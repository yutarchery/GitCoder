import scala.io.StdIn._

object Main extends App {
  val Seq(h, w, a, b) = readLine().split(" ").map(_.toInt).toSeq

  println((0 until h).map(solve(_)).mkString("\n"))

  def solve(line: Int): String = {
    {
      if (line < b) {
        (0 until a).map(_ => '1') ++ (a until w).map(_ => '0')
      } else {
        (0 until a).map(_ => '0') ++ (a until w).map(_ => '1')
      }
    }.mkString
  }
}
