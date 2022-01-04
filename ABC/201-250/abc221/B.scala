import scala.io.StdIn._

object Main extends App {
  val s = readLine()
  val t = readLine()

  val ans = (0 until s.length() - 1).foldLeft(s == t) { (acc, idx) =>
    if (swap(idx) == t) true
    else acc
  }

  if (ans) {
    println("Yes")
  } else {
    println("No")
  }

  private def swap(idx: Int): String = {
    (0 until s.length()).map { i =>
      if (i == idx) s(i + 1)
      else if (i == idx + 1) s(i - 1)
      else s(i)
    }.mkString
  }

}
