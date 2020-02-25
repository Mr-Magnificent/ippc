import java.util.*;

class Node {
  int val;
  int hd;
  Node left;
  Node right;

  Node(Node left, Node right, int val) {
    this.val = val;
    this.left = left;
    this.right = right;
  }
}

class Tree {
  static void leftMostAndRightmost(Node root) {
    Queue<Node> que = new LinkedList<>();
    que.add(root);
    while (!que.isEmpty()) {
      int size = que.size();
      System.out.print(que.peek().val);
      while (size-- > 1) {
        Node node = que.poll();
        if (node.left != null) {
          que.add(node.left);
        }
        if (node.right != null) {
          que.add(node.right);
        }
      }
      System.out.print(que.poll().val);
    }
  }

  public static void main(String[] args) {
    
  }
}
