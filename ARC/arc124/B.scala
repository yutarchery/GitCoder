import scala.io.StdIn._

object Main extends App {
  val n = readInt()
  val a = readLine().split(' ').map(_.toInt)
  val b = readLine().split(' ').map(_.toInt).sorted

  val ans = b.map(bi => bi ^ a(0)).distinct.filter(check(_)).sorted

  println(ans.size)
  println(ans.mkString("\n"))

  def check(x: Int): Boolean = {
    val c = a.map(ai => ai ^ x).sorted
    b sameElements (c)
  }
}
