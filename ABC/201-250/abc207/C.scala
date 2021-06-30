import java.util.Scanner

object Main extends App {
  val scanner = new Scanner(System.in)
  val N = scanner.nextInt()
  val tuple = List
    .fill(N)(scanner.nextDouble(), scanner.nextDouble(), scanner.nextDouble())
    .toSeq

  val rangeSeq = tuple
    .foldLeft(List.empty[(Double, Double)]) { (res, t) =>
      if (t._1 == 1) res :+ (t._2, t._3)
      else if (t._1 == 2) res :+ (t._2, t._3 - 0.1)
      else if (t._1 == 3) res :+ (t._2 + 0.1, t._3)
      else res :+ (t._2 + 0.1, t._3 - 0.1)
    }
    .toSeq

  val ans = (rangeSeq.foldLeft(0) { (res, t1) =>
    rangeSeq.foldLeft(res) { (res, t2) =>
      if (t1._2 < t2._1 || t2._2 < t1._1) res
      else res + 1
    }
  } - N) / 2

  println(ans)
}
