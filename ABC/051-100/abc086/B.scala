import java.util.Scanner

object Main extends App {
  val scanner = new Scanner(System.in)

  val A, B = scanner.nextInt()
  val num = makeNumber(A, B)
  val sqrtNum = math.sqrt(num).toInt

  if (sqrtNum * sqrtNum == num) {
    println("Yes")
  } else {
    println("No")
  }

  def makeNumber(a: Int, b: Int): Int = {
    val digitB = digitCount(b)
    a * math.pow(10, digitB).toInt + b
  }

  def digitCount(num: Int): Int = {
    if (num == 0) {
      0
    } else {
      digitCount(num / 10) + 1
    }
  }
}
