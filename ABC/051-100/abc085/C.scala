import java.util.Scanner

object Main extends App {
    val scanner = new Scanner(System.in)

    val N = scanner.nextInt()
    val Y = scanner.nextInt() / 1000
    val seqN = (0 to N).map(value => value).toSeq

    val ans = seqN.foldLeft(List(List(-1, -1, -1))){ (res, a) =>
        seqN.foldLeft(res){ (res, b) =>
            if (a + b <= N && 10 * a + 5 * b + (N - a - b) == Y) List(a, b, N - a - b) :: res
            else res
        }
    }
    println(ans(0).mkString(" "))
}