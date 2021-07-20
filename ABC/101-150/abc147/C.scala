import scala.io.StdIn._

object Main extends App {
  val n = readInt()

  val a = new Array[Int](n)
  val x = new Array[Array[Int]](n)
  val y = new Array[Array[Int]](n)

  (0 until n).foreach { i =>
    a(i) = readInt()
    x(i) = new Array[Int](a(i))
    y(i) = new Array[Int](a(i))

    (0 until a(i)).foreach { j =>
      val Array(xij, yij) = readLine().split(" ").map(_.toInt)
      x(i)(j) = xij - 1
      y(i)(j) = yij
    }
  }

  val honest = Array.fill(n)(0)

  val ans = (0 until (1 << n)).foldLeft(0) { (acc, i) =>
    math.max(acc, check(i))
  }
  println(ans)

  def check(num: Int): Int = {
    setHonest(num)

    val flag = (0 until n).foldLeft(true) { (acc, i) =>
      if (honest(i) == 1) {
        (0 until a(i)).foldLeft(acc) { (acc, j) =>
          acc & (honest(x(i)(j)) == y(i)(j))
        }
      } else {
        acc
      }
    }

    if (flag) {
      honest.count(_ == 1)
    } else {
      0
    }
  }

  def setHonest(num: Int): Unit = {
    (0 until n).foldLeft(num) { (acc, i) =>
      honest(i) = acc % 2
      acc / 2
    }
  }

}
