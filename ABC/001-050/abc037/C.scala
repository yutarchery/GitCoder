import scala.io.StdIn._

object Main extends App {
  val Array(n, k) = readLine().split(' ').map(_.toLong)
  val a = readLine().split(' ').map(_.toLong)

  val indexes = (1L to n).map { i =>
    Seq(i, n + 1 - i, k, n - k + 1).min
  }

  val ans = (0 until n.toInt).foldLeft(0L) { (acc, i) =>
    acc + a(i) * indexes(i)
  }

  println(ans)
}
