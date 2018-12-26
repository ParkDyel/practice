const express = require('express');
const fs = require('fs');
const http = require('http')
const path = require('path');
const reload = require('reload');
const logger = require('morgan')

const app = express();
const pathRes = path.join(__dirname, 'src');
const pathHtmlRes = path.join(pathRes, 'html');

const getRootPath = (fileName) => {
  let ret = '';
  ret += path.dirname(require.main.filename);
  ret += '/src/html/';
  ret += fileName;
  return ret;
};

app.use(express.static(pathRes));
app.use(logger('dev'))

fs.readdir(pathHtmlRes, (err, files) => {
  files.forEach((file) => {
    const url = `/${file.split('.')[0]}`;
    app.get(url, (req, res) => {
      console.log(file);
      res.sendFile(getRootPath(`${file}`));
    });
  });
});

app.get('/', (req, res) => {
    res.sendFile(getRootPath('index.html'))
})

const server = http.createServer(app)

let port = 8081;
server
  .listen(port, () => {
    console.log(`[${port}] : ${path.dirname(require.main.filename)}`);
  })
  .on('error', (err) => {
    if (err.code === 'EADDRINUSE') {
      port += 1;
      console.log(`Address in use, retrying on port ${port}`);
      setTimeout(() => {
        app.listen(port);
      }, 250);
    }
  });

reload(app);