import java.util.Scanner
import java.io.PrintWriter

object Main extends App{
    val scanner = new Scanner(System.in)
    val N, X = scanner.nextInt()
    val A = new Array[Int](N)
    for (i <- 0 until N){
        A(i) = scanner.nextInt()
    }
    var ans = A.filter(a => a != X)
    println(ans.mkString(" "))
}