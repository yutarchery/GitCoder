import scala.io.StdIn._

object Main extends App {
  val n = readInt()
  val a =
    readLine()
      .split(" ")
      .toSeq
      .map(_.toInt)
      .zipWithIndex
      .sorted
      .reverse
      .map(i => i._2 + 1)
  println(a(1))
}
