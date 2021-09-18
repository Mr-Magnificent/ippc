package leetcode

import "fmt"

var dir [][]int = [][]int{
	{0, 1},
	{1, 0},
	{0, -1},
	{-1, 0},
}

func colorBorder(grid [][]int, r0 int, c0 int, color int) [][]int {
	var deQueue []int = make([]int, 1)
	var vis [][]bool = make([][]bool, len(grid))

	for i := 0; i < len(grid); i++ {
		vis[i] = make([]bool, len(grid[0]))
	}

	glen := len(grid[0])

	deQueue = append(deQueue, r0*glen+c0)

	for len(deQueue) != 0 {
		isBoundary := true

		x := deQueue[0] / glen
		y := deQueue[0] % glen

		deQueue = deQueue[1:]

		if vis[x][y] {
			continue
		}

		vis[x][y] = true

		for _, v := range dir {
			x1 := x + v[0]
			y1 := y + v[1]

			if x1 < 0 && x1 >= len(grid) && y1 < 0 && y1 >= len(grid[0]) {
				continue
			}

			fmt.Printf("%v %v", x, y)
			if grid[x1][y1] != grid[x][y] {
				continue
			}

			isBoundary = false
			deQueue = append(deQueue, x1*glen+y1)
		}

		if x == 0 || y == 0 || x == len(grid)-1 || y == len(grid[0])-1 {
			isBoundary = true
		}

		if isBoundary {
			grid[x][y] = color
		}
	}
	return grid
}
