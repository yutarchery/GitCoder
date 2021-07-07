import scala.io.StdIn._

object Main extends App {
  val n = readInt()
  val a = readLine().split(" ").map(_.toInt).sorted

  val ansTuple =
    (1 until n).foldLeft((n.toLong * (n - 1).toLong / 2, 1.toLong)) {
      (tuple, i) =>
        val ans = tuple._1
        val cnt = tuple._2
        if (a(i) == a(i - 1)) {
          (ans, cnt + 1)
        } else {
          (ans - cnt * (cnt - 1) / 2, 1)
        }
    }

  val ans = ansTuple._1 - ansTuple._2 * (ansTuple._2 - 1) / 2
  println(ans)
}
