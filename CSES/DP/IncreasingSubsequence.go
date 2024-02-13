package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var scanner = bufio.NewScanner(os.Stdin)

func scanint64() (int64, error) {
	scanner.Scan()
	return strconv.ParseInt(scanner.Text(), 10, 64)
}

func lowerBound(slice []int64, value int64) int {
	left, right := 0, len(slice)
	for left < right {
		mid := (left + right) / 2
		if slice[mid] < value {
			left = mid + 1
		} else {
			right = mid
		}
	}
	return left
}

func sol() {
	scanner.Split(bufio.ScanWords)
	n, _ := scanint64()
	var x int64
	var dp []int64
	for i := int64(0); i < n; i++ {
		x, _ = scanint64()
		lb := lowerBound(dp, x)
		if lb == len(dp) {
			dp = append(dp, x)
		} else {
			dp[lb] = x
		}
	}
	fmt.Println(len(dp))
}

func main() {
	tc := 1
	for i := 0; i < tc; i++ {
		sol()
	}
}
