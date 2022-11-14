const Table5 = ({ val }) => {
  //! array map didn't happen
  if (val.length === 0) {
    return (
      <h1>Null</h1>
    );
  }
  return (
    <table>
      <tbody>
        <tr>
          <td>{val.sname}</td>
          <td>{val.sdept}</td>
        </tr>
      </tbody>
    </table>
  )
}

export default Table5