import java.util.Scanner

object Main extends App {
    val sc = new Scanner(System.in)
    val x = sc.nextInt
    val y = sc.nextInt

    if (x == y){
        println(x)
    }else{
        println(3 - x - y)
    }
}