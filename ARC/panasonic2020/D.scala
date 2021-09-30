import scala.io.StdIn._

object Main extends App {
  val n = readInt()
  solve(1, Seq(0))

  def solve(turn: Int, array: Seq[Int]): Unit = {
    if (array.size == n) {
      val ans: Seq[Char] = array.map(i => ('a' + i).toChar)
      println(ans.mkString)
    } else {
      val max = array.max
      (0 to max + 1).foreach { i => solve(turn + 1, array :+ i) }
    }
  }
}
