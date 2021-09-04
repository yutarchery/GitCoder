import scala.io.StdIn._

object Main extends App {
  val n = readInt()
  val names = (0 until n)
    .map { _ =>
      val Array(s, t) = readLine().split(" ")
      Name(s, t)
    }
    .toSeq
    .distinct

  if (n == names.length) {
    println("No")
  } else {
    println("Yes")
  }
}

case class Name(
    s: String,
    t: String
)
