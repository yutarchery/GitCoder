import scala.io.StdIn._

object Main extends App {
  val mod: Long = 998244353

  val n = readInt()
  val a = readLine().split(' ').map(_.toLong).sorted.reverse

  val answer = a.foldLeft(Answer(0, 0)) { (acc, ai) =>
    val sum = (ai * acc.bi + acc.sum) % mod
    val bi = (2 * acc.bi + ai) % mod
    Answer(sum, bi)
  }

  val sum = a.foldLeft(0L) { (acc, ai) =>
    (acc + ai * ai) % mod
  }

  println((answer.sum + sum) % mod)

}

case class Answer(
    sum: Long,
    bi: Long
)
