import scala.io.StdIn._

object Main extends App {
  val n = readInt()
  val A = readLine().split(" ").map(_.toInt)

  val leftGcd = Array.fill(n)(0)
  leftGcd(0) = A(0)
  (1 until n).map { i =>
    leftGcd(i) = calcGcd(leftGcd(i - 1), A(i))
  }

  val rightGcd = Array.fill(n)(0)
  rightGcd(n - 1) = A(n - 1)
  (0 until (n - 1)).reverse.map { i =>
    rightGcd(i) = calcGcd(rightGcd(i + 1), A(i))
  }

  val ans = (1 until (n - 1)).foldLeft(math.max(leftGcd(1), rightGcd(n - 2))) {
    (res, i) =>
      math.max(res, calcGcd(leftGcd(i - 1), rightGcd(i + 1)))
  }
  println(ans)

  def calcGcd(a: Int, b: Int): Int = {
    if (a < b) {
      calcGcd(b, a)
    } else if (a % b == 0) {
      b
    } else {
      calcGcd(b, a % b)
    }
  }
}
