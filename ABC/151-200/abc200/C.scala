import scala.io.StdIn._

object Main extends App {
  val n = readInt()
  val a = readLine().split(" ").map(_.toInt)

  val cntArray = Array.fill(200)(0.toLong)
  a.foreach(ai => cntArray(ai % 200) += 1)

  val ans = cntArray.foldLeft(0.toLong){ (acc, cnt) =>
    acc + cnt * (cnt - 1) / 2
  }
  println(ans)
}
