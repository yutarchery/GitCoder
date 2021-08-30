import scala.io.StdIn._

object Main extends App {
  val Array(n, x0) = readLine().split(" ").map(_.toLong)
  val x = {
    readLine().split(" ").map(_.toLong) ++ Array(x0)
  }.distinct.sorted

  val ans = (0 until x.length - 1).foldLeft(0L) { (acc, i) =>
    gcd(acc, x(i + 1) - x(i))
  }

  println(ans)

  def gcd(a: Long, b: Long): Long = {
    if (a < b) {
      gcd(b, a)
    } else if (b == 0) {
      a
    } else if (a % b == 0) {
      b
    } else {
      gcd(b, a % b)
    }
  }

}
