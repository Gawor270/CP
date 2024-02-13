package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

var scanner = bufio.NewScanner(os.Stdin)

func scanint64() (int64, error) {
	scanner.Scan()
	return strconv.ParseInt(scanner.Text(), 10, 64)
}

type Pair struct {
	First  int64
	Second int
}

type PairSlice []Pair

func (p PairSlice) Len() int {
	return len(p)
}

func (p PairSlice) Less(i, j int) bool {
	if p[i].First != p[j].First {
		return p[i].First < p[j].First
	}
	return p[i].Second < p[j].Second
}

func (p PairSlice) Swap(i, j int) {
	p[i], p[j] = p[j], p[i]
}

func sol() {
	scanner.Split(bufio.ScanWords)
	n, _ := scanint64()
	x, _ := scanint64()
	a := make(PairSlice, n)
	for i := range a {
		a[i].First, _ = scanint64()
		a[i].Second = i
	}
	sort.Sort(a)
	for i := range a {
		xval := x - a[i].First
		j := 0
		k := int(n) - 1
		for j < k {
			if xval-(a[j].First+a[k].First) > 0 {
				j++
			} else if xval-(a[j].First+a[k].First) < 0 {
				k--
			} else {
				if a[j].Second != a[i].Second && a[k].Second != a[i].Second {
					fmt.Println(a[i].Second+1, a[j].Second+1, a[k].Second+1)
					return
				}
				j++
			}
		}
	}
	fmt.Println(-1)

}

func main() {
	tc := 1
	// fmt.Scan(&tc)
	for i := 0; i < tc; i++ {
		sol()
	}
}
