import java.util.Scanner

object Main extends App {
  val scanner = new Scanner(System.in)
  val A, B = scanner.nextInt()
  val W = scanner.nextInt() * 1000

  val ansMax = W / A
  val ansMin = (W - 1) / B + 1

  if (ansMin > ansMax){
    println("UNSATISFIABLE")
  }else{
    println(List(ansMin, ansMax).mkString(" "))
  }
}
