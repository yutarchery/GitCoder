import scala.io.StdIn._

object Main extends App {
  val s = readLine()

  val ans = (0 until (1 << (s.length() - 1))).foldLeft(0l){(acc, rest) => 
    val info = Info(0, (s(0) - '0').toLong)
    acc + solve(info, 1, rest)  
  }

  println(ans)

  def solve(info: Info, index: Int, rest: Int): Long = {
    if (index == s.length()){
      info.sum + info.num
    }else if (rest % 2 == 0){
      val nextInfo = Info(info.sum + info.num, (s(index) - '0').toLong)
      solve(nextInfo, index + 1, rest / 2)
    }else{
      val nextInfo = Info(info.sum, info.num * 10 + (s(index) - '0').toLong)
      solve(nextInfo, index + 1, rest / 2)
    }
  }
}

case class Info(
    sum: Long,
    num: Long
)
