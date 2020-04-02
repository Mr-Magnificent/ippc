import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


public class ConvertaBinaryTreetoaCircularDoublyLinkList {

  static class Node {
    int data;
    Node left, right;
    Node(int d) {
      data = d;
      left = right = null;
    }
  }

  static class Tree {

    Node bTreeToClist(Node root) {
      if (root == null) {
        return null;
      }

      Node leftLL = bTreeToClist(root.left);
      Node rightLL = bTreeToClist(root.right);

      if (leftLL != null && rightLL != null) {
        Node prev = leftLL.left;

        prev.right = root;
        root.left = prev;
        leftLL.left = rightLL.left;
        root.right = rightLL;
        rightLL.left.right = leftLL;
        rightLL.left = root;

        return leftLL;
      } else if (rightLL != null) {
        rightLL.left.right = root;
        root.left = rightLL.left;
        root.right = rightLL;
        rightLL.left = root;
        return root;
      } else if (leftLL != null) {
        leftLL.left.right = root;
        root.right = leftLL;
        root.left = leftLL.left;
        leftLL.left = root;
        return leftLL;
      } else {
        root.left = root;
        root.right = root;
        return root;
      }
    }
  }

  public static Node constructTree(String line) {
    line = line.substring(1, line.length() - 1);
    String[] nodeVal = line.split(",");

    if (nodeVal.length == 0) {
      return null;
    }

    Queue<Node> que = new LinkedList<Node>();
    Node root = null;
    for (int i = 0; i < nodeVal.length; i++) {
      if (i == 0) {
        root = new Node(Integer.parseInt(nodeVal[i]));
        que.add(root);
      } else {
        Node top = que.peek();
        if (nodeVal[i].equals("null") || nodeVal.equals("#")) {
          top.left = null;
        } else {
          Node node = new Node(Integer.parseInt(nodeVal[i]));
          top.left = node;
          que.add(node);
        }

        i += 1;
        if (i == nodeVal.length) {
          break;
        }

        if (nodeVal[i].equals("null") || nodeVal.equals("#")) {
          top.right = null;
        } else {
          Node node = new Node(Integer.parseInt(nodeVal[i]));
          top.right = node;
          que.add(node);
        }
        que.remove();
      }
    }
    return root;
  }

  public static void printCList(Node root) {
    Node temp = root.right;
    System.out.print(root.data + "->");
    while (temp != null && temp != root) {
      System.out.print(temp.data + "->");
      temp = temp.right;
    }

    temp = root.left;
    System.out.println();
    System.out.print(root.data + "<-");
    while (temp != null && temp != root) {
      System.out.print(temp.data + "<-");
      temp = temp.left;
    }
    System.out.println();
  }

  public static void main(String[] args) throws IOException {
    String line;
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    while ((line = in.readLine()) != null) {
      Node root = constructTree(line);
      Node cList = new Tree().bTreeToClist(root);
      printCList(cList);
    }
  }
}