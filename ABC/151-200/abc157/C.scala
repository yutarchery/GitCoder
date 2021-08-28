import scala.io.StdIn._

object Main extends App {
  val Array(n, m) = readLine().split(" ").map(_.toInt)

  val visited = Array.fill(n)(false)
  val ans = Array.fill(n)(0)

  val exist = (0 until m).foldLeft(true) { (acc, i) =>
    val Array(s, c) = readLine().split(" ").map(_.toInt)

    if (!visited(s - 1)) {
      ans(s - 1) = c
      visited(s - 1) = true
    }

    if (ans(s - 1) != c || (n > 1 && s == 1 && c == 0)) {
      false
    } else {
      acc
    }
  }

  if (exist) {
    display()
  } else {
    println("-1")
  }

  def display(): Unit = {
    if (n == 1) {
      println(ans(0))
    } else {
      if (!visited(0)) {
        ans(0) = 1
      }
      println(ans.slice(0, n).mkString(""))
    }
  }
}
