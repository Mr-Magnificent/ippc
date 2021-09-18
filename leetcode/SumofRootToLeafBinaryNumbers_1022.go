package leetcode

//  * Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func sumRootToLeaf(root *TreeNode) int {
	return helper(root, 0)
}

func helper(root *TreeNode, num int) int {

	if root == nil {
		return num
	}
	num = num<<1 + root.Val
	return helper(root.Left, num) + helper(root.Right, num)
}
