import java.util.Scanner

object Main extends App{
    val scanner = new Scanner(System.in)

    val a, b, c = scanner.nextInt()

    if (a == b){
        println(c)
    }else if (b == c){
        println(a)
    }else if (c == a){
        println(b)
    }else{
        println(0)
    }
}