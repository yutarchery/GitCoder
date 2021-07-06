import scala.io.StdIn._

object Main extends App {
  val P = readInt()

  val cand = (2 to 15).scanLeft(1)(_ * _).toList.filter(p => p <= P)
  println(solve(P))

  def solve(price: Int): Int = {
    if (price == 0) {
      0
    } else {
      val maxCoin = cand.filter(p => p <= price).last
      solve(price % maxCoin) + price / maxCoin
    }
  }
}
