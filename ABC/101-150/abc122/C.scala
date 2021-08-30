import scala.io.StdIn._

object Main extends App {
  val Array(n, q) = readLine().split(" ").map(_.toInt)
  val s = readLine()

  val acCount = Array.fill((1e5 + 5).toInt)(0)
  val updated = Array.fill((1e5 + 5).toInt)(false)
  val l = Array.fill(q)(0)
  val r = Array.fill(q)(0)
  init()

  val ans = (0 until q).map{ i => 
    if (updated(l(i))){
      acCount(r(i)) - acCount(l(i) - 1) - 1
    }else{
      acCount(r(i)) - acCount(l(i) - 1)
    }

  }

  println(ans.mkString("\n"))

  def init(): Unit = {
    (1 until s.length()).foreach { i =>
      acCount(i + 1) = acCount(i)
      if (s(i - 1) == 'A' && s(i) == 'C') {
        acCount(i + 1) += 1
        updated(i + 1) = true
      }
    }

    (0 until q).foreach { i =>
      val Array(li, ri) = readLine().split(" ").map(_.toInt)
      l(i) = li
      r(i) = ri
    }
  }
}
