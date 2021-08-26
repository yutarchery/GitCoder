import scala.io.StdIn._

object Main extends App {
  final val mod = (1e9 + 7).toLong

  val n = readInt()
  println(solve(n))

  def solve(n: Int): Long = {
    val sum =
      (myPow(10, n, mod) - 2 * myPow(9, n, mod) + myPow(8, n, mod)) % mod

    if (sum < 0) {
      sum + mod
    } else {
      sum
    }

  }

  def myPow(a: Long, n: Long, mod: Long): Long = {
    if (n == 0) {
      1L
    } else if (n % 2 == 0) {
      myPow(a * a % mod, n / 2, mod)
    } else {
      a * myPow(a, n - 1, mod) % mod
    }
  }
}
