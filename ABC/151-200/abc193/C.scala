import scala.io.StdIn._

object Main extends App {
  val n = readLong()

  val sqrtN = math.sqrt(n).toLong

  val ans = {
    for {
      i <- (2.toLong to sqrtN)
      nowMax = (math.log(n.toDouble) / math.log(i.toDouble)).toLong
    } yield (2.toLong to nowMax).scanLeft(i * i)((acc, j) => acc * i)
  }.flatten.distinct
    .count(value => value <= n)

  println(n - ans)
}
