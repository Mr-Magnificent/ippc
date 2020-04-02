import java.io.InputStreamReader;
import java.lang.reflect.Constructor;
import java.util.*;

public class MergeTwoBalancedBinarySearchTrees {

  static class Node {
    int data;
    Node prev, next;
    Node(int d) {
      data = d;
      prev = next = null;
    }
  }

  static class Solution {}

  // ! convert integer array to BST
  static class Convert {
    int idx = 0;

    static Node convert(int[] arr, int left, int right) {
      if (left > right) {
        return null;
      }

      if (left == right) {
        return new Node(arr[idx++]);
      }

      int mid = (left + right) / 2;
      Node leftNode = convert(arr, left, mid - 1);

      Node node = new Node(arr[idx++]);

      Node rightNode = convert(arr, mid + 1, right);

      node.left = leftNode;
      node.right = rightNode;

      return node;
    }
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

  public static void main(String[] args) {
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    String line;
    while ((line = in.nextLine()) != null) {
      int[] arr1 = stringToIntegerArray(line);
      Node bst1 = Convert.convert(arr1, 0, arr1.length - 1);
    }
  }
}