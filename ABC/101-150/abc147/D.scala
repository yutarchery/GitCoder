import scala.io.StdIn._

object Main extends App {
  val n = readLong()
  val a = readLine().split(" ").map(_.toLong)
  val mod = (1e9 + 7).toLong

  val ans =
    (0 until 60).foldLeft(0L) { (acc, i) =>
      val (zero, one) = a.foldLeft((0L, 0L)) { (tuple, aj) =>
        val tupleZero = tuple._1
        val tupleOne = tuple._2
        if ((aj & (1L << i)) == 0) {
          (tupleZero + 1, tupleOne)
        } else {
          (tupleZero, tupleOne + 1)
        }
      }

      val nowBit = (1L << i) % mod
      val nowTimes = zero * one % mod
      val nowSum = nowBit * nowTimes % mod

      (acc + nowSum) % mod
    }

  println(ans)
}
