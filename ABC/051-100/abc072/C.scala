import scala.io.StdIn._

object Main extends App {
  val n = readInt()
  val a = readLine().split(' ').map(_.toInt).toSeq

  println(makeCount(a).max)

  def makeCount(a: Seq[Int]): Seq[Int] = {
    val cnt = Array.fill((1e5 + 5).toInt)(0)
    a.map { ai =>
      if (ai - 1 >= 0) {
        cnt(ai - 1) += 1
      }
      cnt(ai) += 1
      cnt(ai + 1) += 1
    }
    cnt
  }
}
