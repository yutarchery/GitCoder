import scala.io.StdIn._

object Main extends App {
  val Array(a, b) = readLine().split(" ").map(_.toInt)
  println(List(b - a + 1, 0).max)
}
