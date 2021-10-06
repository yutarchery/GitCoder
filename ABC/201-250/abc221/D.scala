import scala.io.StdIn._

object Main extends App {
  val n = readInt()

  val inputDays = (0 until n)
    .flatMap { _ =>
      val Array(a, b) = readLine().split(' ').map(_.toInt)
      Seq(Day(a, 1), Day(a + b, -1))
    }
    .sortBy(_.when)

  val maybeIndexes: Seq[Option[Int]] = (0 until inputDays.size)
    .map { i =>
      if (i == 0) {
        Some(0)
      } else if (inputDays(i).when != inputDays(i - 1).when) {
        Some(i)
      } else {
        None
      }
    }

  val indexes: Seq[Int] = for {
    maybeIndex <- maybeIndexes
    index <- maybeIndex
  } yield {
    index
  }

  val days = indexes.map(makeDay(_, Day(0, 0))).filter(_.change != 0)

  val answers = Array.fill(n + 1)(0)
  (1 until days.size).foldLeft(days(0).change) { (acc, i) =>
    answers(acc) += days(i).when - days(i - 1).when
    acc + days(i).change
  }

  println(answers.slice(1, n + 1).mkString(" "))

  def makeDay(index: Int, day: Day): Day = {
    val nowWhen = inputDays(index).when
    val nowChange = day.change + inputDays(index).change
    val nextDay = Day(nowWhen, nowChange)

    if (index == inputDays.size - 1) {
      nextDay
    } else if (inputDays(index).when != inputDays(index + 1).when) {
      nextDay
    } else {
      makeDay(index + 1, nextDay)
    }
  }

}

case class Day(
    when: Int,
    change: Int
)
