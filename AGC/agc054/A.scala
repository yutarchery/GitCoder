import scala.io.StdIn._

object Main extends App {
  val n = readInt()
  val s = readLine()
  println(solve())

  def solve(): Int = {
    if (s.head != s.last) {
      1
    } else {
      if (isAble()) {
        2
      } else {
        -1
      }
    }
  }

  def isAble(): Boolean = {
    (1 until s.length() - 1).foldLeft(false) { (acc, i) =>
      acc || (s.head != s(i) && s(i + 1) != s.last)
    }
  }
}
