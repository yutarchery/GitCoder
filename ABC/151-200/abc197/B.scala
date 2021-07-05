import java.util.Scanner

object Main extends App {
  val scanner = new Scanner(System.in)

  val H = scanner.nextInt()
  val W = scanner.nextInt()
  val X = scanner.nextInt() - 1
  val Y = scanner.nextInt() - 1
  val S = List.fill(H)(scanner.next())

  println(
    solve(1, 0, X, Y)
      + solve(0, 1, X, Y)
      + solve(-1, 0, X, Y)
      + solve(0, -1, X, Y) - 3
  )

  def solve(dx: Int, dy: Int, x: Int, y: Int): Int = {
    if (0 <= x && x < H && 0 <= y && y < W) {
      if (S(x)(y) == '.') {
        1 + solve(dx, dy, x + dx, y + dy)
      } else {
        0
      }
    } else {
      0
    }
  }
}
