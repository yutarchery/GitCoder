import scala.io.StdIn._

object Main extends App {
  val n = readInt()
  val a = readLine().split(' ').map(_.toInt)

  val dp = Array.fill(n)(Int.MaxValue)
  dp(0) = 0

  (0 until (n - 1)).foreach { i =>
    dp(i + 1) = math.min(dp(i + 1), dp(i) + math.abs(a(i) - a(i + 1)))
    if (i + 2 < n) {
      dp(i + 2) = math.min(dp(i + 2), dp(i) + math.abs(a(i) - a(i + 2)))
    }
  }

  println(dp(n - 1))
}
