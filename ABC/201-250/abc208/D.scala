import scala.io.StdIn._

object Main extends App {
  val inf = 1e16.toLong
  val Array(n, m) = readLine().split(" ").map(_.toInt)
  val dist = distInit(n)

  (0 until m).foreach { i =>
    val Array(a, b, c) = readLine().split(" ").map(_.toInt)
    dist(a - 1)(b - 1) = c
  }

  val ans = (0 until n).foldLeft(0L) { (acc, i) =>
    acc + operation(i)
  }
  println(ans)

  def operation(turn: Int): Long = {
    (0 until n).foreach { i =>
      (0 until n).foreach { j =>
        dist(i)(j) = math.min(dist(i)(j), dist(i)(turn) + dist(turn)(j))
      }
    }

    dist.flatMap(i => i.filter(_ < inf)).sum
  }

  def distInit(size: Int): Array[Array[Long]] = {
    val matrix = Array.ofDim[Long](size, size)
    (0 until size).foreach { i =>
      (0 until size).foreach { j =>
        if (i != j) {
          matrix(i)(j) = inf
        } else {
          matrix(i)(j) = 0
        }
      }
    }
    matrix
  }

}
