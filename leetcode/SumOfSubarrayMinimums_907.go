package leetcode

type Array []int

const MOD int = 1e9 + 7

type Stack interface {
	Top() int
	Push()
	Pop()
	Empty() bool
	Len() int
}

func (s *Array) Len() int {
	return len(*s)
}

func (s *Array) Top() int {
	if s.Len() == 0 {
		panic("Empty array")
	}

	return (*s)[s.Len()-1]
}

func (s *Array) Push(num int) {
	*s = append(*s, num)
}

func (s *Array) Pop() {
	if s.Len() == 0 {
		panic("Empty array")
	}

	*s = (*s)[:s.Len()-1]
}

func (s *Array) Empty() bool {
	return s.Len() == 0
}

func sumSubarrayMins(arr []int) int {
	stk := Array{}
	left := make([]int, len(arr))
	for i, x := range arr {
		for !stk.Empty() && arr[stk.Top()] > x {
			stk.Pop()
		}

		if stk.Empty() {
			left[i] = -1
		} else {
			left[i] = stk.Top()
		}

		stk.Push(i)
	}

	stk = Array{}
	right := make([]int, len(arr))
	for i := len(arr) - 1; i >= 0; i-- {
		for !stk.Empty() && arr[stk.Top()] >= arr[i] {
			stk.Pop()
		}

		if stk.Empty() {
			right[i] = len(arr)
		} else {
			right[i] = stk.Top()
		}

		stk.Push(i)
	}

	var count int = 0
	for i := range left {
		count = (count + (((i-left[i])*(right[i]-i))*arr[i])%MOD) % MOD
	}
	return count
}

// https://zoom.us/j/7768646280?pwd=MEZLN2s1Tm1RY2kyWjRnVTY0bktWQT09
// https://zoom.us/j/94472764660?pwd=ZVI1ZnBBdit4eWpjTzdMVVpVMnlqUT09
