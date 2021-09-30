import scala.io.StdIn._

object Main extends App {
  val n = readInt()
  val cards: Seq[Card] = (0 until n).map { _ =>
    val Array(a, b) = readLine().split(' ').map(_.toLong)
    Card(a, b)
  }

  val a = makeComponent(cards(0).a)
  val b = makeComponent(cards(0).b)

  val ans = a.foldLeft(0L) { (acc, ai) =>
    b.foldLeft(acc) { (acc2, bi) =>
      if (judge(ai, bi)) {
        math.max(acc2, lcm(ai, bi))
      } else {
        acc2
      }
    }
  }

  println(ans)

  def judge(a: Long, b: Long): Boolean = {
    cards.foldLeft(true) { (acc, card) =>
      if (card.a % a == 0 && card.b % b == 0) {
        acc
      } else if (card.b % a == 0 && card.a % b == 0) {
        acc
      } else {
        false
      }
    }
  }

  def gcd(a: Long, b: Long): Long = {
    if (a < b) {
      gcd(b, a)
    } else if (a % b == 0) {
      b
    } else {
      gcd(b, a % b)
    }
  }

  def lcm(a: Long, b: Long): Long = {
    val g = gcd(a, b)
    a / g * b
  }

  def makeComponent(n: Long): Seq[Long] = {
    val max = math.sqrt(n).toInt
    (1 to max)
      .foldLeft(Seq.empty[Long]) { (acc, i) =>
        if (n % i == 0) {
          acc ++ Seq(i, n / i)
        } else {
          acc
        }
      }
  }

}

case class Card(
    a: Long,
    b: Long
)
