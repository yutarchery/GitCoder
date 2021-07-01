import java.util.Scanner

object Main extends App {
  val scanner = new Scanner(System.in)
  val L = Seq.fill(3)(scanner.nextInt())
  println((L.max + L.min) * 2 - L.sum)
}
