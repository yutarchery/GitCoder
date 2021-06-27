import java.util.Scanner

object Main extends App {
    val scanner = new Scanner(System.in)
    val A, B = scanner.nextInt()

    if ((A * B) % 2 == 0){
        println("Even")
    }else{
        println("Odd")
    }
}