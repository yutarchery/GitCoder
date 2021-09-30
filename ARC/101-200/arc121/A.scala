import scala.io.StdIn._

object Main extends App {
  val n = readInt()

  val locations = (0 until n).map { i =>
    val Array(x, y) = readLine().split(" ").map(_.toLong)
    Location(x, y, i)
  }.toSeq

  val locationsSortedByX = locations.sortBy(_.x)
  val locationsSortedByY = locations.sortBy(_.y)

  val xIndexes =
    locationsSortedByX.slice(0, 2).map(_.index) ++
      locationsSortedByX.slice(n - 2, n).map(_.index)

  val yIndexes =
    locationsSortedByY.slice(0, 2).map(_.index) ++
      locationsSortedByY.slice(n - 2, n).map(_.index)

  val indexes = (xIndexes ++ yIndexes).distinct

  val results = (0 until indexes.length)
    .flatMap { i =>
      (i + 1 until indexes.size).map { j =>
        makeResult(indexes(i), indexes(j))
      }
    }
    .distinct
    .map(_.dist)
    .sorted
    .reverse

  println(results(1))

  def makeResult(i: Int, j: Int): CandidateDistance = {
    if (i > j) {
      makeResult(j, i)
    } else {
      CandidateDistance(
        dist = calcDist(i, j),
        indexI = i,
        indexJ = j
      )
    }
  }

  def calcDist(i: Int, j: Int): Long = {
    val difX = math.abs(locations(i).x - locations(j).x)
    val difY = math.abs(locations(i).y - locations(j).y)
    math.max(difX, difY)
  }
}

case class Location(
    x: Long,
    y: Long,
    index: Int
)

case class CandidateDistance(
    dist: Long,
    indexI: Int,
    indexJ: Int
)
