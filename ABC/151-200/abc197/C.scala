import scala.io.StdIn._

object Main extends App {
  val n = readInt()
  val a = readLine().split(" ").map(_.toInt)

  println {
    (0 until (1 << n)).foldLeft(a.foldLeft(0)(_ ^ _)) { (acc, i) =>
      math.min(acc, solve(i))
    }
  }

  def solve(num: Int): Int = {
    val (xorResult, orResult, rest) =
      a.foldLeft((0, 0, num)) { (acc, ai) =>
        val xorValue = acc._1
        val orValue = acc._2 | ai
        val restValue = acc._3

        if (restValue % 2 == 0) {
          (xorValue ^ orValue, 0, restValue / 2)
        } else {
          (xorValue, orValue, restValue / 2)
        }
      }
    xorResult ^ orResult
  }
}
