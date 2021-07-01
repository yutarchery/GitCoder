import java.util.Scanner

object Main extends App {
  val scanner = new Scanner(System.in)
  val N, S, T = scanner.nextInt()
  val A = Seq.fill(N)(scanner.nextInt())
  val weight = A.slice(1, N).scanLeft(A(0))(_ + _)
  println(weight.count(w => (S <= w && w <= T)))
}
