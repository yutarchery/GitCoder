import java.util.Scanner
import java.io.PrintWriter

object Main extends App{
    val scanner = new Scanner(System.in)

    val N = scanner.nextInt()
    var checkList = new Array[Boolean](N + 1)

    for (i <- 1 to N){
        val num = scanner.nextInt()
        checkList(num) = true 
    }

    var ans = true
    for (i <- 1 to N){
        if (checkList(i) == false){
            ans = false
        }
    }

    if (ans){
        println("Yes")
    }else{
        println("No")
    }
}