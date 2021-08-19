import scala.io.StdIn._

object Main extends App {
  val Array(s, t) = readLine().split(" ").map(_.toInt)

  val ans = (0 to s).foldLeft(0) { (acc, a) =>
    (0 to (s - a)).foldLeft(acc) { (acc, b) =>
      (0 to (s - a - b)).foldLeft(acc) { (acc, c) =>
        if (a * b * c <= t) {
          acc + 1
        } else {
          acc
        }
      }
    }
  }

  println(ans)

}

