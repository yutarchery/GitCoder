import scala.io.StdIn._

object Main extends App {
  val x = readInt()
  println((1 to 360).map(_ * 360).filter(i => i % x == 0).head / x)
}
