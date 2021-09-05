import scala.io.StdIn._

object Main extends App {
  val Array(s, t) = readLine().split(" ")
  if (s < t){
    println("Yes")
  }else{
    println("No")
  }
}
