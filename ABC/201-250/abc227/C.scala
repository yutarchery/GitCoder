import scala.io.StdIn._

object Main extends App {
  val n = readLong()

  val ans = (1L to mySqrt3(n)).foldLeft(0L) { (acc, a) =>
    (a to mySqrt(n / a)).foldLeft(acc) { (acc2, b) =>
      acc2 + solve(a, b)
    }
  }

  println(ans)

  def solve(a: Long, b: Long): Long = {
    n / (a * b) - b + 1
  }

  private def mySqrt(a: Long): Long = binary2(1, 1e6.toLong, a)

  private def binary2(min: Long, max: Long, sum: Long): Long = {
    if (max - min == 1) {
      return min
    }

    val mid = (min + max) / 2
    if (mid * mid <= sum) {
      binary2(mid, max, sum)
    } else {
      binary2(min, mid, sum)
    }
  }

  private def mySqrt3(a: Long): Long = binary3(1, 1e4.toLong, a)

  private def binary3(min: Long, max: Long, sum: Long): Long = {
    if (max - min == 1) {
      return min
    }
    val mid = (min + max) / 2
    if (mid * mid * mid <= sum) {
      binary3(mid, max, sum)
    } else {
      binary3(min, mid, sum)
    }
  }
}
