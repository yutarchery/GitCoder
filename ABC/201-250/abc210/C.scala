import scala.io.StdIn._
import scala.collection.mutable

object Main extends App {
  val Array(n, k) = readLine().split(" ").map(_.toInt)
  val c = readLine().split(" ").map(_.toInt)

  val cntMap = mutable.Map.empty[Int, Int]
  c.foreach { ci =>
    if (!cntMap.contains(ci)) {
      cntMap += (ci -> 0)
    }
  }

  println(solve(0, 0, 0))

  def solve(index: Int, cnt: Int, ans: Int): Int = {
    if (index == n) {
      ans
    } else if (index < k) {
      val newColor = cntMap(c(index)) == 0
      cntMap(c(index)) += 1
      if (newColor) {
        solve(index + 1, cnt + 1, cnt + 1)
      } else {
        solve(index + 1, cnt, cnt)
      }
    } else {
      cntMap(c(index - k)) -= 1
      val oldColor = cntMap(c(index - k)) == 0

      val newColor = cntMap(c(index)) == 0
      cntMap(c(index)) += 1

      if (oldColor && newColor) {
        solve(index + 1, cnt, ans)
      } else if (oldColor) {
        solve(index + 1, cnt - 1, ans)
      } else if (newColor) {
        solve(index + 1, cnt + 1, math.max(ans, cnt + 1))
      } else {
        solve(index + 1, cnt, ans)
      }
    }
  }
}
