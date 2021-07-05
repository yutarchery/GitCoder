import java.util.Scanner

object Main extends App {
  val scanner = new Scanner(System.in)
  val N = scanner.nextInt()
  val K = scanner.nextLong()
  val AB =
    List.fill(N)(scanner.nextLong(), scanner.nextLong()).sortBy(t => t._1)

  val ans = AB.foldLeft(K) { (dist, value) =>
    if (dist >= value._1) dist + value._2
    else dist
  }

  println(ans)
}
