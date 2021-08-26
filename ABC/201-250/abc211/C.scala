import scala.io.StdIn._

object Main extends App {
  final val mod = (1e9 + 7).toInt

  val s = readLine()
  val t = "chokudai"

  val dp = Array.ofDim[Long]((1e5 + 5).toInt, 9)

  dp(0)(0) = 1
  (1 to s.length()).foreach { i => update(i) }

  println(dp(s.length())(t.length()))

  def update(sIndex: Int) = {
    (0 to t.length()).foreach { j =>
      dp(sIndex)(j) += dp(sIndex - 1)(j)
    }

    (1 to t.length()).foreach { j =>
      if (s(sIndex - 1) == t(j - 1)) {
        dp(sIndex)(j) += dp(sIndex - 1)(j - 1)
        dp(sIndex)(j) %= mod
      }
    }
  }
}
