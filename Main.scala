import scala.io.StdIn._

object Main extends App {
  val n = readInt()
  val s = readLine()
  val q = readInt()

  val order = (0 until 2 * n).toArray

  val reverseFlag =
    (0 until q).foldLeft(false) { (acc, i) =>
      val Array(t, a, b) = readLine().split(" ").map(_.toInt)

      if (t == 1) {
        query(a - 1, b - 1, acc)
        acc
      } else {
        !acc
      }
    }

  val finalOrder =
    if (reverseFlag) {
      order.slice(n, 2 * n) ++ order.slice(0, n)
    } else {
      order
    }

  println(finalOrder.map(i => s(i)).toList.mkString(""))

  def query(a: Int, b: Int, reverseFlag: Boolean): Unit = {
    val (aIndex, bIndex) = {
      if (reverseFlag) {
        ((a + n) % (2 * n), (b + n) % (2 * n))
      } else {
        (a, b)
      }
    }

    val willChangeValueA = order(aIndex)

    order(aIndex) = order(bIndex)
    order(bIndex) = willChangeValueA
  }
}
