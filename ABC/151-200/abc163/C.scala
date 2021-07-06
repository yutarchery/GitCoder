import scala.io.StdIn._

object Main extends App {
  val N = readInt()
  val A = readLine().split(" ").map(_.toInt)

  val ans = Array.fill(N)(0)
  A.foreach(a => ans(a - 1) += 1)
  println(ans.mkString("\n"))

}
