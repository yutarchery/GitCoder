import scala.io.StdIn._

object Main extends App {
  val n = readInt()

  val location: Seq[Location] = (0 until n).map { _ =>
    val Array(x, y) = readLine().split(' ').map(_.toInt)
    Location(x, y)
  }

  val map: Map[Location, Boolean] = location.map { l =>
    (l -> true)
  }.toMap

  val ans = location.foldLeft(0) { (acc, l1) =>
    location.foldLeft(acc) { (acc, l2) =>
      if (check(l1, l2)) {
        acc + 1
      } else {
        acc
      }
    }
  }

  println(ans / 4)

  def check(l1: Location, l2: Location): Boolean = {
    val Seq(x1, y1, x2, y2) = Seq(l1.x, l1.y, l2.x, l2.y)
    if (x1 == x2 || y1 == y2) {
      false
    } else {
      map.contains(Location(x2, y1)) && map.contains(Location(x1, y2))
    }
  }

}

case class Location(
    x: Int,
    y: Int
)
