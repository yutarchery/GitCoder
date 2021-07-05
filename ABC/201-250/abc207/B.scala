import java.util.Scanner

object Main extends App {
  val scanner = new Scanner(System.in)

  val A, B, C, D = scanner.nextInt()
  val ans = if (D * C - B <= 0) {
    -1
  } else {
    (A - 1) / (D * C - B) + 1
  }
  println(ans)
}
