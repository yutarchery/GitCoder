import scala.io.StdIn._

object Main extends App {
  println {
    readLine().reverse.map(c =>
      if (c == '6') '9'
      else if (c == '9') '6'
      else c
    )
  }
}
