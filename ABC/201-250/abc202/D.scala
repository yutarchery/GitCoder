import scala.io.StdIn._

object Main extends App {
  val Array(a, b, k) = readLine().split(" ").map(_.toLong)
  solve(a, b, k - 1)

  def solve(restA: Long, restB: Long, restK: Long): Unit = {
    if (restA + restB == 0) {
      println()
    } else if (restA == 0) {
      print('b')
      solve(restA, restB - 1, restK)
    } else if (restB == 0) {
      print('a')
      solve(restA - 1, restB, restK)
    } else {
      val judge = nCk(restA + restB - 1, restB)

      if (restK < judge) {
        print('a')
        solve(restA - 1, restB, restK)
      } else {
        print('b')
        solve(restA, restB - 1, restK - judge)
      }
    }
  }

  def nCk(n: Long, k: Long): Long = {
    (1L to k).foldLeft(1L) { (acc, i) =>
      acc * (n + 1 - i) / i
    }
  }
}
