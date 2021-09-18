package leetcode

func maximum69Number(num int) int {
	dig := 1000
	for dig != 0 {
		if (num/dig)%(dig*10) == 6 {
			return num + 3*dig
		}
	}
	return num
}

func Log10(x int) int {
	count := 0
	for ; x >= 10; count, x = count+1, x/10 {
	}
	return count
}
