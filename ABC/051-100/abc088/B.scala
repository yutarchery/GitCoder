import java.util.Scanner

object Main extends App {
    val scanner = new Scanner(System.in)
    val N = scanner.nextInt()
    val A = Seq.fill(N)(scanner.nextInt()).sortBy(x => x).reverse
    println(solve(A, 0))

    def solve(seqA: Seq[Int], index: Int): Int = {
        if (index == seqA.length){
            0
        }else if (index % 2 == 0){
            solve(seqA, index + 1) + seqA(index)
        }else{
            solve(seqA, index + 1) - seqA(index)
        }
    }
}