const Table8 = ({ val }) => {
  return (
    <table>
      <tbody>
        <tr>
          <td>{val.sno}</td>
          <td>{val.sname}</td>
          <td>{val.ssex}</td>
          <td>{val.sage}</td>
          <td>{val.sdept}</td>
        </tr>
      </tbody>
    </table>
  )
}

export default Table8