import scala.io.StdIn._

object Main extends App {
  val n = readInt()
  val s = readLine()
  val q = readInt()

  val ans = (0 until q).foldLeft(s) { (acc, i) =>
    {
      val Array(t, a, b) = readLine().split(" ").map(_.toInt)

      if (t == 1) {
        query1(a - 1, b - 1, acc)
      } else {
        acc.slice(n, 2 * n) + acc.slice(0, n)
      }
    }
  }

  println(ans)

  def query1(a: Int, b: Int, s: String): String = {
    s.updated(a, s(b)).updated(b, s(a))
  }
}
