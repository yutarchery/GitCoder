import scala.io.StdIn._

object Main extends App {
  val Array(n, k) = readLine().split(" ").map(_.toInt)
  val V = readLine().split(" ").map(_.toInt).toSeq

  val ans = (0 to math.min(n, k)).foldLeft(0) { (res, left) =>
    (0 to math.min(n, k) - left).foldLeft(res) { (res, right) =>
      math.max(res, solve(left, right))

    }
  }
  println(ans)

  def solve(left: Int, right: Int): Int = {
    if (left + right > k) {
      0
    } else {
      val v = V.slice(0, left) ++ V.slice(n - right, n)
      val minusSeq = v.filter(_ < 0).sortBy(i => i)

      val rest = math.min(k - (left + right), minusSeq.size)
      v.sum - minusSeq.slice(0, rest).sum
    }
  }
}
