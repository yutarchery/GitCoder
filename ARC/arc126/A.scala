import scala.io.StdIn._

object Main extends App {
  val t = readInt()
  val bars: Seq[Bar] = (0 until t).map { _ =>
    val Seq(n2, n3, n4) = readLine().split(' ').map(_.toLong).toSeq
    Bar(n2, n3, n4, 0)
  }.toSeq

  bars.map { bar =>
    val ans = (0 until math.pow(5, 5).toInt).foldLeft(0L) { (acc, num) =>
      math.max(acc, solve(bar, num, 0))
    }
    println(ans)
  }

  def solve(bar: Bar, num: Int, turn: Int): Long = {
    if (turn == 5) {
      bar.sum
    } else {
      val nextBar = Bar.solve(bar, num)
      solve(Bar.solve(bar, num), num / 5, turn + 1)
    }
  }
}

case class Bar(
    n2: Long,
    n3: Long,
    n4: Long,
    sum: Long
)

object Bar {
  def solve(bar: Bar, num: Int): Bar = {
    num % 5 match {
      case 0 => process1(bar)
      case 1 => process2(bar)
      case 2 => process3(bar)
      case 3 => process4(bar)
			case 4 => process5(bar)
    }
  }

  private def process1(bar: Bar): Bar = {
    val ans = math.min(bar.n2, bar.n3) / 2
    Bar(bar.n2 - ans * 2, bar.n3 - ans * 2, bar.n4, bar.sum + ans)
  }

  private def process2(bar: Bar): Bar = {
    val ans = math.min(bar.n3 / 2, bar.n4)
    Bar(bar.n2, bar.n3 - ans * 2, bar.n4 - ans, bar.sum + ans)
  }

  private def process3(bar: Bar): Bar = {
    val ans = math.min(bar.n2, bar.n4 / 2)
    Bar(bar.n2 - ans, bar.n3, bar.n4 - ans * 2, bar.sum + ans)
  }

  private def process4(bar: Bar): Bar = {
    val ans = bar.n2 / 5
    Bar(bar.n2 - ans * 5, bar.n3, bar.n4, bar.sum + ans)
  }

  private def process5(bar: Bar): Bar = {
    val ans = math.min(bar.n2 / 3, bar.n4)
    Bar(bar.n2 - ans * 3, bar.n3, bar.n4 - ans, bar.sum + ans)
  }

}
