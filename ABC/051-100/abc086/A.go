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

	var a, b int
	fmt.Fscan(r, &a, &b)

	if a*b%2 == 0 {
		fmt.Fprintln(w, "Even")
	} else {
		fmt.Fprintln(w, "Odd")
	}
}
