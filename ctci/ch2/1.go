package main

func main() {
	ll := List{nil, 0}
	ll.PushFront(30)
	ll.Insert(40, 1)
	ll.Insert(10, 2)
	ll.Insert(20, 3)
	ll.Insert(50, 4)

	// var tail *Node = ll.head
	// for tail.next != nil {
	// 	tail = tail.next
	// }

	// t := Sort(&LlPtr{ll.head, tail})
	// ll.head = t.head
	// ll.Display()

	MergeSort(&ll).Display()
}
