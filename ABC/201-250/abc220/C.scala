import scala.io.StdIn._

object Main extends App {
  val n = readLong()
  val a = readLine().split(' ').map(_.toLong)
  val x = readLong()

  val sum = a.sum
  println(solve(x, 0, 0))

  def solve(rest: Long, ans: Long, index: Int): Long = {
    if (rest < 0) {
      ans
    } else if (rest >= sum) {
      solve(rest % sum, ans + n * (rest / sum), index)
    } else {
      solve(rest - a(index), ans + 1, index + 1)
    }
  }

}
