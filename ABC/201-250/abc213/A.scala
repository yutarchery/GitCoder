import scala.io.StdIn._

object Main extends App {
  val Seq(a, b) = readLine().split(' ').map(_.toInt).toSeq
  println(solve(a, b, 0))

  def solve(a: Int, b: Int, c: Int): Int = {
    if ((a ^ c) == b) {
      c
    } else {
      solve(a, b, c + 1)
    }
  }
}
