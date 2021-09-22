import scala.io.StdIn._

object Main extends App {
  val x = readLine().zipWithIndex
    .map(elem => (elem._1 -> ('a' + elem._2).toChar))
    .toMap
  val y = x.map(xi => (xi._2 -> xi._1)).toMap

  val n = readInt()
  val s = (0 until n).map(_ => readLine())

  val ans = solve(s)
  println(ans.mkString("\n"))

  def trans(s: String): String = {
    s.map(x(_)).mkString
  }

  def revTrans(t: String): String = {
    t.map(y(_)).mkString
  }

  def solve(s: Seq[String]): Seq[String] = {
    val t = s.map(trans(_)).sorted
    t.map(revTrans(_))
  }
}
