import express from "express";
const app = express();
app.use(express.json()); // grab the information as a json from the front-end

import mysql from "mysql";
const db = mysql.createPool({
  host: "127.0.0.1",
  port: "3306",
  user: "root",
  database: "NCUT",
});

import bodyParser from "body-parser";
app.use(bodyParser.urlencoded({ extended: true }));

// provides a Connect/Express middleware that can be used to enable CORS with various options.
import cors from "cors";
app.use(cors());

import insert_items from "./sql/insert.js";

app.post("/api/insert", (req, res) => {
  // test
  // var insert = fs.readFileSync("../../lab1/code/insert.sql").toString();
  const sqlInsert = insert_items();
  // console.log(sqlInsert);

  let resList = [];
  for (let i = 0; i < sqlInsert.length; i++) {
    db.query(sqlInsert[i], (err, result) => {
      resList.push(result);
    });
  }
  res.send(resList);
  // display
  // res.send("Hello World!");
});

import { tasks } from "./sql/tasks.js";

try {
  app.get("/api/get/task0", (req, res) => {
    let sqlList = tasks(0).split(";");
    let resList = [];
    for (let i = 0; i < sqlList.length; i++) {
      db.query(sqlList[i].trim() + ";", (err, result) => {
        try {
          resList.push(result);
        } catch (e) {
          console.log("[DEBUG]: query error on stmt `" + sqlList[i] + "`");
          console.log("[DEBUG]: error = [" + err + "]");
          console.log("[DEBUG]: panic = [" + e + "]");
          process.exit(-1);
        }
      });
    }
    res.send(resList);
  });
} catch (e) {
  console.log("[Get] 404 Not Found!");
}

app.get("/api/get/task1", (req, res) => {
  const sqlSelect = tasks(1);
  db.query(sqlSelect, (err, result) => {
    res.send(result);
  });
});

app.get("/api/get/task2", (req, res) => {
  const sqlSelect = tasks(2);
  db.query(sqlSelect, (err, result) => {
    res.send(result);
  });
});

app.get("/api/get/task3", (req, res) => {
  const sqlSelect = tasks(3);
  db.query(sqlSelect, (err, result) => {
    res.send(result);
  });
});

app.get("/api/get/task4", (req, res) => {
  const sqlSelect = tasks(4);
  db.query(sqlSelect, (err, result) => {
    res.send(result);
  });
});

app.get("/api/get/task5", (req, res) => {
  const sqlSelect = tasks(5);
  db.query(sqlSelect, (err, result) => {
    res.send(result);
  });
});

app.get("/api/get/task6", (req, res) => {
  const sqlSelect = tasks(6);
  db.query(sqlSelect, (err, result) => {
    res.send(result);
  });
});

app.get("/api/get/task7", (req, res) => {
  const sqlSelect = tasks(7);
  db.query(sqlSelect, (err, result) => {
    res.send(result);
  });
});

app.get("/api/get/task8", (req, res) => {
  const sqlSelect = tasks(8);
  db.query(sqlSelect, (err, result) => {
    res.send(result);
  });
});

app.get("/api/get/task9", (req, res) => {
  const sqlSelect = tasks(9);
  db.query(sqlSelect, (err, result) => {
    res.send(result);
  });
});

app.get("/api/get/task10", (req, res) => {
  const sqlSelect = tasks(10);
  db.query(sqlSelect, (err, result) => {
    res.send(result);
  });
});

var lower = 0;
var higher = 0;

app.post("/api/fetch/values", (req, res) => {
  lower = parseInt(req.body.min);
  higher = parseInt(req.body.max);
  // console.log(lower, higher);
});

app.get("/api/fetch/result", (req, res) => {
  // console.log(lower, higher, typeof lower, typeof higher);
  const sqlCall = "CALL __PROCEDURE_TASK__(?,?)";
  db.query(sqlCall, [lower, higher], (err, result) => {
    res.send(result);
  });
});

app.listen(3001, () => {
  console.log("running on port 3001...");
});
