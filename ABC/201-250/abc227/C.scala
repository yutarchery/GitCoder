import scala.io.StdIn._

object Main extends App {
  val n = readLong()

  val ans = (1L to math.pow(n, (1.0 / 3.0)).toLong).foldLeft(0L) { (acc, a) =>
    (a to math.sqrt(n / a).toLong).foldLeft(acc) { (acc2, b) =>
      acc2 + solve(a, b)
    }
  }

  println(ans)

  def solve(a: Long, b: Long): Long = {
    n / (a * b) - b + 1
  }
}
