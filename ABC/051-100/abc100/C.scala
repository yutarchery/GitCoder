import scala.io.StdIn._

object Main extends App {
  val n = readInt()
  val a = readLine().split(" ").map(_.toInt)

  val ans = a.foldLeft(0) { (acc, ai) =>
    acc + count(ai)
  }
  println(ans)

  def count(num: Int): Int = {
    if (num % 2 != 0) {
      0
    } else {
      count(num / 2) + 1
    }
  }
}
