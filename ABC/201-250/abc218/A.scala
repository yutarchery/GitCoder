import scala.io.StdIn._

object Main extends App {
  val n = readInt()
  val s = readLine()

  s(n - 1) match {
    case 'o' => println("Yes")
    case _   => println("No")
  }
}
