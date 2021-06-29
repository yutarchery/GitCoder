import java.util.Scanner

object Main extends App {
    val scanner = new Scanner(System.in)
    val X, A, B = scanner.nextInt()
    println((X - A) % B)
}