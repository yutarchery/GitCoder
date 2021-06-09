import java.util.Scanner

object Main extends App{
    val scanner = new Scanner(System.in)
    val N, X = scanner.nextInt()

    var ans = Array[Int]()
    for (i <- 0 until N){
        val a = scanner.nextInt()
        if (a != X){
            ans :+= a
        }
    }

    val K = ans.size
    for (i <- 0 until K){
        print(ans(i))
        if (i < K - 1){
            print(" ")
        }else{
            print("\n")
        }
    }

}