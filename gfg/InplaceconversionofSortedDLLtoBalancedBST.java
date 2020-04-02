import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class InplaceconversionofSortedDLLtoBalancedBST {
  static class Node {
    int data;
    Node prev, next;
    Node(int d) {
      data = d;
      prev = next = null;
    }
  }

  // ! ====== solution ==========
  static class Solution {
    Node itr = null;

    // ! returns the count of the DLL
    public int countLength(Node head) {
      Node temp = head;
      int count = 0;
      while (temp != null) {
        count++;
        temp = temp.next;
      }
      return count;
    }

    // ! actual function called from psvm
    public Node convert(Node head) {
      // * initially count the length of the DLL
      int length = countLength(head);
      itr = head;
      Node root = recursion(1, length);
      return root;
    }

    // ! ======= function doing actual conversion
    public Node recursion(int left, int right) {
      // * incase the limits are overstepped return null
      if (left > right) {
        return null;
      }

      // * only when left == right then 1 node needs to be created
      if (left == right) {
        Node temp = itr;
        itr = itr.next;

        // * prepare the leaf node
        temp.next = null;
        temp.prev = null;
        return temp;
      }

      int mid = (int)Math.ceil((left + right) / 2);

      Node leftNode = recursion(left, mid - 1);

      // * get the next value for the current node
      Node temp = itr;
      itr = itr.next;

      Node rightNode = recursion(mid + 1, right);

      // * the values in leftNode and rightNode are the children
      temp.prev = leftNode;
      temp.next = rightNode;

      return temp;
    }
  }

  // ! helper function to construct Doubly Linked List
  static Node constructDLL(int[] arr) {
    if (arr.length == 0) {
      return null;
    }

    Node root = null;
    Node tail = null;
    for (int i = 0; i < arr.length; i++) {
      if (i == 0) {
        root = tail = new Node(arr[i]);
      } else {
        Node node = new Node(arr[i]);
        node.prev = tail;
        tail.next = node;
        tail = node;
      }
    }

    return root;
  }

  // ! create string to integer Array
  static int[] stringToIntegerArray(String line) {
    if (line.equals("[]")) {
      return new int[0];
    }

    line = line.substring(1, line.length() - 1);
    String[] arrItems = line.split(",");

    int[] items = Arrays.stream(arrItems)
                      .mapToInt(item -> Integer.parseInt(item))
                      .toArray();
    return items;
  }

  // ! function to print the result
  public static void printTree(Node root) {
    if (root == null) {
      return;
    }

    System.out.print(root.data + " :");
    if (root.prev != null) {
      System.out.print(root.prev.data + ", ");
    } else {
      System.out.print("null, ");
    }

    if (root.next != null) {
      System.out.print(root.next.data + ", ");
    } else {
      System.out.print("null, ");
    }
    System.out.println();

    printTree(root.prev);
    printTree(root.next);
  }

  // ! ====== main =========
  public static void main(String[] args) throws IOException {
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    String line = null;
    while ((line = in.readLine()) != null) {
      int[] arr = stringToIntegerArray(line);
      Node head = constructDLL(arr);

      Node root = new Solution().convert(head);
      printTree(root);
    }
  }
}
