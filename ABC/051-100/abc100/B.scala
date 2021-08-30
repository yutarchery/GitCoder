import scala.io.StdIn._

object Main extends App {
  val Array(d, n) = readLine().split(" ").map(_.toInt)
  val border = math.pow(100, d).toInt

  println {
    (1 to (n + 1)).map(_ * border).filter(count(_) == d)(n - 1)
  }

  def count(num: Int): Int = {
    if (num % 100 != 0) {
      0
    } else {
      count(num / 100) + 1
    }
  }
}
