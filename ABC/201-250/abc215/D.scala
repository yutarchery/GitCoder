import scala.io.StdIn._

object Main extends App {
  val Array(n, m) = readLine().split(" ").map(_.toInt)
  val a = readLine().split(" ").map(_.toInt).toSeq.filter(ai => ai > 1)

  val usedMap = a.foldLeft(Map.empty[Int, Boolean]) { (acc, ai) =>
    val max = math.sqrt(ai).toInt

    val otherMap = (2 to max).foldLeft(acc) { (acc2, i) =>
      if (ai % i != 0) {
        acc2
      } else {
        makeMap(i, acc2)
      }
    }

    val correctMap = (2 to max).foldLeft(otherMap){(acc2, i) => 
      if (ai % i != 0) {
        acc2
      } else {
        makeMap(ai / i, acc2)
      }
    }

    makeMap(ai, correctMap)
  }

  val ans = (1 to m).filter(i => !usedMap.contains(i))

  println(ans.length)
  println(ans.mkString("\n"))

  def makeMap(num: Int, map: Map[Int, Boolean]) = {
    if (map.contains(num)) {
      map
    } else {
      map ++ Seq.range(num, m + 1, num).map(i => i -> true).toMap
    }
  }
}
