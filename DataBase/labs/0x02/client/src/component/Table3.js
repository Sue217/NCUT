const Table3 = ({ val }) => {
  return (
    <table>
      <tbody>
        <tr>
          <td>{val.sno}</td>
          <td>{val.cname}</td>
          <td>{val.grade}</td>
        </tr>
      </tbody>
    </table>
  )
}

export default Table3