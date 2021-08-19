import scala.io.StdIn._

object Main extends App {
  val s = new Array[String](4)

  (0 until 4).foreach { i =>
    val si = readLine()
    s(i) = si
  }

  val sSize = s.sorted.distinct.size

  if (sSize == 4) {
    println("Yes")
  } else {
    println("No")
  }

}
