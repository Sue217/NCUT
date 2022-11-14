const Table9 = ({ val }) => {
  return (
    <div>
      <table>
        <tbody>
          <tr>
            <td>{val.sno}</td>
            <td>{val.sname}</td>
            <td>{val.sd}</td>
            <td>{val.sa}</td>
          </tr>
        </tbody>
      </table>
    </div>
  )
}

export default Table9