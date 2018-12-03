const fs = require('fs')


function loadingJSON(path) {
  return JSON.parse(fs.readFileSync(path, 'utf8'))
}

function writingToFile(path, JSONs) {
  return fs.writeFileSync(path, JSONs, 'utf8')
}

function appendingJSON(path, appendJSON) {
  return fs.appendFileSync(path, appendJSON, 'utf8')
}

function readLastDocumentOfJSON(jsons) {
  return jsons[jsons.length - 1]
}

var jsons = loadingJSON('data.json')
var cur = readLastDocumentOfJSON(jsons)

var append = {
  date: cur.date + 1,
  in: 0,
  out: 0,
  state: 0
}

jsons.push(append)
writingToFile('data.json', JSON.stringify(jsons))