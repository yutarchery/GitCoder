import scala.io.StdIn._

object Main extends App {
  val n = readInt()
  if (n <= 125) {
    println("4")
  } else if (n <= 211) {
    println("6")
  } else {
    println("8")
  }
}

