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
	var a [int(1e5 + 5)]int
	var visited [int(1e5 + 5)]bool

	fmt.Fscan(r, &n)

	for i := 1; i <= n; i++ {
		fmt.Fscan(r, &a[i])
	}

	visited[1] = true
	ans := 0
	now := 1

	for {
		ans++
		now = a[now]

		if now == 2 {
			fmt.Fprintln(w, ans)
			return
		} else if visited[now] {
			fmt.Fprintln(w, -1)
			return
		}
		visited[now] = true
	}

}
