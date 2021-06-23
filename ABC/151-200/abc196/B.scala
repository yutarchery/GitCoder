import java.util.Scanner
import java.io.PrintWriter

object Main extends App{
    val scanner = new Scanner(System.in)
    
    val S = scanner.next()
    var flag = true
    for (i <- 0 until S.length()){
        if (S(i) == '.'){
            flag = false
        }
        if (flag){
            print(S(i))
        }
    }
    println()
}