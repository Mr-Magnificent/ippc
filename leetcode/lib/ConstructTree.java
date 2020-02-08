package lib;
import java.util.Queue;
import java.util.LinkedList;

public class ConstructTree {
  public static TreeNode stringToTreeNode(String str) {
    String input = str.trim();
    input = str.substring(1, str.length() - 1);

    if (input.length() == 0) {
      return null;
    }

    String[] parts = input.split(",");
    String item = parts[0];

    Queue<TreeNode> que = new LinkedList<>();
    TreeNode root = new TreeNode(Integer.parseInt(item));
    que.add(root);

    int ind = 1;
    while (!que.isEmpty()) {
      TreeNode rmNode = que.poll();

      if (ind == parts.length) {
        break;
      }

      item = parts[ind++];
      item = item.trim();
      if (!item.equals("null")) {
        TreeNode left = new TreeNode(Integer.parseInt(item));
        rmNode.left = left;
        que.add(left);
      }

      if (ind == parts.length) {
        break;
      }

      item = parts[ind++];
      item = item.trim();
      if (!item.equals("null")) {
        TreeNode right = new TreeNode(Integer.parseInt(item));
        rmNode.right = right;
        que.add(right);
      }
    }
    return root;
  }
}