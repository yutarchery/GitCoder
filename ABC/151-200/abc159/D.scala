import scala.io.StdIn._

object Main extends App {
  val n = readLong()
  val a = readLine().split(" ").map(_.toInt)

  val count = Array.fill((2e5 + 5).toInt)(0L)
  a.foreach { ai => count(ai) += 1 }

  val sum = (1 to n.toInt).foldLeft(0L) { (acc, i) =>
    acc + count(i) * (count(i) - 1) / 2
  }

  val ans = a.map { ai => sum - (count(ai) - 1) }

  println(ans.mkString("\n"))
}
