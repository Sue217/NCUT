import { StyleSheet } from "react-native";
import { DataTable } from "react-native-paper";

const Table8 = ({ val }) => {
  return (
    <DataTable style={styles.container}>
      <DataTable.Row style={styles.table}>
        <DataTable.Cell>{val.sno}</DataTable.Cell>
        <DataTable.Cell>{val.sname}</DataTable.Cell>
        <DataTable.Cell>{val.ssex}</DataTable.Cell>
        <DataTable.Cell>{val.sage}</DataTable.Cell>
        <DataTable.Cell>{val.sdept}</DataTable.Cell>
      </DataTable.Row>
    </DataTable>
  );
};

const styles = StyleSheet.create({
  container: {
    backgroundColor: "#f1f8ff",
    width: 400,
  },
  table: {
    textAlign: "center",
    fontWeight: "bold",
    fontSize: 16,
  },
});

export default Table8;
