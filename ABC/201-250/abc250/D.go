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

	var n int64
	fmt.Fscan(r, &n)

	var primes = []int64{2}
	for i := int64(3); i <= int64(1e6) && i <= n; i += 2 {
		if judgePrime(i) {
			primes = append(primes, i)
		}
	}

	var ans int = 0

	for i := 0; i < len(primes); i++ {
		rest := calcTriple(n/primes[i], 1, int64(1e6+1))

		if rest <= primes[i] {
			break
		}

		l := i
		r := len(primes)

		for {
			if r-l == 1 {
				break
			}

			mid := (l + r) / 2

			if primes[mid] <= rest {
				l = mid
			} else {
				r = mid
			}
		}
		ans += l - i
	}

	fmt.Fprintln(w, ans)

}

func judgePrime(n int64) bool {
	for i := int64(2); i*i <= n; i++ {
		if n%i == 0 {
			return false
		}
	}
	return true
}

func calcTriple(n int64, l int64, r int64) int64 {
	if l+1 == r {
		return l
	}

	mid := (l + r) / 2
	if mid*mid*mid <= n {
		return calcTriple(n, mid, r)
	} else {
		return calcTriple(n, l, mid)
	}
}
