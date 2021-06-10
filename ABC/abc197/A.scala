import java.util.Scanner
import java.io.PrintWriter

object Main extends App{
    val scanner = new Scanner(System.in)
    val S = scanner.next()
    var ans:String = S.substring(1, 3) + S(0)
    println(ans)
}