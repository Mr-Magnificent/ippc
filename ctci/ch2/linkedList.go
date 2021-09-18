package main

import "fmt"

type Node struct {
	data int
	next *Node
}

type List struct {
	head *Node
	len  int
}

type LinkedList interface {
	Insert(loc, val int) int
	Erase(val int) *Node
}

func (ll *List) Insert(val, loc int) int {
	if loc > ll.len {
		return -1
	}

	if ll.head == nil {
		ll.head = &Node{val, nil}
		ll.len = 1
		return 1
	}

	var ptr *Node = ll.head
	for i := 1; i < loc; i += 1 {
		ptr = ptr.next
	}

	node := Node{val, nil}
	node.next = ptr.next
	ptr.next = &node
	ll.len += 1
	return 1
}

func (ll *List) Erase(val int) *Node {
	var indirect **Node = &ll.head

	for *indirect != nil && (*indirect).data != val {
		indirect = &(*indirect).next
	}

	if *indirect == nil {
		return nil
	}

	var next *Node = *indirect
	*indirect = (*indirect).next
	ll.len -= 1
	return next
}

func (ll *List) PushFront(val int) int {
	return ll.Insert(val, 0)
}

func mergeLists(h1, h2 *Node) (head *Node) {
	var ptr *Node

	for h1 != nil && h2 != nil {
		if ptr == nil {
			if h1.data < h2.data {
				head, ptr = h1, h1
			} else {
				head, ptr = h2, h2
			}
		} else {
			if h1.data < h2.data {
				ptr.next, h1 = h1, h1.next
				ptr = ptr.next
			} else {
				ptr.next, h2 = h2, h2.next
				ptr = ptr.next
			}
		}
	}

	for h1 != nil {
		ptr.next, h1 = h1, h1.next
		ptr = ptr.next
	}

	for h1 != nil {
		ptr.next, h1 = h1, h1.next
		ptr = ptr.next
	}

	return
}

func MergeSort(ll *List) *List {
	if ll.head == nil {
		return &List{ll.head, 0}
	}

	if ll.head.next == nil {
		return &List{ll.head, 1}
	}

	var slow, fast **Node
	slow = &ll.head
	var count int = 0

	for fast = &(*ll.head).next.next; *fast != nil && (*fast).next != nil; fast, slow, count = &(*fast).next.next, &(*slow).next, count+1 {
	}

	var head2 *Node = *slow
	*slow = nil
	h1 := MergeSort(&List{head: ll.head, len: count})
	h2 := MergeSort(&List{head: head2, len: ll.len - count})

	return &List{mergeLists(h1.head, h2.head), ll.len}
}

type LlPtr struct {
	head *Node
	tail *Node
}

func Sort(ll *LlPtr) (newLLPtr *LlPtr) {
	if ll == nil || ll.head == ll.tail {
		return ll
	}

	pivot := ll.head
	var ll1 *LlPtr = &LlPtr{nil, nil}
	var ll2 *LlPtr = &LlPtr{nil, nil}

	for ptr := ll.head.next; ; {
		next := ptr.next
		if ptr.data < pivot.data {
			if ll1.head == nil {
				ll1 = &LlPtr{ptr, ptr}
			} else {
				ll1.tail.next, ll1.tail = ptr, ptr
			}
			ll1.tail.next = nil
		} else {
			if ll2.head == nil {
				ll2 = &LlPtr{ptr, ptr}
			} else {
				ll2.tail.next, ll2.tail = ptr, ptr
			}
			ll2.tail.next = nil
		}

		if ptr == ll.tail {
			break
		}
		ptr = next
	}

	if ll1.head == nil {
		rightLLPtr := Sort(ll2)
		ll.head.next = rightLLPtr.head
		newLLPtr = &LlPtr{ll.head, rightLLPtr.tail}
	} else {
		leftLLPtr := Sort(ll1)
		rightLLPtr := Sort(ll2)
		leftLLPtr.tail.next = ll.head
		ll.head.next = rightLLPtr.head
		newLLPtr = &LlPtr{leftLLPtr.head, rightLLPtr.tail}
	}
	return newLLPtr
}

func (ll *List) Display() {
	ptr := ll.head
	for ptr != nil {
		fmt.Println(ptr.data)
		ptr = ptr.next
	}
}

// func main() {
// 	ll := List{nil, 0}
// 	ll.PushFront(30)
// 	ll.Insert(40, 1)
// 	ll.Insert(10, 2)
// 	ll.Insert(20, 3)
// 	ll.Insert(50, 4)

// 	var tail *Node = ll.head
// 	for tail.next != nil {
// 		tail = tail.next
// 	}

// 	t := Sort(&LlPtr{ll.head, tail})
// 	ll.head = t.head
// 	ll.Display()
// }
