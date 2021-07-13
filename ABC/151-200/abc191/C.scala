import scala.io.StdIn._

object Main extends App {
  val Array(h, w) = readLine().split(" ").map(_.toInt)

  val s = Array.fill(h)("")
  (0 until h).foreach { i =>
    s(i) = readLine()
  }

  val di = List(0, 1, 0, 1)
  val dj = List(0, 0, 1, 1)

  val ans = (0 until (h - 1)).foldLeft(0) { (acc, i) =>
    (0 until (w - 1)).foldLeft(acc) { (acc, j) =>
      {
        val cnt = (0 until 4).foldLeft(0) { (acc2, k) =>
          s(i + di(k))(j + dj(k)) match {
            case '#' => acc2 + 1
            case _   => acc2
          }
        }
        if (cnt % 2 == 0) {
          acc
        } else {
          acc + 1
        }
      }
    }
  }
  println(ans)

}
