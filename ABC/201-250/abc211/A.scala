import scala.io.StdIn._

object Main extends App {
  val Array(a, b) = readLine().split(" ").map(_.toDouble)
  println((a - b) / 3 + b)
}
