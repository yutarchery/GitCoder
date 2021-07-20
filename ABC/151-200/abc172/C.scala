import scala.io.StdIn._

object Main extends App {
  val Array(n, m, k) = readLine().split(" ").map(_.toInt)
  val a = readLine().split(" ").map(_.toLong)
  val b = readLine().split(" ").map(_.toLong)

  val sumA = a.scanLeft(0.toLong)(_ + _)
  val sumB = b.scanLeft(0.toLong)(_ + _)

  val ans = (0 until sumA.size).foldLeft(0) { (acc, i) =>
    math.max(acc, solve(i))
  }
  println(ans)

  def solve(index: Int): Int = {
    if (sumA(index) > k) {
      0
    } else {
      index + searchSumB(0, sumB.size, k - sumA(index))
    }
  }

  def searchSumB(l: Int, r: Int, rest: Long): Int = {
    if (r - l == 1) {
      l
    } else {
      val mid = (l + r) / 2
      if (sumB(mid) > rest) {
        searchSumB(l, mid, rest)
      } else {
        searchSumB(mid, r, rest)
      }
    }
  }
}
