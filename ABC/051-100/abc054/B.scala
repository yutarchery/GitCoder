import scala.io.StdIn._

object Main extends App {
  val Array(n, m) = readLine().split(' ').map(_.toInt)

  val a = (0 until n).map { _ => readLine() }
  val b = (0 until m).map { _ => readLine() }

  val ans = (0 until (n - m + 1)).foldLeft(false) { (acc1, ai) =>
    (0 until (n - m + 1)).foldLeft(acc1) { (acc2, aj) =>
      val flag = (0 until m).foldLeft(true) { (acc3, bi) =>
        (0 until m).foldLeft(acc3) { (acc4, bj) =>
          acc4 && check(ai + bi, aj + bj, bi, bj)
        }
      }
      acc2 || flag
    }
  }

  ans match {
    case true  => println("Yes")
    case false => println("No")
  }

  def check(ai: Int, aj: Int, bi: Int, bj: Int): Boolean = {
    a(ai)(aj) == b(bi)(bj)
  }
}
