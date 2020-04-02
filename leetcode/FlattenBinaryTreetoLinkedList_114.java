public class FlattenBinaryTreetoLinkedList_114 {

  //  * Definition for a binary tree node.
  class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
  }

  class Solution {
    public void flatten(TreeNode root) {
      recursion(root);
    }

    public TreeNode recursion(TreeNode node) {
      if (node == null) {
        return null;
      }

      // * if the nodes is leaf node return the node
      if (node.left == null && node.right == null) {
        return node;
      }

      // * get the left leaf and right leaf
      TreeNode leftLeaf = recursion(node.left);
      TreeNode rightLeaf = recursion(node.right);

      // * if leftLeaf is null then tree already flattened; return rightLeaf;
      if (leftLeaf == null) {
        return rightLeaf;
      }

      TreeNode temp = node.right;

      // * merge the left flattened and right flattened tree
      node.right = node.left;
      node.left = null;
      leftLeaf.right = temp;

      // * if rightLeaf is null then the leaf node becomes leftLeaf
      if (rightLeaf == null) {
        return leftLeaf;
      }
      return rightLeaf;
    }
  }

  public static void main(String[] args) {}
}