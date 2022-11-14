const Table3 = ({ val }) => {
  return (
    <div>
      <table>
        <tbody>
          <tr>
            <td>{val.sno}</td>
            <td>{val.cname}</td>
            <td>{val.grade}</td>
          </tr>
        </tbody>
      </table>
    </div>
  )
}

export default Table3