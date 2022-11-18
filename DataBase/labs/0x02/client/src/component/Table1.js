const Table1 = ({ val }) => {
  return (
    <table>
      <tbody>
        <tr>
          <td>{val.sno}</td>
          <td>{val.sname}</td>
          <td>{val.birth}</td>
        </tr>
      </tbody>
    </table>
  )
}

export default Table1