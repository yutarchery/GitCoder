import scala.io.StdIn._

object Main extends App {
  val Array(n, m) = readLine().split(" ").map(_.toInt)
  val A = Array.fill(m)(0)

  val visited = Array.fill(n + 2)(false)
  (0 until m).map { i =>
    {
      A(i) = readInt()
      visited(A(i)) = true
    }
  }

  val ans = Array.fill(n + 2)(0: Long)
  ans(0) = 1

  (0 until n).map { i =>
    ans(i) %= (1e9 + 7).toInt
    if (!visited(i + 1)) {
      ans(i + 1) += ans(i)
    }
    if (!visited(i + 2)) {
      ans(i + 2) += ans(i)
    }
  }
  println(ans(n) % (1e9 + 7).toInt)

}
