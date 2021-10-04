import scala.io.StdIn._

object Main extends App {
  val mod = 998244353
  val n = readInt()
  val a = readLine().split(' ').map(_.toInt)

  val start = init(a(0))
  val ans = a.slice(1, n).foldLeft(start) { (acc, ai) => update(ai, acc) }
  println(ans.mkString("\n"))

  def init(num: Int): Seq[Long] = {
    (0 until 10)
      .map { i =>
        i match {
          case `num` => 1L
          case _     => 0L
        }
      }
  }

  def update(num: Int, now: Seq[Long]): Seq[Long] = {

    val res = Seq.fill(10)(0L)

    val sums = (0 until 10).foldLeft(res) { (acc, i) =>
      val index = (num + i) % 10
      val sum = acc(index) + now(i)
      acc.updated(index, sum % mod)
    }

    val times = (0 until 10).foldLeft(res) { (acc, i) =>
      val index = (num * i) % 10
      val sum = acc(index) + now(i)
      acc.updated(index, sum % mod)
    }

    (0 until 10).map { i =>
      (sums(i) + times(i)) % mod
    }
  }
}
