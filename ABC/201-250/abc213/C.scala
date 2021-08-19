import scala.io.StdIn._
import scala.collection.mutable

object Main extends App {
  val Array(h, w, n) = readLine().split(" ").map(_.toInt)

  val a = new Array[Int](n)
  val b = new Array[Int](n)

  (0 until n).foreach { i =>
    val Array(ai, bi) = readLine().split(" ").map(_.toInt)
    a(i) = ai
    b(i) = bi
  }

  val sortedA = a.sorted.distinct
  val aMap = mutable.Map[Int, Int]()
  (0 until sortedA.length).foreach { i =>
    aMap += (sortedA(i) -> (i + 1))
  }

  val sortedB = b.sorted.distinct
  val bMap = mutable.Map[Int, Int]()
  (0 until sortedB.length).foreach { i =>
    bMap += (sortedB(i) -> (i + 1))
  }

  (0 until n).foreach { i =>
    val ans = Seq(aMap(a(i)), bMap(b(i)))
    println(ans.mkString(" "))
  }
}
