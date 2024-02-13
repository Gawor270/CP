package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

var scanner = bufio.NewScanner(os.Stdin)

func scanUint64() (int64, error) {
	scanner.Scan()
	return strconv.ParseInt(scanner.Text(), 10, 64)
}

func sol() {
	scanner.Split(bufio.ScanWords)
	n, _ := scanUint64()
	f := make([]int64, n)
	var dsum int64
	var _ int64
	for i := 0; i < int(n); i++ {
		f[i], _ = scanUint64()
		d, _ := scanUint64()
		dsum += d
	}
	sort.Slice(f, func(i, j int) bool { return f[i] < f[j] })
	for i := int64(0); i < n; i++ {
		dsum -= f[i] * (n - i)
	}
	fmt.Println(dsum)
}

func main() {
	tc := 1
	// fmt.Scan(&tc)
	for i := 0; i < tc; i++ {
		sol()
	}
}
