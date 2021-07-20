import scala.io.StdIn._

object Main extends App {
  val Array(h, w, k) = readLine().split(" ").map(_.toInt)
  val c = new Array[String](h)
  (0 until h).foreach(i => c(i) = readLine())

  val hArray = Array.fill(h)(false)
  val wArray = Array.fill(w)(false)

  val ans = (0 until (1 << h)).foldLeft(0) { (acc, i) =>
    (0 until (1 << w)).foldLeft(acc) { (acc, j) =>
      setArray(i, j)
      if (solve()) acc + 1
      else acc
    }
  }
  println(ans)

  def setArray(hNum: Int, wNum: Int): Unit = {
    (0 until h).foldLeft(hNum) { (acc, i) =>
      if (acc % 2 != 0) {
        hArray(i) = true
      } else {
        hArray(i) = false
      }
      acc / 2
    }
    (0 until w).foldLeft(wNum) { (acc, i) =>
      if (acc % 2 != 0) {
        wArray(i) = true
      } else {
        wArray(i) = false
      }
      acc / 2
    }
  }

  def solve(): Boolean = {
    val blackCount = (0 until h).foldLeft(0) { (acc, i) =>
      (0 until w).foldLeft(acc) { (acc, j) =>
        if (!hArray(i) && !wArray(j) && c(i)(j) == '#') {
          acc + 1
        } else {
          acc
        }
      }
    }
    blackCount == k
  }
}
