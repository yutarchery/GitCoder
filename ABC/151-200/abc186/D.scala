import scala.io.StdIn._

object Main extends App {
  val n = readInt()
  val a = readLine().split(' ').map(_.toLong).sorted.reverse

  val ans = (0 until n).foldLeft(0L) { (acc, i) =>
    acc + a(i) * (n - 1 - 2 * i).toLong
  }
  println(ans)

}
