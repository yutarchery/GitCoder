import scala.io.StdIn._

object Main extends App {

  val s = (0 until 3).map { _ => readLine() }.toSeq
  val t = Seq("ABC", "ARC", "AGC", "AHC")

  println(t.filter(ti => !s.contains(ti)))

}
