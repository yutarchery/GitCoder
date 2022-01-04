import scala.io.StdIn._

object Main extends App {
  val s = readLine()
  val t = readLine()

  val nums = (0 until (s.length())).map(idx => judge(s(idx), t(idx)))

  val ans = (0 until (s.length() - 1)).foldLeft("Yes") { (acc, idx) =>
    if (nums(idx) != nums(idx + 1)) "No"
    else acc
  }

	println(ans)

  def judge(a: Char, b: Char): Int = {
    if (a - b < 0) {
      a - b + 26
    } else {
      a - b
    }
  }
}
