const Table1 = ({ val }) => {
  return (
    <div>
      <table>
        <tbody>
          <tr>
            <td>{val.sno}</td>
            <td>{val.sname}</td>
            <td>{val.birth}</td>
          </tr>
        </tbody>
      </table>
    </div>
  )
}

export default Table1