import scala.io.StdIn._

object Main extends App {
  val n = readInt()
  val a = (0 until n).map(_ => readLong())

  val ans = a.foldLeft(Answer(0, 0)) { (acc, ai) =>
    if (ai == 0) {
      Answer(acc.sum, 0)
    } else {
      Answer(acc.sum + (acc.rest + ai) / 2, (acc.rest + ai) % 2)
    }
  }
  println(ans.sum)
}

case class Answer(
    sum: Long,
    rest: Long
)
