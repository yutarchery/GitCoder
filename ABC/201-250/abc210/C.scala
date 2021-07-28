import scala.io.StdIn._
import scala.collection.mutable

object Main extends App {
  val Array(n, k) = readLine().split(" ").map(_.toInt)
  val c = readLine().split(" ").map(_.toInt)

  val cnt = mutable.Map.empty[Int, Int]

  val ans0 = (0 until k).foldLeft(0) { (acc, i) =>
    if (cnt.contains(c(i))) {
      cnt(c(i)) += 1
      acc
    } else {
      cnt += (c(i) -> 1)
      acc + 1
    }
  }

  println(solve(k, ans0, ans0))

  def solve(index: Int, value: Int, max: Int): Int = {
    if (index == n) {
      max
    } else {
      cnt(c(index - k)) -= 1
      if (cnt.contains(c(index))) {
        cnt(c(index)) += 1
      } else {
        cnt += (c(index) -> 1)
      }

      val nowValue = if (cnt(c(index - k)) == 0 && cnt(c(index)) == 1) {
        value
      } else if (cnt(c(index - k)) == 0) {
        value - 1
      } else if (cnt(c(index)) == 1) {
        value + 1
      } else {
        value
      }
      solve(index + 1, nowValue, math.max(max, nowValue))
    }
  }
}
