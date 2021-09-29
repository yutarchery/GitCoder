import scala.io.StdIn._

object Main extends App {
  val Array(n, m) = readLine().split(' ').map(_.toInt)
  val s = readLine().split(' ').map(_.toInt)
  val t = readLine().split(' ').map(_.toInt)

  val used = Seq(0, 1).map(i => s.contains(i))

  val dist = (0 until n).foldLeft(Int.MaxValue) { (acc, i) =>
    if (s(i) == s(0)) {
      acc
    } else {
      Seq(acc, i, n - i).min
    }
  }

  println(solve(0, 0, s(0), false))

  def solve(index: Int, sum: Int, now: Int, flag: Boolean): Int = {
    if (index == m) {
      sum
    } else if (!used(t(index))) {
      -1
    } else {
      if (now == t(index)) {
        solve(index + 1, sum + 1, t(index), flag)
      } else {
        if (!flag) {
          solve(index + 1, sum + dist + 1, t(index), true)
        } else {
          solve(index + 1, sum + 2, t(index), flag)
        }
      }
    }
  }

}
