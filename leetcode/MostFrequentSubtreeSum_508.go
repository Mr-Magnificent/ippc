package leetcode

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func findFrequentTreeSum(root *TreeNode) []int {
	myMap := make(map[int]int)
	dfs(root, &myMap)

	ans := make([]int, 0)
	curMax := 0
	for k, v := range myMap {
		if v == curMax {
			ans = append(ans, k)
		} else if v > curMax {
			ans = nil
			ans = append(ans, k)
			curMax = v
		}
	}
	return ans
}

func dfs(node *TreeNode, myMap *map[int]int) int {
	if node == nil {
		return 0
	}

	sum := dfs(node.Left, myMap) + dfs(node.Right, myMap) + node.Val
	(*myMap)[sum]++
	return sum
}
