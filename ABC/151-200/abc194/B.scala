import java.util.Scanner

object Main extends App {
  val scanner = new Scanner(System.in)

  val N = scanner.nextInt()
  val tasks = Seq.fill(N)(scanner.nextInt(), scanner.nextInt())

  val A = tasks.sortBy(_._1)
  val B = tasks.sortBy(_._2)

  val ans = if (A(0) == B(0)) {
    List(
      A(0)._1 + A(0)._2,
      math.max(A(0)._1, B(1)._2),
      math.max(A(1)._1, B(0)._2)
    ).min
  } else {
    math.max(A(0)._1, B(0)._2)
  }

  println(ans)
}
