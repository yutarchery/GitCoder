import scala.io.StdIn._

object Main extends App {
  val Array(n, k) = readLine().split(" ").map(_.toLong)
  val a = (readLine().split(" ").map(_.toLong) :+ 0L).sorted.reverse

  println {
    {
      (0L until n).foldLeft(Information(0, k)) { (acc, i) =>
        val now = a(i.toInt)
        val next = a((i + 1).toInt)

        val diff = now - next

        if (diff * (i + 1) < acc.rest) {
          val rest = acc.rest - diff * (i + 1)
          val ans = acc.ans + (now + next + 1) * diff / 2 * (i + 1)
          Information(ans, rest)
        } else if (acc.rest > 0) {
          val ans =
            acc.ans +
              (now * 2 + 1 - acc.rest / (i + 1)) * (acc.rest / (i + 1)) / 2 * (i + 1) +
              (now - acc.rest / (i + 1)) * (acc.rest % (i + 1))

          Information(ans, 0)
        } else {
          acc
        }
      }
    }.ans
  }

}

case class Information(
    ans: Long,
    rest: Long
)
