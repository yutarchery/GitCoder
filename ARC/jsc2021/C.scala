import scala.io.StdIn._

object Main extends App {
  val Array(a, b) = readLine().split(' ').map(_.toInt)

  println((1 to b).foldLeft(0) { (acc, i) =>
    if (judge(i)) {
      math.max(acc, i)
    } else {
      acc
    }
  })

  def judge(num: Int): Boolean = {
    val max = b / num
    a <= (max - 1) * num && max * num <= b
  }

}
