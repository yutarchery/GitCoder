import java.util.Scanner

object Main extends App {
    val scanner = new Scanner(System.in)
    val S = scanner.next()
    println(S.count(x => x.toString() == "1"))
}