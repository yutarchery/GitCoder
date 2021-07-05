import java.util.Scanner

object Main extends App {
  val scanner = new Scanner(System.in)
  val N = scanner.nextLong()
  val K = scanner.nextInt()

  val ans = (1 to K).foldLeft(N){ (result, i) =>
    f(result)
  }
  println(ans)

  def f(num: Long): Long = {
    g1(num) - g2(num)
  }
  def g1(num: Long): Long = {
    num.toString().sortBy(v => v).reverse.toLong
  }
  def g2(num: Long): Long = {
    num.toString().sortBy(v => v).toLong
  }
}
