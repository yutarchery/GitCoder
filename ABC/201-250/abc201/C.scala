import scala.io.StdIn._

object Main extends App {
  val s = readLine()

  val ans = (0 until (1e4).toInt).foldLeft(0){(cnt, i) =>
    check(i) match {
      case true => cnt + 1
      case false => cnt
    }
  }
  println(ans)

  def check(num: Int): Boolean = {
    val numString = num.formatted("%04d")

    (0 until 10).foldLeft(true) { (flag, i) =>
      s(i) match {
        case 'o' => flag & numString.contains(i.toString())
        case 'x' => flag & !numString.contains(i.toString())
        case _ => flag
      }
    }
  }
}
