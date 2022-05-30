package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	r := bufio.NewReader(os.Stdin)
	w := bufio.NewWriter(os.Stdout)
	defer w.Flush()

	var n int
	var a [200]int

	fmt.Fscan(r, &n)
	for i := 0; i < n; i++ {
		fmt.Fscan(r, &a[i])
	}

	res := a[0]
	for i := 1; i < n; i++ {
		res = gcd(res, a[i])
	}

	ans := 0
	for {
		if res%2 != 0 {
			break
		} else {
			ans++
			res /= 2
		}
	}

	fmt.Fprintln(w, ans)

}

func gcd(a int, b int) int {
	if a < b {
		return gcd(b, a)
	} else if a%b == 0 {
		return b
	} else {
		return gcd(b, a%b)
	}
}
