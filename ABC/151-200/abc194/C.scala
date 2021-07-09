import scala.io.StdIn._

object Main extends App {
  val n = readLong()
  val a = readLine().split(" ").map(_.toLong)
  val sum = a.sum
  val powSum = a.map(ai => ai * ai).sum
  println(n * powSum - sum * sum)
}
