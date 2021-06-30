import java.util.Scanner

object Main extends App {
    val scanner = new Scanner(System.in)
    val N = scanner.nextInt()
    val sqrtNSeq = (1 to math.sqrt(N).toInt).map(a => a).toSeq

    val ans = sqrtNSeq.foldLeft(N){ (res, value) =>
        math.min(res, math.abs(value - N / value) + (N - value * (N / value)))
    }
    println(ans)
}