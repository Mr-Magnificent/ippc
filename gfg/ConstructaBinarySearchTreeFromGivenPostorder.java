import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class ConstructaBinarySearchTreeFromGivenPostorder {
  // * node class
  static class Node {
    int data;
    Node left, right;
    Node(int d) {
      data = d;
      left = right = null;
    }
  }

  static class Solution {
    private int n = 0;

    Solution(int n) {
      this.n = n;
    }

    public Node constructTree(int post[], int n) {
      Node root = constructTreeHelper(post, Integer.MIN_VALUE, Integer.MAX_VALUE);
      return root;
    }

    public Node constructTreeHelper(int post[], int start, int end) {
      if ( n ==  -1 || post[n] < start || post[n] > end) {
        return null;
      }

      int val = post[n];
      Node node = new Node(post[n]);
      n = n - 1;

      node.right = constructTreeHelper(post, val, end);
      node.left = constructTreeHelper(post, start, val);

      return node;
    }
  }

  public static void printTree(Node node) {
    if (node == null) {
      return;
    }

    System.out.print(node.data + ": ");
    if (node.left != null) {
      System.out.print(node.left.data + ", ");
    } else {
      System.out.print("null, ");
    }

    if (node.right != null) {
      System.out.println(node.right.data + ", ");
    } else {
      System.out.println("null, ");
    }

    printTree(node.left);
    printTree(node.right);
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    String line;
    while ((line = br.readLine())  != null) {
      int[] arr = Arrays.stream(line.split(" ")).mapToInt(Integer::parseInt).toArray();

      Node root = new Solution(arr.length - 1).constructTree(arr, arr.length - 1);
      printTree(root);
    }
  }
}