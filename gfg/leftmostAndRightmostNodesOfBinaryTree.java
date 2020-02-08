import java.util.*;

class TreeNode {
  int val;
  TreeNode left;
  TreeNode right;

  TreeNode(TreeNode left, TreeNode right, int val) {
    this.val = val;
    this.left = left;
    this.right = right;
  }
}

class Tree {
  static void leftMostAndRightmost(TreeNode root) {
    Queue<TreeNode> que = new LinkedList<>();
    que.add(root);
    while (!que.isEmpty()) {
      int size = que.size();
      System.out.print(que.peek().val);
      while (size-- > 1) {
        TreeNode node = que.poll();
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
