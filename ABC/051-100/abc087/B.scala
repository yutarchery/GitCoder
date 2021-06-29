import java.util.Scanner

object Main extends App {
    val scanner = new Scanner(System.in)

    val A, B, C, X = scanner.nextInt()
    val seqA = (0 to A).map(a => a * 500).toSeq
    val seqB = (0 to B).map(b => b * 100).toSeq
    val seqC = (0 to C).map(c => c * 50).toSeq

    val ans = seqA.foldLeft(0){(ans0, a) =>
        seqB.foldLeft(ans0){(ans1, b) =>
            seqC.foldLeft(ans1){(ans2, c) =>
                if (a + b + c == X) ans2 + 1
                else ans2
            }
        }
    }
    println(ans)
}