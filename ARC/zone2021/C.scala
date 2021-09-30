import scala.io.StdIn._

object Main extends App {
  val n = readInt()
  val abilities: Seq[Ability] = (0 until n).map { _ =>
    val power = readLine().split(' ').map(_.toInt)
    Ability(power)
  }

  println(solve(0, Int.MaxValue / 2))

  def solve(left: Int, right: Int): Int = {
    if (right - left == 1) {
      left
    } else {
      val mid = (left + right) / 2

      if (check(mid)) {
        solve(mid, right)
      } else {
        solve(left, mid)
      }
    }
  }

  def check(x: Int): Boolean = {
    val indexes = abilities.map(_.makeIndex(x)).distinct

    indexes.foldLeft(false) { (acc, i) =>
      indexes.foldLeft(acc) { (acc, j) =>
        indexes.foldLeft(acc) { (acc, k) =>
          val now = (i | j | k)
          acc || ((i | j | k) == 31)
        }
      }
    }

  }
}

case class Ability(
    power: Seq[Int]
) {

  def makeIndex(value: Int) = {
    power.foldLeft(0) { (acc, elem) =>
      if (elem >= value) {
        2 * acc + 1
      } else {
        2 * acc
      }
    }
  }
}
