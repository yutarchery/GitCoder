import java.util.Scanner

object Main extends App {
    val scanner = new Scanner(System.in)
    val N = scanner.nextInt()
    val A = Seq.fill(N)(scanner.nextInt())
    println(solve(A))

    def solve(A: Seq[Int]): Int = {
        if (!A.forall(a => a % 2 == 0)){
            0
        }else{
            1 + solve(A.map(a => a / 2))
        }
    }
}