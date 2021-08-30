import scala.io.StdIn._

object Main extends App {
  val Array(n, m) = readLine().split(" ").map(_.toInt)

  val xyzArray = Array.fill(n)(Array.fill(3)(0L))

  (0 until n).foreach { i =>
    xyzArray(i) = readLine().split(" ").map(_.toLong)
  }

  val sgn = Seq(-1, 1).map(_.toLong)

  val ans = sgn.foldLeft(0L) { (acc1, x) =>
    sgn.foldLeft(acc1) { (acc2, y) =>
      sgn.foldLeft(acc2) { (acc3, z) =>
        math.max(acc3, solve(x, y, z))
      }
    }
  }

  println(ans)

  def solve(x: Long, y: Long, z: Long): Long = {
    val sortedArray = xyzArray
      .map { xyz =>
        xyz(0) * x + xyz(1) * y + xyz(2) * z
      }
      .sorted
      .reverse

    (0 until m).foldLeft(0L) { (acc, i) =>
      acc + sortedArray(i)
    }
  }

}
