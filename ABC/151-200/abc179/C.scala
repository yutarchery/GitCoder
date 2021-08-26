import scala.io.StdIn._

object Main extends App {
  val n = readLong()

  val ans = (1L to n).foldLeft(0L) { (acc, a) =>
    acc + (n - 1) / a
  }

  println(ans)
}
