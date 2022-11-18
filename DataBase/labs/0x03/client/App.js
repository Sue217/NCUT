import Axios from "axios";
import { StatusBar } from "expo-status-bar";
import React, { useState, useEffect } from "react";
import {
  Button,
  StyleSheet,
  Text,
  View,
  SafeAreaView,
  ScrollView,
  TextInput,
} from "react-native";

import Table1 from "./component/Table1";
import Table2 from "./component/Table2";
import Table3 from "./component/Table3";
import Table4 from "./component/Table4";
import Table5 from "./component/Table5";
import Table6 from "./component/Table6";
import Table7 from "./component/Table7";
import Table8 from "./component/Table8";
import Table9 from "./component/Table9";
import TableA from "./component/TableA";
import TableB from "./component/TableB";

const insert_btn = () => {
  Axios.post("http://localhost:3001/api/insert")
    .then((data) => {
      console.log(data);
      alert("Insert Sucessfully!");
    })
    .catch((err) => console.log(err));
};

try {
  Axios.get("http://localhost:3001/api/get/task0").then(() => {
    alert("Loaded and Created");
  });
} catch (e) {
  console.log("404 Not Found");
}

export default function App() {
  const [button, setButton] = useState(0);
  const [resList, setResList] = useState([]);

  const [min, setMin] = useState("");
  const [max, setMax] = useState("");

  const submitValue = () => {
    alert("Bound Checked!");
    Axios.post("http://localhost:3001/api/fetch/values", {
      min: min,
      max: max,
    });
  };

  const path = "http://localhost:3001/api/get/task";

  useEffect(() => {
    if (button !== 11) {
      Axios.get(path + button.toString()).then((response) => {
        setResList(response.data);
      });
    } else {
      Axios.get("http://localhost:3001/api/fetch/result").then((response) => {
        setResList(response.data[0]);
      });
    }
  }, [resList]);

  return (
    <SafeAreaView style={styles.container}>
      <Text>{"\n\n\n"}</Text>
      <Text style={styles.h1}>SQL APPLICATION</Text>
      <Text>{"\n"}</Text>
      <Text style={styles.h2}>--- Jingbo Su ---</Text>
      <Text>{"\n\n"}</Text>

      <StatusBar style="auto" />

      <View style={styles.fixToText}>
        <Button title="Insert" onPress={insert_btn} />
        <Button
          title="Task 1"
          color="#f194ff"
          onPress={() => {
            setButton(1);
          }}
        />
        <Button
          title="Task 2"
          color="#f194ff"
          onPress={() => {
            setButton(2);
          }}
        />
        <Button
          title="Task 3"
          color="#f194ff"
          onPress={() => {
            setButton(3);
          }}
        />
      </View>
      <View style={styles.fixToText}>
        <Button
          title="Task 4"
          color="#f194ff"
          onPress={() => {
            setButton(4);
          }}
        />
        <Button
          title="Task 5"
          color="#f194ff"
          onPress={() => {
            setButton(5);
          }}
        />
        <Button
          title="Task 6"
          color="#f194ff"
          onPress={() => {
            setButton(6);
          }}
        />
        <Button
          title="Task 7"
          color="#f194ff"
          onPress={() => {
            setButton(7);
          }}
        />
      </View>
      <View style={styles.fixToText}>
        <Button
          title="Task 8"
          color="#f194ff"
          onPress={() => {
            setButton(8);
          }}
        />
        <Button
          title="Task 9"
          color="#f194ff"
          onPress={() => {
            setButton(9);
          }}
        />
        <Button
          title="Task A"
          color="#f194ff"
          onPress={() => {
            setButton(10);
          }}
        />
        <Button
          title="Task B"
          color="#f194ff"
          onPress={() => {
            setButton(11);
          }}
        />
      </View>
      <SafeAreaView>
        <TextInput
          style={styles.input}
          onChangeText={setMin}
          placeholder="Lower Bound (ONLY for task 11)"
          value={min}
          keyboardType="numeric"
        />
        <TextInput
          style={styles.input}
          onChangeText={setMax}
          placeholder="Upper Bound (ONLY for task 11)"
          value={max}
          keyboardType="numeric"
        />
        <Button title="Submit" onPress={submitValue} />
      </SafeAreaView>
      <ScrollView>
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
              return <Text style={styles.h1}>Where???</Text>;
          }
        })}
      </ScrollView>
    </SafeAreaView>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: "#fff",
    alignItems: "center",
    justifyContent: "center",
  },
  fixToText: {
    flexDirection: "row",
    justifyContent: "stretch",
  },
  h1: {
    fontFamily: "Cochin",
    fontSize: 36,
    fontWeight: "bold",
    justifyContent: "center",
    alignItems: "center",
  },
  h2: {
    fontSize: 25,
    justifyContent: "center",
    alignItems: "center",
  },
  input: {
    height: 40,
    margin: 12,
    borderWidth: 1,
    padding: 10,
  },
});
