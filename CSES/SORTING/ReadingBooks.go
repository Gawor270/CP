package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var scanner = bufio.NewScanner(os.Stdin)

func scanUint64() (int64, error) {
	scanner.Scan()
	return strconv.ParseInt(scanner.Text(), 10, 64)
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func sol() {
	scanner.Split(bufio.ScanWords)
	n, _ := scanUint64()
	t := make([]int64, n)
	var sum int64
	var maxim int64
	for i := range t {
		t[i], _ = scanUint64()
		sum += t[i]
		maxim = max(maxim, t[i])
	}
	fmt.Println(max(sum, 2*maxim))
}

func main() {
	tc := 1
	// fmt.Scan(&tc)
	for i := 0; i < tc; i++ {
		sol()
	}
}
