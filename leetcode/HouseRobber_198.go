package leetcode

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func rob(nums []int) int {
	take := 0
	leave := 0

	take = nums[0]
	for i := range nums {
		if i == 0 {
			continue
		}

		temp := take
		take = leave + nums[i]
		leave = max(leave, temp)
	}
	return max(leave, take)
}
