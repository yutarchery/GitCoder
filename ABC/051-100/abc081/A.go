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

	var s string
	fmt.Fscan(r, &s)

	var count int = 0
	for i := 0; i < len(s); i++ {
		if s[i] == '1' {
			count++
		}
	}
	fmt.Fprintln(w, count)
}
