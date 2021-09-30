import scala.io.StdIn._

object Main extends App {
  val mod = (1e9 + 7).toLong
  val Array(n, p) = readLine().split(' ').map(_.toLong)

  println((p - 1) * pow(p - 2, n - 1) % mod)

  def pow(a: Long, n: Long): Long = {
    if (n == 0) {
      1
    } else if (n % 2 == 0) {
      pow(a * a % mod, n / 2)
    } else {
      pow(a * a % mod, n / 2) * a % mod
    }
  }
}
