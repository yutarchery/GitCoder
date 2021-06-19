import java.util.Scanner
import java.io.PrintWriter

object Main extends App{
    val scanner = new Scanner(System.in)

    val A, B, C = scanner.nextInt()
    val ans = 21 - (A + B + C)
    println(ans)
}