import scala.io.StdIn._

object Main extends App {
  val Array(n, x) = readLine().split(" ").map(_.toInt)
  val a = readLine().split(" ").map(_.toInt)

  if (x >= a.sum - n / 2) {
    println("Yes")
  } else {
    println("No")
  }
}
