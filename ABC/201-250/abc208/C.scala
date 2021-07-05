import java.util.Scanner
import scala.io.StdIn._

object Main extends App {
  val NK = readLine().split(" ").map(_.toLong)
  val N = NK(0)
  val K = NK(1)
  val A = readLine().split(" ").map(_.toInt)

  val Ai = A.zipWithIndex.sortBy(_._1)

  val ans = {
    val res = Array.fill(N.toInt)(K / N)
    (0 until (K % N).toInt).map { i =>
      res(Ai(i)._2) += 1
    }
    res
  }

  println(ans.mkString("\n"))
}
