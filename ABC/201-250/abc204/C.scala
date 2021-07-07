import scala.io.StdIn._

object Main extends App {
  val Array(n, m) = readLine().split(" ").map(_.toInt)

  val roadGraph = Array.fill(n + 1)(List.empty[Int])
  (0 until m).foreach { i =>
    val Array(a, b) = readLine().split(" ").map(_.toInt)
    roadGraph(a) :+= b
  }

  val ans = (1 to n).foldLeft(0){(res, node) =>
    val solve = new Solve
    res + solve.countAnswer(node)
  }
  println(ans)

  class Solve() {
    private val visited = Array.fill(n + 1)(false)

    def countAnswer(node: Int): Int = {
      if (visited(node)) {
        0
      } else {
        visited(node) = true
        val ans = roadGraph(node).foldLeft(1) { (res, next) =>
          res + countAnswer(next)
        }
        ans
      }
    }
  }
}
