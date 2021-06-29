import java.util.Scanner

object Main extends App {
    val scanner = new Scanner(System.in)
    val N, A, B = scanner.nextInt()

    val nowSeq = (1 to N).map(value => value).toSeq

    val ans = nowSeq.foldLeft(0){ (res, value) =>
        if (check(value, A, B)) res + value
        else res
    }
    println(ans)

    def check(value: Int, a: Int, b: Int): Boolean = {
        val sum = digitSum(0, value)
        a <= sum && sum <= b
    }

    def digitSum(nowSum: Int, nowVal: Int): Int = {
        if (nowVal == 0){
            nowSum
        }else{
            digitSum(nowSum + nowVal % 10, nowVal / 10)
        }
    }
}