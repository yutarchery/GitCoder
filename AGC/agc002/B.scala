import scala.io.StdIn._

object Main extends App {
  val Array(n, m) = readLine().split(' ').map(_.toInt)
  val operations = (0 until m).map { _ =>
    val Array(x, y) = readLine().split(' ').map(_.toInt)
    Operation(x, y)
  }

  val reds = Array.fill(n + 1)(false).updated(1, true)
  val balls = Array.fill(n + 1)(1).updated(0, 0)

  operations.foreach { operation =>
    if (reds(operation.x)) {
      reds.update(operation.y, true)
    }

    balls(operation.x) -= 1
    balls(operation.y) += 1

    if (balls(operation.x) == 0) {
      reds.update(operation.x, false)
    }
  }

  println(reds.count(_ == true))

}

case class Operation(
    x: Int,
    y: Int
)
