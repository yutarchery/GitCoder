import scala.io.StdIn._

object Main extends App {
  val n = readLong()

  val ans = (1 to 16).foldLeft(0L) { (acc, i) =>
    (i to 16).foldLeft(acc) { (acc2, j) =>
      if (make11(i, 0) > n) {
        acc2
      } else {
        acc2 + count(i, j)
      }
    }
  }

  println(ans)

  def make11(rest: Int, now: Long): Long = {
    if (rest == 0) {
      now
    } else {
      make11(rest - 1, now * 10 + 1)
    }
  }

  def count(i: Int, j: Int): Long = {
    if (i > j) {
      0
    } else {
      val min = make11(i, 0) * math.pow(10, j - i).toLong
      val max = (make11(i, 0) + 1) * math.pow(10, j - i).toLong - 1

      if (n < min) {
        0
      } else if (n < max) {
        n - min + 1
      } else {
        max - min + 1
      }
    }
  }
}
