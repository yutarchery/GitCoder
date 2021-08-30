import scala.io.StdIn._

object Main extends App {
  val Array(n, q) = readLine().split(" ").map(_.toInt)
  val s = readLine()

  val acCount = Array.fill((1e5 + 5).toInt)(0)
  val updated = Array.fill((1e5 + 5).toInt)(false)
  init()

  (0 until q).foreach { _ =>
    val Array(l, r) = readLine().split(" ").map(_.toInt)

    val ans = if (updated(l)) {
      acCount(r) - acCount(l - 1) - 1
    } else {
      acCount(r) - acCount(l - 1)
    }

    println(ans)

  }

  def init(): Unit = {
    (1 until s.length()).foreach { i =>
      acCount(i + 1) = acCount(i)
      if (s(i - 1) == 'A' && s(i) == 'C') {
        acCount(i + 1) += 1
        updated(i + 1) = true
      }
    }
  }
}
