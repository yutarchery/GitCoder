import scala.io.StdIn._

object Main extends App {
  val n = readInt()
  val aSeq = 0 +: readLine().split(" ").map(_.toInt) :+ 0

  val leftGcd = Array.fill(n + 2)(0)
  (1 to n).map(i => leftGcd(i) = calcGcd(leftGcd(i - 1), aSeq(i)))

  val rightGcd = Array.fill(n + 2)(0)
  (1 to n).reverse.map(i => rightGcd(i) = calcGcd(rightGcd(i + 1), aSeq(i)))

  val ans = (1 to n).foldLeft(0) { (res, i) =>
    math.max(calcGcd(leftGcd(i - 1), rightGcd(i + 1)), res)
  }

  println(ans)

  def calcGcd(a: Int, b: Int): Int = {
    if (a < b) {
      calcGcd(b, a)
    } else if (b == 0) {
      a
    } else if (a % b == 0) {
      b
    } else {
      calcGcd(b, a % b)
    }
  }
}
