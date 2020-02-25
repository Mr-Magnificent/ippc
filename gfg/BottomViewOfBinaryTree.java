import java.io.*;
import java.util.*;
import lib.Node;
import lib.ConstructTree;

class BottomView {

  static public void bottomView(Node root) {
    Queue<Node> que = new LinkedList<>();
    Map<Integer, Integer> map = new HashMap<>();
    int minVal = 0;
    root.hd = 0;
    que.add(root);

    while (!que.isEmpty()) {
      int size = que.size();
      while (size-- > 0) {
        Node rmNode = que.poll();
        map.put(rmNode.hd, rmNode.data);
        minVal = Math.min(minVal, rmNode.hd);

        if (rmNode.left != null) {
          rmNode.left.hd = rmNode.hd - 1;
          que.add(rmNode.left);
        }
        if (rmNode.right != null) {
          rmNode.right.hd = rmNode.hd + 1;
          que.add(rmNode.right);
        }
      }
    }


    while(map.containsKey(minVal)) {
      System.out.print(map.get(minVal) + " ");
      minVal++;
    }
    System.out.println();
  }

  public static void main(String[] args) throws IOException {
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

    String line;

    while ((line = in.readLine()) != null) {
      Node root = ConstructTree.stringToTreeNode(line);
      bottomView(root);
    }
  }
}