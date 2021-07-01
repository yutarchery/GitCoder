import java.util.Scanner

object Main extends App {
  val scanner = new Scanner(System.in)

  val S = scanner.next()
  val N = scanner.nextInt()
  val LR = List.fill(N)(scanner.nextInt() - 1, scanner.nextInt())

  println(
    LR.foldLeft(S) { (str, lr) =>
      solve(str, lr._1, lr._2)
    }
  )

  def solve(s: String, L: Int, R: Int): String = {
    s.slice(0, L) + s.slice(L, R).reverse + s.slice(R, s.length())
  }
}
