import scala.io.StdIn._

object Main extends App {
  val n = readLine()

  val ans = (1 until (1 << n.length())).foldLeft(0L) { (acc, i) =>
    val twoNumber = makeTwoNumber(0, i, TwoNumber("", ""))
    math.max(acc, twoNumber.solve)
  }
	println(ans)

  def makeTwoNumber(index: Int, rest: Int, now: TwoNumber): TwoNumber = {
    if (index == n.length()) {
      now
    } else {
      if (rest % 2 == 0) {
        makeTwoNumber(
          index + 1,
          rest / 2,
          TwoNumber(now.l + n(index), now.r)
        )
      } else {
        makeTwoNumber(
          index + 1,
          rest / 2,
          TwoNumber(now.l, now.r + n(index))
        )
      }
    }
  }
}

case class TwoNumber(
    l: String,
    r: String
) {
  def solve: Long = {
    (l, r) match {
      case ("", _) => 0
      case (_, "") => 0
      case (_, _) => {
        val numL = l.toSeq.sorted.reverse.toString().toLong
        val numR = r.toSeq.sorted.reverse.toString().toLong
        numL * numR
      }
    }
  }
}
