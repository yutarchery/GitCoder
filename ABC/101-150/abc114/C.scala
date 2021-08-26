import scala.io.StdIn._

object Main extends App {
  val n = readLong()
  println(solve(0, false, false, false))

  def solve(num: Long, three: Boolean, five: Boolean, seven: Boolean): Int = {
    if (num > n) {
      0
    } else {
      solve(num * 10 + 3, true, five, seven) +
        solve(num * 10 + 5, three, true, seven) +
        solve(num * 10 + 7, three, five, true) + {
          if (three && five && seven) {
            1
          } else {
            0
          }
        }
    }
  }
}
