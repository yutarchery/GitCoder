import scala.io.StdIn._

object Main extends App {
  val k = readInt()
  val visited = Array.fill(k)(false)

  println(solve(1, 7))

  def solve(turn: Int, num: Int): Int = {
    if (k % 2 == 0 || k % 5 == 0 || visited(num % k)) {
      -1
    } else if (num % k == 0) {
      turn
    } else {
      visited(num % k) = true
      solve(turn + 1, (num * 10 + 7) % k)
    }
  }
}
