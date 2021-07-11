import scala.io.StdIn._

object Main extends App {
  val n = readInt()
  val a = readLine().split(" ").map(_.toLong).sorted

  val ans = (0 until n).foldLeft(1.toLong) { (acc, i) =>
    acc * (a(i) - i) % (1e9 + 7).toLong
  }
  println(ans)
}
