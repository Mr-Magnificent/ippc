package leetcode

// func longestSubarray(nums []int, limit int) (ans int) {
// 	var i, j int

// 	// we will try to maximize j - i
// 	for minv, maxv := 0, 0; i < len(nums) && j < len(nums); {
// 		maxv, minv = updatev(nums, maxv, minv, j)
// 		maxv, minv = updatev(nums, maxv, minv, i)
// 		if nums[maxv]-nums[minv] <= limit {
// 			ans = max(ans, j-i)
// 			j++
// 		} else {
// 			i++
// 		}
// 	}
// 	return
// }

// func updatev(nums []int, maxv int, minv int, idx int) (int, int) {
// 	if nums[maxv] < nums[idx] {
// 		maxv = idx
// 	}

// 	if nums[minv] > nums[idx] {
// 		minv = idx
// 	}

// 	return maxv, minv
// }

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

type ArrayDequeue []int

func (deq *ArrayDequeue) Push_back(x int) {
	*deq = append(*deq, x)
}

func (deq *ArrayDequeue) Push_front(x int) {
	temp := append([]int{}, x)
	*deq = append(*deq, temp...)
}

func (deq *ArrayDequeue) Pop_back() int {
	temp := (*deq)[len(*deq)-1]
	*deq = (*deq)[:len(*deq)-1]
	return temp
}

func (deq *ArrayDequeue) Pop_front() int {
	temp := (*deq)[len(*deq)-1]
	*deq = (*deq)[1:]
	return temp
}

func (deq *ArrayDequeue) Front() int {
	return (*deq)[0]
}

func (deq *ArrayDequeue) Back() int {
	return (*deq)[len(*deq)-1]
}

func (deq *ArrayDequeue) Empty() bool {
	return len(*deq) == 0
}

func longestSubarray(nums []int, limit int) (ans int) {
	var maxd *ArrayDequeue = new(ArrayDequeue)
	var mind *ArrayDequeue = new(ArrayDequeue)

	i, j := 0, 0
	for _, x := range nums {
		for !maxd.Empty() && nums[maxd.Back()] < x {
			maxd.Pop_back()
		}
		for !mind.Empty() && nums[mind.Back()] > x {
			mind.Pop_back()
		}

		maxd.Push_back(j)
		mind.Push_back(j)

		for nums[maxd.Front()]-nums[mind.Front()] > limit {
			if i == maxd.Front() {
				maxd.Pop_front()
			}
			if i == mind.Front() {
				mind.Pop_front()
			}
			i++
		}
		ans = max(ans, j-i+1)
	}
	return
}
