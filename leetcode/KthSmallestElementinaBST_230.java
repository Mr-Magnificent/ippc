import java.io.*;
import lib.TreeNode;
import lib.ConstructTree;

class KthSmallestElement {

  static class Solution {
    public int kthSmallest(TreeNode root, int k) { 
      if (root.left != null) {
        kthSmallest(root.left, k);
      }
      System.out.println(root.val);

      if (root.right != null) {
        kthSmallest(root.right, k);
      }
      return k;
     }
  }

  public static void main(String[] args) throws IOException {
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    String line;
    while ((line = in.readLine()) != null) {
      TreeNode root = ConstructTree.stringToTreeNode(line);
      line = in.readLine();
      int k = Integer.parseInt(line);
      
      int ret = new Solution().kthSmallest(root, k);
      String out = String.valueOf(ret);
      System.out.println(out);
    }
  }
}