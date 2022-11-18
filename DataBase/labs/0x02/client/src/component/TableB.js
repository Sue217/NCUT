const TableB = ({ val }) => {
  return (
    <table>
      <tbody>
        <tr>
          <td>{val.sname}</td>
          <td>{val.sdept}</td>
          <td>{val.grade}</td>
        </tr>
      </tbody>
    </table>
  )
}

export default TableB