import scala.io.StdIn._

object Main extends App {
  val n = readInt()
  val s = readLine()
  solve(0)

  def solve(num: Int): Unit = {
    if (s(num) == '1') {
      if (num % 2 == 0) {
        println("Takahashi")
      } else {
        println("Aoki")
      }
    } else {
      solve(num + 1)
    }
  }
}
