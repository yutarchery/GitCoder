import scala.io.StdIn._

object Main extends App {
  val Array(x, y) = readLine().split('.').map(_.toInt)

  print(x)
  if (y <= 2) {
    println("-")
  } else if (y <= 6) {
    println()
  } else {
    println("+")
  }
}