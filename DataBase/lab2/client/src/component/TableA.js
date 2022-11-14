const TableA = ({ val }) => {
  return (
    <div>
      <table>
        <tbody>
          <tr>
            <td>{val.sno}</td>
            <td>{val.sname}</td>
            <td>{val.grade}</td>
          </tr>
        </tbody>
      </table>
    </div>
  )
}

export default TableA