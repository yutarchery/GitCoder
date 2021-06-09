import java.util.Scanner
import java.io.PrintWriter

object Main extends App{
    val scanner = new Scanner(System.in)
    val N, X = scanner.nextInt()

    var ans = Array[Int]()
    var flag = false
    for (i <- 0 until N){
        val a = scanner.nextInt()
        if (a != X){
            ans :+= a
        }
    }
    println(ans.mkString(" "))
}