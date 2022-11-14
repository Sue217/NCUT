const Table2 = ({ val }) => {
  return (
    <div>
      <table>
        <tbody>
          <tr>
            <td>{val.sdept}</td>
            <td>{val.total}</td>
          </tr>
        </tbody>
      </table>
    </div>
  )
}

export default Table2