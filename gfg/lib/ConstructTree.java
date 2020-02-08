package lib;
import java.util.Queue;
import java.util.LinkedList;

public class ConstructTree {
  public static Node stringToTreeNode(String str) {
    String input = str.trim();
    input = str.substring(1, str.length() - 1);

    if (input.length() == 0) {
      return null;
    }

    String[] parts = input.split(",");
    String item = parts[0];

    Queue<Node> que = new LinkedList<>();
    Node root = new Node(Integer.parseInt(item));
    que.add(root);

    int ind = 1;
    while (!que.isEmpty()) {
      Node rmNode = que.poll();

      if (ind == parts.length) {
        break;
      }

      item = parts[ind++];
      item = item.trim();
      if (!item.equals("null")) {
        Node left = new Node(Integer.parseInt(item));
        rmNode.left = left;
        que.add(left);
      }

      if (ind == parts.length) {
        break;
      }

      item = parts[ind++];
      item = item.trim();
      if (!item.equals("null")) {
        Node right = new Node(Integer.parseInt(item));
        rmNode.right = right;
        que.add(right);
      }
    }
    return root;
  }
}