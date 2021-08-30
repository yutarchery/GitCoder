import scala.io.StdIn._

object Main extends App {
  val Array(a, b) = readLine().split(" ").map(_.toInt)

  if (a <= 8 && b <= 8) {
    println("Yay!")
  } else {
    println(":(")
  }
}
