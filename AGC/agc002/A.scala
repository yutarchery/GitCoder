import scala.io.StdIn._

object Main extends App {
  val Array(a, b) = readLine().split(" ").map(_.toLong)

  val ans =
    if (a * b <= 0) {
      "Zero"
    } else if (a > 0 || (b - a + 1) % 2 == 0) {
      "Positive"
    } else {
      "Negative"
    }

  println(ans)

}
