import java.util.Scanner

object Main extends App {
  val scanner = new Scanner(System.in)
	val L = Seq.fill(3)(scanner.nextInt()).sortBy(a => a)
	println(L(0) - L(1) + L(2))
}
