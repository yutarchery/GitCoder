import scala.io.StdIn._

object Main extends App {
  val n = readInt()
  val a = (0 until n).map((readInt(), _)).sortBy(_._1)

  val ans = (0 until n).count(i => a(i)._2 % 2 != i % 2) / 2
  println(ans)

}
