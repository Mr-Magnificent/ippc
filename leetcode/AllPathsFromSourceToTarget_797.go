package leetcode

func allPathsSourceTarget(graph [][]int) (ans [][]int) {
	vis := make([]bool, len(graph))
	ans = make([][]int, 0)

	asf := []int{}

	dfs(&graph, 0, &vis, &ans, &asf)
	return ans
}

func dfs(graph *[][]int, src int, vis *[]bool, ans *[][]int, asf *[]int) {

	if src == len(*graph)-1 {
		*asf = append(*asf, src)
		dup := make([]int, len(*asf))
		copy(dup, *asf)
		*ans = append(*ans, dup)
		*asf = (*asf)[:len(*asf)-1]
		return
	}

	(*vis)[src] = true

	*asf = append(*asf, src)

	for _, nbr := range (*graph)[src] {
		if (*vis)[nbr] {
			continue
		}

		dfs(graph, nbr, vis, ans, asf)
	}

	*asf = (*asf)[:len(*asf)-1]
	(*vis)[src] = false
}
