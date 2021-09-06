import scala.io.StdIn._

object Main extends App {
  val Array(n, k) = readLine().split(' ').map(_.toInt)
  val d = readLine().split(' ').map(_.toInt)

  println(solve(n))

  def solve(num: Int): Int = {
    if (check(num, false)){
      solve(num + 1)
    }else{
      num
    }
  }

  def check(num: Int, flag: Boolean): Boolean = {
    if (num == 0){
      flag
    }else{
     check(num / 10, flag | d.contains(num % 10)) 
    }
  }

}
