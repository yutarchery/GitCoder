import scala.io.StdIn._

object Main extends App {
  val mod = 998244353

  val Array(h, w) = readLine().split(" ").map(_.toInt)
  val s = (0 until h).map(_ => readLine())

  val ans = (0 until h + w - 1).foldLeft(1L) { (acc, sum) =>
    acc * sameColor(0, sum, '.') % mod
  }
  println(ans)

  def sameColor(i: Int, j: Int, color: Char): Long = {
    if (i < 0 || j >= w) {
      sameColor(i + 1, j - 1, color)
    } else if (i >= h || j < 0) {
      color match {
        case '.' => 2
        case _   => 1
      }
    } else {
      color match {
        case '.' => sameColor(i + 1, j - 1, s(i)(j))
        case _ => {
          s(i)(j) match {
            case '.'     => sameColor(i + 1, j - 1, color)
            case `color` => sameColor(i + 1, j - 1, s(i)(j))
            case _       => 0
          }
        }
      }
    }
  }

}
