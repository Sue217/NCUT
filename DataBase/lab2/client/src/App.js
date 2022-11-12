import React, {useState, useEffect} from 'react';
import Axios from 'axios';
import './App.css';

const insert_btn = () => {
  Axios.post("http://localhost:3001/api/insert").then(() => {
    alert("Insert Sucessfully!");
  });
}

function App() {
  const [resList, setResList] = useState([])

  var path = "http://localhost:3001/api/get/task1";

  const task_btn_1 = () => {
    path = "http://localhost:3001/api/get/task1";
  }

  useEffect(() => {
    Axios.get(path)
      .then((response) => {
        setResList(response.data);
      });
  }, [resList, path]);

  return (
    <div className="App">
      <h1>SQL APPLICATION</h1>
      {/* <div className='form'>
        <label>Response</label>
        <input type="textbox" name="display"></input>
      </div> */}
      <div>
        <button className='func_btn' onClick={insert_btn}>Insert</button>
        <button className='opt_btn' onClick={task_btn_1}>Task 1</button>

        {resList.map((val, id) => {
          return <h3 key={id}>{val.sno} | {val.sname} | {val.birth}</h3>;
        })}
      </div>
    </div>
  );
}

export default App;
