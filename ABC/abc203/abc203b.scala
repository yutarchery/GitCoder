import java.util.Scanner

object Main extends App{
    val scanner = new Scanner(System.in)

    val N, K = scanner.nextInt()

    var ans = 0
    for (i <- 1 to N; j <- 1 to K){
        var now = i * 100 + j
        ans += now
    }
    println(ans)
}