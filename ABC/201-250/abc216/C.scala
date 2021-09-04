import scala.io.StdIn._

object Main extends App {
  val n = readLong()
  println(solve(new String(), n))

  def solve(str: String, num: Long): String = {
    if (num == 0) {
      str
    } else if (num % 2 == 0) {
      solve('B' + str, num / 2)
    } else {
      solve('A' + str, num - 1)
    }
  }
}
