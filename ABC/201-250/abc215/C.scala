import scala.io.StdIn._

object Main extends App {
  val Array(s, k) = readLine().split(" ")
  println(s.permutations.toSeq.sorted.apply(k.toInt - 1))
}
