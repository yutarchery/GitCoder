import scala.io.StdIn._

object Main extends App {
  val p = readLine().split(' ').map(_.toInt - 1).toSeq
  println(p.map(i => ('a' + i).toChar).mkString)
}
