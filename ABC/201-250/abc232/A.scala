import scala.io.StdIn._

object Main extends App {
  val s = readLine()
  println((s(0) - '0').toInt * (s(2) - '0').toInt)
}
