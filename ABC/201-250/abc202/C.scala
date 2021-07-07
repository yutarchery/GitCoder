import scala.io.StdIn._

object Main extends App {
  val n = readLong()
  val a = readLine().split(" ").map(_.toInt)
  val b = readLine().split(" ").map(_.toInt)
  val c = readLine().split(" ").map(_.toInt - 1)

  val aCount = Array.fill((1e5 + 1).toInt)(0: Long)
  a.foreach(ai => aCount(ai) += 1)

  val bCount = Array.fill((1e5 + 1).toInt)(0: Long)
  c.foreach(ci => bCount(b(ci)) += 1)

  val ans = (1 to (1e5).toInt).foldLeft(0: Long) { (res, i) =>
    res + aCount(i) * bCount(i)
  }
  println(ans)
}
