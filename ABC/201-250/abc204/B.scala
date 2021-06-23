import java.util.Scanner

object Main extends App{
    val scanner = new Scanner(System.in)
    val N = scanner.nextInt()
    
    var ans = 0
    for (i <- 0 until N){
        var a = scanner.nextInt()
        if (a >= 10){
            ans += a - 10
        }
    }
    println(ans)
}