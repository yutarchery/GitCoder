import scala.io.StdIn._

object Main extends App {
  val n = readInt()
  val s = readLine().split(" ").map(_.toLong)
  val t = readLine().split(" ").map(_.toLong)

  val ans = new Array[Long](n)

  ans(0) = math.min(s(0), t(0))
  (1 until n).foreach { i =>
    ans(i) = math.min(ans(i - 1) + s(i - 1), t(i))
  }

  println(ans.mkString("\n"))
}
