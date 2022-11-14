const TableA = ({ val }) => {
  return (
    <table>
      <tbody>
        <tr>
          <td>{val.sno}</td>
          <td>{val.sname}</td>
          <td>{val.grade}</td>
        </tr>
      </tbody>
    </table>
  )
}

export default TableA