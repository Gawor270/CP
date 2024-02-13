package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func check(a []uint64, thre, target uint64) bool {
	var count uint64
	for _, v := range a {
		count += thre / v
		if count >= target {
			return true
		}
	}
	return count >= target
}

func sol() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	var n, t uint64
	scanner.Scan()
	n, _ = strconv.ParseUint(scanner.Text(), 10, 64)
	scanner.Scan()
	t, _ = strconv.ParseUint(scanner.Text(), 10, 64)

	k := make([]uint64, n)
	for i := range k {
		scanner.Scan()
		k[i], _ = strconv.ParseUint(scanner.Text(), 10, 64)
	}

	var l uint64
	var r uint64 = 1e18
	for r-l > 1 {
		var m uint64 = l + (r-l)/2
		if check(k, m, t) {
			r = m
		} else {
			l = m
		}
	}
	fmt.Println(r)
}

func main() {
	tc := 1
	// fmt.Scan(&tc)
	for i := 0; i < tc; i++ {
		sol()
	}
}
