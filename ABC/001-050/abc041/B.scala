import scala.io.StdIn._

object Main extends App {
  val mod = (1e9 + 7).toLong
  val nodes = readLine().split(' ').map(_.toLong)

  println {
    nodes.foldLeft(1L) { (acc, node) =>
      acc * node % mod
    }
  }
}
