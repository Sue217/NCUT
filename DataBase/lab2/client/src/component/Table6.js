const Table6 = ({ val }) => {
  return (
    <div>
      <table>
        <tbody>
          <tr>
            <td>{val.sname}</td>
            <td>{val.cno}</td>
            <td>{val.grade}</td>
          </tr>
        </tbody>
      </table>
    </div>
  )
}

export default Table6