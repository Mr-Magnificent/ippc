package leetcode

func reverseNum(num int) (revNum int) {
	for num != 0 {
		revNum = (revNum * 10) + (num % 10)
		num /= 10
	}
	return
}

func countNicePairs(nums []int) int {
	var m map[int]int = make(map[int]int)
	var count int = 0

	for x := range nums {
		x = x + reverseNum(x)
		count += m[x]
		m[x] += 1
	}

	return count
}
