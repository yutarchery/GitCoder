import scala.io.StdIn._

object Main extends App {
  val t = readInt()

  val ans = (0 until t).foldLeft(Array.empty[String]) { (acc, _) =>
    val n = readInt()
    (0 until 3).foreach(_ => readLine())
    acc :+ display(n)
  }

  println(ans.mkString("\n"))

  def display(n: Int): String = {
    val ones = Seq.fill(n)(1)
    val zeros = Seq.fill(n)(0)
    (ones ++ zeros :+ 1).mkString
  }
}
