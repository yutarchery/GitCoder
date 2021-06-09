import java.util.Scanner
import java.io.PrintWriter

object Main extends App{
    val scanner = new Scanner(System.in)
    val N, X = scanner.nextInt()
    val A = Array.fill(N)(scanner.nextInt())
    
    var ans = A.filter(a => a != X)
    println(ans.mkString(" "))
}