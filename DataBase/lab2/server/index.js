import express from 'express';
const app = express();
app.use(express.json());  // grab the information as a json from the front-end

import mysql from 'mysql';
const db = mysql.createPool({
  host: '127.0.0.1',
  port: '3306',
  user: 'root',
  database: 'NCUT'
});

import bodyParser from 'body-parser';
app.use(bodyParser.urlencoded({extended: true}));

// provides a Connect/Express middleware that can be used to enable CORS with various options.
import cors from 'cors';
app.use(cors());

import insert_items from './sql/insert.js';

app.post('/api/insert', (req, res) => {
  // test
  // var insert = fs.readFileSync("../../lab1/code/insert.sql").toString();
  const sqlInsert = insert_items();
  // console.log(sqlInsert);
  
  for (let i = 0; i < sqlInsert.length; i++) {
    db.query(sqlInsert[i], (err, result) => {
      res.send(err);
    });
  }
  // display
  // res.send("Hello World!");
});

import { tasks } from './sql/tasks.js';

app.get('/api/get/task1', (req, res) => {
  const sqlSelect = tasks(1);
  db.query(sqlSelect, (err, result) => {
    res.send(result);
  });
});

app.listen(3001, () => {
  console.log("running on port 3001...")
});