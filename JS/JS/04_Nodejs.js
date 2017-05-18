const express = require('express')
const bodyParser = require('body-parser')
const fs = require('fs')

const app = express()
var port = 57017

app.use(express.static('04_public'))
var urlencodedParser = bodyParser.urlencoded({
  extended: true
})

var items = [{
  name: 'Dyel',
  sex: 'male'
}, {
  name: 'Ruhama',
  sex: 'female'
}]

app.route('/')
  .get(urlencodedParser, function (req, res) {
    res.send('Get\n\n' + req.params + '\n\n' + req.query)
  })
  .post(urlencodedParser, function (req, res) {
    res.send('Post\n\n' + req.params + '\n\n' + req.query)
  })
  .put(urlencodedParser, function (req, res) {
    res.send('Put\n\n' + req.params + '\n\n' + req.query)
  })
app.route('/user', urlencodedParser)
  .get(function (req, res) {
    res.send(items)
  })
  .post(function (req, res) {
    var nameData = req.query.name
    var sexData = req.query.sex
    var item = {
      name: nameData,
      sex: sexData
    }
    if ((nameData === undefined) || (sexData === undefined)) {
      res.send({
        error: 'Please Input Name and Sex Data'
      })
    } else {
      items.push(item)
      res.send({
        message: 'Successful Upload Data',
        data: item
      })
    }
    console.log(items)
  })
app.route('/user/:id')
  .get(function (req, res) {
    var id = Number(req.params.id)

    if (isNaN(id)) {
      res.send({
        error: 'Just Number!'
      })
    } else if (items[id]) {
      res.send(items[id])
    } else {
      res.send({
        error: 'Not Exist'
      })
    }
  })

  .put(function (req, res) {
    var id = Number(req.params.id)
    var nameData = req.params.name
    var sexData = req.params.sex

    if (items[id]) {
      if (nameData) {
        items[id].name = nameData
      }
      if (sexData) {
        items[id].data = sexData
      }
      res.send({
        message: 'Successful Update Data'
      })
    } else {
      res.send({
        message: 'not Exist Data'
      })
    }
  })
  .delete(function (req, res) {
    var id = Number(req.params.id)
    if (isNaN(id)) {
      res.send({
        error: 'Just Insert Numeric ID'
      })
    } else if (items[id]) {
      items.splice(id, 1)
      res.send({
        message: 'Successful Delete Data'
      })
    } else {
      res.send({
        error: 'Not Exist ID'
      })
    }
  })


app.listen(port, function () {
  console.log('Server Running on port ' + port)
})