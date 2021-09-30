import scala.io.StdIn._

object Main extends App {
  val n = readInt()
  solve("a")

  def solve(now: String): Unit = {
    if (now.length() == n) {
      println(now)
    } else {
      val max = now.max + 1
      ('a' to max.toChar).foreach { i => solve(now :+ i) }
    }
  }
}
