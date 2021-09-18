package leetcode

// func expressiveWords(S string, words []string) (ans int) {
// 	for _, word := range words {
// 		isExpressive := true
// 		if word[0] != S[0] {
// 			isExpressive = false
// 		}

// 		ptr := 1
// 		count := 0
// 		for i := 1; i < len(S); i++ {
// 			if S[i] == word[ptr] {
// 				continue
// 			}

// 			if ptr != len(word) && word[ptr-1] == S[i] {
// 				for i < len(S) && word[ptr-1] == S[i] {
// 					count++
// 					i++
// 				}
// 				if count < 3 {
// 					isExpressive = false
// 				}
// 				count = 0
// 			} else if ptr == len(word) {
// 				for i < len(S) && word[ptr-1] == S[i] {
// 					count++
// 					i++
// 				}
// 				if count < 3 || i != len(S) {
// 					isExpressive = false
// 				}
// 				count = 0
// 			} else if word[ptr-1] != S[i] {
// 				isExpressive = false
// 				break
// 			}
// 		}

// 		if isExpressive {
// 			ans++
// 		}
// 	}

// 	return
// }

func expressiveWords(S string, words []string) (count int) {
	for _, word := range words {
		isExpressive := true
		i := 0
		j := 0

		for i < len(S) && j < len(word) {
			if S[i] != word[j] {
				isExpressive = false
				break
			}

			ci := countRepeating(S, i)
			cj := countRepeating(word, j)

			if ci != cj && (cj > ci || ci < 3) {
				isExpressive = false
				break
			}

			i += ci
			j += cj
		}

		if isExpressive && i == len(S) && j == len(word) {
			count++
		}
	}
	return
}

func countRepeating(S string, idx int) (count int) {
	for i := idx; i < len(S) && S[i] == S[idx]; i++ {
		count++
	}
	return
}
