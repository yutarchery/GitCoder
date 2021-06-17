import java.util.Scanner
import java.io.PrintWriter

object Main extends App{
    val scanner = new Scanner(System.in)

    val A, B, C = scanner.nextInt()
    
    if (C == 0){
        println("=")
    }else if (C % 2 == 0){
        if (A.abs == B.abs) println("=")
        else if (A.abs < B.abs) println("<")
        else println(">")
    }else{
        if (A == B) println("=")
        else if (A < B) println("<")
        else println(">")
    }
}