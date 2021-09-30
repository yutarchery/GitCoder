import scala.io.StdIn._

object Main extends App {
  val mod: Long = 998244353

  val Seq(n, k) = readLine().split(' ').map(_.toInt).toSeq

  val fixed = Array.fill(n + 1)(false)
  val candidates = Array.fill(n + 2)(0L)

  (0 until k).foreach { _ =>
    val Array(ci, ki) = readLine().split(' ')
    fixed(ki.toInt) = true
    ci match {
      case "L" => candidates(ki.toInt) += 1
      case "R" => {
        candidates(0) += 1
        candidates(ki.toInt + 1) -= 1
      }
    }
  }

  (1 to n).foreach { i => candidates(i) += candidates(i - 1) }

  val ans = (1 to n).foldLeft(1L) { (acc, i) =>
    if (fixed(i)) {
      acc
    } else {
      acc * candidates(i) % mod
    }
  }

  println(ans)

}

