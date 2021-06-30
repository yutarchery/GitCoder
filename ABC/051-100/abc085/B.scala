import java.util.Scanner

object Main extends App {
    val scanner = new Scanner(System.in)
    val N = scanner.nextInt()
    val A = Seq.fill(N)(scanner.nextInt()).distinct
    println(A.length)
}