import scala.io.StdIn._

object Main extends App {
  val n = readLong()
  println(solve(0, 61))

  def solve(l: Int, r: Int): Int = {
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

  def check(k: Int): Boolean = {
    val num: Long = 1L << k
    num <= n
  }
}
