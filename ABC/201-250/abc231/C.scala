import scala.io.StdIn._

object Main extends App {
  val Array(n, q) = readLine().split(' ').map(_.toInt)
  val a = readLine().split(' ').map(_.toInt).sorted

  val x = (0 until q).map(_ => readInt())

  println(x.map(xi => solve(xi)).mkString("\n"))

  private def solve(height: Int): Int = {
    if (a.last < height) return 0
    if (height < a.head) return n
    n - binary(height, 0, n - 1)
  }

  private def binary(height: Int, minIdx: Int, maxIdx: Int): Int = {
    if (minIdx + 1 == maxIdx) return maxIdx

    val midIdx = (minIdx + maxIdx) / 2

    if (a(midIdx) < height) {
      binary(height, midIdx, maxIdx)
    } else {
      binary(height, minIdx, midIdx)
    }
  }
}
