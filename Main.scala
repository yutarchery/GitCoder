import java.util.Scanner

object Main extends App {
  val scanner = new Scanner(System.in)

  val N = scanner.nextInt()
  val A = List.fill(N)(scanner.nextInt()).toSeq

  val sumSeq = A.slice(1, N).scanLeft(A(0))(_ + _)

  println(solve(N, A))

  def solve(num: Int, seq: Seq[Int]): Int = {
    if (seq.sum % num != 0) {
      -1
    } else {
      val sumSeq = seq.slice(1, num).scanLeft(seq(0))(_ + _)
      val idealSeq = (1 to N)
        .map(i => i * (seq.sum / num))

      {
        for { (a, b) <- (sumSeq, idealSeq).zipped } yield (a, b)
      }
        .count(t => t._1 != t._2)
    }
  }
}
