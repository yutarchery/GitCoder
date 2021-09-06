import scala.io.StdIn._

object Main extends App {
  val n = readInt()

  val apx = (0 until n)
    .map { _ =>
      val Array(a, p, x) = readLine().split(' ').map(_.toInt)
      APX(a, p, x)
    }
    .filter(elem => elem.a < elem.x)
    .sortBy(_.p)
    .toSeq

  apx.size match {
    case 0 => println(-1)
    case _ => println(apx(0).p)
  }
}

case class APX(
    a: Int,
    p: Int,
    x: Int
)
