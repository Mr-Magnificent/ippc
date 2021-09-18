package leetcode

import "math"

func movesToMakeZigzag(nums []int) int {
	var min1, min2 int

	if len(nums) == 1 {
		return 0
	}

	for i, x := range nums {
		if i%2 == 0 {
			switch i {
			case 0:
				if x < nums[i+1] {
					break
				}
				min1 += x - (nums[i+1] - 1)
			case len(nums) - 1:
				if x < nums[i-1] {
					break
				}
				min1 += x - (nums[i-1] - 1)
			default:
				if x < int(math.Min(float64(nums[i-1]), float64(nums[i+1]))) {
					break
				}
				min1 += x - (int(math.Min(float64(nums[i-1]), float64(nums[i+1]))) - 1)
			}
		} else {
			switch i {
			case len(nums) - 1:
				if x < nums[i-1] {
					break
				}
				min2 += x - (nums[len(nums)-2] - 1)
			default:
				if x < int(math.Min(float64(nums[i-1]), float64(nums[i+1]))) {
					break
				}
				min2 += x - (int(math.Min(float64(nums[i-1]), float64(nums[i+1]))) - 1)
			}
		}
	}

	return int(math.Min(float64(min1), float64(min2)))
}
