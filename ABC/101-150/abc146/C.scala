import scala.io.StdIn._

object Main extends App {
  val Array(a, b, x) = readLine().split(" ").map(_.toLong)
  println(solve(0, 1e9.toLong + 1))

  def solve(l: Long, r: Long): Long = {
    if (r - l == 1) {
      l
    } else {
      val mid = (l + r) / 2
      if (check(mid)) {
        solve(mid, r)
      } else {
        solve(l, mid)
      }
    }
  }

  def digitCount(num: Long): Long = {
    if (num == 0) {
      0
    } else {
      digitCount(num / 10) + 1
    }
  }

  def check(num: Long): Boolean = {
    a * num + b * digitCount(num) <= x
  }
}
