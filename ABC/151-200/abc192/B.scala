import java.util.Scanner
import java.io.PrintWriter

object Main extends App{
    val scanner = new Scanner(System.in)
    val S = scanner.next()

    var flag = true
    for (i <- 0 until S.length()){
        if (i % 2 == 0 && 'A' <= S(i) && S(i) <= 'Z') flag = false
        if (i % 2 != 0 && 'a' <= S(i) && S(i) <= 'z') flag = false
    }

    if (flag){
        println("Yes")
    }else{
        println("No")
    }
}