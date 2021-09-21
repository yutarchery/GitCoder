import scala.io.StdIn._

object Main extends App {
  val n = readInt()
  val s = (0 until n).map(_ => readLine()).toSeq
  val t = (0 until n).map(_ => readLine()).toSeq

  val countFlag = {
    val sCount = s.map(si => si.count(_ == '#')).sum
    val tCount = t.map(ti => ti.count(_ == '#')).sum
    sCount == tCount
  }

  val ans = (0 until 4).foldLeft(false) { (acc, k) =>
    val u = rotate(t, k)
    acc || compare(s, u)
  }

  (ans && countFlag) match {
    case true  => println("Yes")
    case false => println("No")
  }

  def rotate(t: Seq[String], turn: Int): Seq[String] = {
    if (turn == 0) {
      t
    } else {
      val u = (0 until n).map { i =>
        (0 until n).map { j =>
          t(n - 1 - j)(i)
        }.mkString
      }.toSeq
      rotate(u, turn - 1)
    }
  }

  def makeEdge(s: Seq[String]): Edge = {
    (0 until n).foldLeft(Edge(n, n)) { (acc, i) =>
      (0 until n).foldLeft(acc) { (acc2, j) =>
        if (s(i)(j) == '#') {
          val nextI = math.min(acc2.i, i)
          val nextJ = math.min(acc2.j, j)
          Edge(nextI, nextJ)
        } else {
          acc2
        }
      }
    }
  }

  def compare(s: Seq[String], u: Seq[String]): Boolean = {
    val edgeS = makeEdge(s)
    val edgeU = makeEdge(u)

    (0 until n).foldLeft(true) { (acc, i) =>
      if (i + edgeS.i >= n || i + edgeU.i >= n) {
        acc
      } else {
        (0 until n).foldLeft(acc) { (acc2, j) =>
          if (j + edgeS.j >= n || j + edgeU.j >= n) {
            acc2
          } else {
            acc2 && s(i + edgeS.i)(j + edgeS.j) == u(i + edgeU.i)(j + edgeU.j)
          }
        }
      }
    }
  }
}

case class Edge(
    i: Int,
    j: Int
)
