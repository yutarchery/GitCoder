import scala.io.StdIn._

object Main extends App {
  val n = readInt()
  val p = readLine().split(" ").map(_.toInt).zipWithIndex.sortBy(_._1)
  val q = p.map(_._2 + 1)

  println(q.mkString(" "))
}
