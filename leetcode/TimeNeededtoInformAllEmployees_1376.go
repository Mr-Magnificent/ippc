package leetcode

type Person struct {
	Num        int
	InformTime int
	Emp        []*Person
}

func NewPerson(num, informTime int) *Person {
	var p *Person = &Person{num, informTime, make([]*Person, 0)}
	return p
}

func numOfMinutes(n int, headID int, manager []int, informTime []int) int {
	var emp []*Person = make([]*Person, 0)

	for i := 1; i <= n; i++ {
		emp = append(emp, NewPerson(i, informTime[i]))
	}

	for i, x := range manager {
		if i == headID {
			continue
		}
		emp[x].Emp = append(emp[x].Emp, emp[i])
	}

	return dfs(emp[headID])
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func dfs(node *Person) int {
	if node == nil || len(node.Emp) == 0 {
		return 0
	}

	ans := 0
	for _, emp := range node.Emp {
		ans = max(ans, dfs(emp))
	}

	return ans + node.InformTime
}
