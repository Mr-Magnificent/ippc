package leetcode

func swap(nums []int, a, b int) {
	cur := nums[a]
	nums[a] = nums[b]
	nums[b] = cur
}

func sortColors(nums []int) {
	var b0, b2, cur int

	b2 = len(nums) - 1
	for cur <= b2 {
		switch nums[cur] {
		case 0:
			swap(nums, cur, b0)
			cur++
			b0++
		case 1:
			cur++
		case 2:
			swap(nums, cur, b2)
			b2--
		}
	}
}
