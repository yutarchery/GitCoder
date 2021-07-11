import scala.io.StdIn._

object Main extends App {
  val Array(n, q) = readLine().split(" ").map(_.toInt)

  val treeGraph = Array.fill(n + 1)(Array.empty[Int])

  (1 until n).foreach(i => {
    val Array(a, b) = readLine.split(" ").map(_.toInt)
    treeGraph(a) :+= b
    treeGraph(b) :+= a
  })

  val startNode = 1
  val calcurateDistance = new CalcurateDistance(startNode)
  calcurateDistance.dfs(startNode)

  (1 to q).foreach { i =>
    {
      val Array(c, d) = readLine().split(" ").map(_.toInt)
      calcurateDistance.solve(c, d)
    }
  }

  class CalcurateDistance(startNode: Int) {
    val dist = Array.fill(n + 1)(0)
    val visited = {
      val initVisited = Array.fill(n + 1)(false)
      initVisited(startNode) = true
      initVisited
    }

    def dfs(node: Int): Unit = {
      treeGraph(node).foreach { nextNode =>
        {
          if (!visited(nextNode)) {
            visited(nextNode) = true
            dist(nextNode) = dist(node) + 1
            dfs(nextNode)
          }
        }
      }
    }

    def solve(node1: Int, node2: Int): Unit = {
      if ((dist(node1) - dist(node2)) % 2 == 0) {
        println("Town")
      } else {
        println("Road")
      }
    }
  }
}
