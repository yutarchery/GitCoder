import java.util.Scanner
import java.io.PrintWriter

object Main extends App{
    val scanner = new Scanner(System.in)

    val A = scanner.nextDouble()
    val B = scanner.nextDouble()

    println(A / 100 * B)
}