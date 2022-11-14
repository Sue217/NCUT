const Table5 = ({ val }) => {
  //! array map didn't happen
  if (val.length === 0) {
    return (
      <h1>Null</h1>
    );
  }
  return (
    <div>
      <table>
        <tbody>
          <tr>
            <td>{val.sname}</td>
            <td>{val.sdept}</td>
          </tr>
        </tbody>
      </table>
    </div>
  )
}

export default Table5