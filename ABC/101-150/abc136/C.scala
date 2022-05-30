import scala.io.StdIn._

object Main extends App {

  val n: Int = readInt()
  val h: Seq[Int] = readLine().split(' ').map(_.toInt)

  val ans = h.foldLeft(AnswerFlow.initialValue) { (acc, hi) =>
    if (acc.isAble) {
      if (hi < acc.maxHeight) {
        AnswerFlow(false, acc.maxHeight)
      } else {
        AnswerFlow(true, Math.max(acc.maxHeight, hi - 1))
      }
    } else {
      acc
    }
  }

  if (ans.isAble) {
    println("Yes")
  } else {
    println("No")
  }

}

case class AnswerFlow(
    isAble: Boolean,
    maxHeight: Int
)

object AnswerFlow {
  final val initialValue = AnswerFlow(isAble = true, maxHeight = 0)
}
