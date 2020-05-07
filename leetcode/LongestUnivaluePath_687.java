import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import lib.*;

// import java.util.*;

public class LongestUnivaluePath_687 {
  /**
   * Definition for a binary tree node.
   */
  // static class TreeNode extends ConstructTree.TreeNode {
  //   TreeNode left;
  //   TreeNode right;
  //   TreeNode(int x) { super(x); }
  // }

  static class Solution {

    class StatusNode {
      public int value;
      public int count;

      StatusNode(int value, int count) {
        this.value = value;
        this.count = count;
      }
    }

    class Pair {
      public StatusNode prev;
      public StatusNode max;

      Pair(StatusNode prev, StatusNode max) {
        this.prev = prev;
        this.max = max;
      }
    }

    public int longestUnivaluePath(TreeNode root) {
      Pair node = helper(root);
      return node.max.count;
    }

    private Pair helper(TreeNode root) {

      if (root == null) {
        return null;
      }

      Pair left = helper(root.left);
      Pair right = helper(root.right);

      int myCount = 0;
      if (left != null && left.prev.value == root.val) {
        myCount = Math.max(left.prev.count + 1, myCount);
      }

      if (right != null && right.prev.value == root.val) {
        myCount = Math.max(right.prev.count + 1, myCount);
      }

      StatusNode currNodeVal = new StatusNode(root.val, myCount);
      
      Pair myPair = new Pair(currNodeVal, currNodeVal);

      if (left != null && left.max.count > myPair.max.count) {
        myPair.max = left.max;
      }

      if (right != null && right.max.count > myPair.max.count) {
        myPair.max = right.max;
      }

      return myPair;
    }
  }

  public static void main(String[] args) throws IOException {
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    String line;
    while ((line = in.readLine()) != null) {
      TreeNode node = ConstructTree.stringToTreeNode(line);
      System.out.println(new Solution().longestUnivaluePath(node));
    }
  }
}