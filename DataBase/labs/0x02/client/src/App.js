import React, { useState, useEffect } from 'react';
import Axios from 'axios';
import './App.css';
import Table1 from './component/Table1';
import Table2 from './component/Table2';
import Table3 from './component/Table3';
import Table4 from './component/Table4';
import Table5 from './component/Table5';
import Table6 from './component/Table6';
import Table7 from './component/Table7';
import Table8 from './component/Table8';
import Table9 from './component/Table9';
import TableA from './component/TableA';
import TableB from './component/TableB';

const insert_btn = () => {
  Axios.post("http://localhost:3001/api/insert").then(() => {
    alert("Insert Sucessfully!");
  });
}

try {
  Axios.get("http://localhost:3001/api/get/task0").then(() => {
    alert("Loaded and Created");
  });
} catch (e) {
  console.log('404 Not Found');
}

function App() {
  const [button, setButton] = useState(0)
  const [resList, setResList] = useState([])

  const [min, setMin] = useState('');
  const [max, setMax] = useState('');

  const submitValue = () => {
    alert("Bound Checked!");
    Axios.post("http://localhost:3001/api/fetch/values", {
      min: min,
      max: max,
    })
  };

  const path = "http://localhost:3001/api/get/task";

  useEffect(() => {
    if (button !== 11) {
      Axios.get(path + button.toString())
        .then((response) => {
          setResList(response.data);
        });
    } else {
      Axios.get("http://localhost:3001/api/fetch/result")
        .then((response) => {
          setResList(response.data[0]);
        });
    }
  }, [resList, button]);

  return (
    <div className="App">
      <h1>SQL APPLICATION</h1>
      <h4>---  Jingbo Su from NCUT  ---</h4>
      
      <div>
        <button className='func_btn' onClick={insert_btn}>Insert</button>
        <button className='opt_btn' onClick={() => { setButton(1) }}>Task 1</button>
        <button className='opt_btn' onClick={() => { setButton(2) }}>Task 2</button>
        <button className='opt_btn' onClick={() => { setButton(3) }}>Task 3</button>
        <button className='opt_btn' onClick={() => { setButton(4) }}>Task 4</button>
        <button className='opt_btn' onClick={() => { setButton(5) }}>Task 5</button>
        <button className='opt_btn' onClick={() => { setButton(6) }}>Task 6</button>
        <button className='opt_btn' onClick={() => { setButton(7) }}>Task 7</button>
        <button className='opt_btn' onClick={() => { setButton(8) }}>Task 8</button>
        <button className='opt_btn' onClick={() => { setButton(9) }}>Task 9</button>
        <button className='opt_btn' onClick={() => { setButton(10) }}>Task A</button>
        <button className='opt_btn' onClick={() => { setButton(11) }}>Task B</button>

        <div className='form'>
          <label>Lower Bound (ONLY for task 11)</label>
          <input type="textbox" name="min" onChange={(e) => { setMin(e.target.value) }}></input>
          <label>Higher Bound (ONLY for task 11)</label>
          <input type="textbox" name="max" onChange={(e) => { setMax(e.target.value) }}></input>
          <button onClick={submitValue}>Submit</button>
        </div>

        {resList.map((val) => {
          switch (button) {
            // case 0:
            //   return <h1>Hi, there!</h1>;
            case 1:
              return <Table1 key={val.sname} val={val} />;
            case 2:
              return <Table2 key={val.sdept} val={val} />;
            case 3:
              return <Table3 key={[val.cname][val.sno]} val={val} />;
            case 4:
              return <Table4 key={val.tname} val={val} />;
            case 5:
              return <Table5 key={val.sname} val={val} />;
            case 6:
              return <Table6 key={[val.cno][val.sname]} val={val} />;
            case 7:
              return <Table7 key={val.tname} val={val} />;
            case 8:
              return <Table8 key={[val.sname][val.ssex]} val={val} />;
            case 9:
              return <Table9 key={[val.sd][val.sno]} val={val} />;
            case 10:
              return <TableA key={[val.sno][val.sname]} val={val} />;
            case 11:
              return <TableB key={[val.sname][val.sdept]} val={val} />;
            default:
              return <h1>Where?</h1>
          }
        })}
      </div>
    </div>
  );
}

export default App;
