import scala.io.StdIn._

object Main extends App {
  val s = readLine()
  val candidates = Seq("dream", "dreamer", "erase", "eraser")

  val visited = Array.fill(s.length() + 1)(false)
  val ans = Array.fill(s.length() + 1)(false)

  if (judge(0)) {
    println("YES")
  } else {
    println("NO")
  }

  def judge(start: Int): Boolean = {
    if (start == s.length()) {
      ans(start) = true
    } else if (!visited(start)) {
      visited(start) = true
      ans(start) = candidates.foldLeft(false) { (acc, c) =>
        if (start + c.length() > s.length()) {
          acc
        } else {
          if (s.slice(start, start + c.length()) == c) {
            acc | judge(start + c.length())
          } else {
            acc
          }
        }
      }
    }
    ans(start)
  }
}
