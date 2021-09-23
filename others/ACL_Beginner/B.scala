import scala.io.StdIn._

object Main extends App {
  val Seq(a, b, c, d) = readLine().split(' ').map(_.toLong).toSeq

  if (b < c || d < a) {
    println("No")
  } else {
    println("Yes")
  }
}
