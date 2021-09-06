import scala.io.StdIn._

object Main extends App {
  val Array(a, b, x) = readLine().split(' ').map(_.toLong)
  println(count(b) - count(a - 1))

  def count(num: Long): Long = {
    num match {
      case -1 => 0
      case _  => num / x + 1
    }
  }
}
