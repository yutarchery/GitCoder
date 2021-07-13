import scala.io.StdIn._

object Main extends App {
  val Array(n, m) = readLine().split(" ").map(_.toInt)

  val a =
    if (m == 0) {
      Array(0, n + 1)
    } else {
      0 +: readLine().split(" ").map(_.toInt).sorted :+ (n + 1)
    }

  val cnt = (0 to m).foldLeft(n) { (acc, i) =>
    if (a(i + 1) - a(i) == 1) {
      acc
    } else {
      List(acc, a(i + 1) - a(i) - 1).min
    }
  }

  val ans = (0 to m).foldLeft(0) { (acc, i) =>
    val dif = a(i + 1) - a(i) - 1
    if (dif % cnt == 0) {
      acc + dif / cnt
    } else {
      acc + dif / cnt + 1
    }
  }

  println(ans)

}
