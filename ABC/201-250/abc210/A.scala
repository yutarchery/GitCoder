import scala.io.StdIn._

object Main extends App {
  val Array(n, a, x, y) = readLine().split(" ").map(_.toInt)

  val ans = {
    if (n <= a) {
      x * n
    } else {
      x * a + y * (n - a)
    }
  }
  println(ans)
}
