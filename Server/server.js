const { createServer } = require('node:http');

const hostname = '127.0.0.1';
const port = 3000;

const express = require('express')
const app = express()

const cors = require('cors');

var state = 0;

app.use(cors());

app.get('/', (req, res) => {
  res.setHeader("Content-Type", "application/json")
  res.send({'state': state})
})

app.post('/change_state', (req, res) => {
    if (state == 0) {
        state = 1
    } else {
        state = 0
    }
    console.log(state)
    res.send("you did great")
})


app.listen(port, hostname, () => {
  console.log(`Server running at http://${hostname}:${port}/`);
});