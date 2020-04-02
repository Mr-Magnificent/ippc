import java.util.*;

class ListinBinaryTree_1367 {

  //  Definition for singly-linked list.
  class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
  }

  //  Definition for a binary tree node.
  class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
  }

  // !=============================================
 

  class Solution {
    ArrayList<Integer> prefix;
    int idxStart = 0;
    int idxEnd = 0;

    void calculatePrefix(ListNode head) {
      
    }

    public boolean isSubPath(ListNode head, TreeNode root) {
      calculatePrefix(head);
      return true;
    }
  }

  public static void main(String[] args) {

  }
}