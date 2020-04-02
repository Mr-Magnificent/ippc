import java.util.*;
import lib.*;

public class BinaryTreeLongestConsecutiveSequence_298 {

  //  Definition of TreeNode:
  public class TreeNode {
    public int val;
    public TreeNode left, right;
    public TreeNode(int val) {
      this.val = val;
      this.left = this.right = null;
    }
  }

  class Solution {
    /**
     * @param root: the root of binary tree
     * @return: the length of the longest consecutive sequence path
     */

    int maxVal = 0;

    public int longestConsecutive(TreeNode root) {
      // write your code here
      this.maxVal = 0;
      func(root);
      return maxVal;
    }

    public int func(TreeNode root) {
      if (root == null) {
        return 0;
      }

      int left = longestConsecutive(root.left);
      int right = longestConsecutive(root.right);

      System.out.println(left + " " + right + "--");
      if (root.left != null && (root.val - root.left.val) == -1) {
        left++;
      } else {
        left = 1;
      }

      if (root.right != null && (root.val - root.right.val) == -1) {
        right++;
      } else {
        right = 1;
      }

      System.out.println(left + " " + right + "***");
      // System.out.println(this.maxVal);
      // maxVal = Math.max(maxVal, Math.max(left, right));

      if (maxVal < Math.max(left, right)) {
        this.maxVal = Math.max(left, right);
        // this.value = root.val;
        // System.out.println(root.val + " " + maxVal + " " + left + " " +
        // right);
      }
      // System.out.println(left + " " + right);
      // return Math.max(left, right);
      if (left > right) {
        System.out.println(left + "L");
        return left;
      }
      System.out.println(right + "R");
      return right;
    }
  }


  public static void main(String[] args) {
    String line;
    Scanner scn = new Scanner(System.in);
    String tree = scn.nextLine();
  }
}