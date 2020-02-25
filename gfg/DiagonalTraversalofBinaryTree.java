import java.io.*;
import java.util.*;
import lib.ConstructTree;
import lib.Node;

class DiagonalTraversal {

  static class Pair {
    Node node;
    int hd;

    Pair(Node node, int hd) {
      this.node = node;
      this.hd = hd;
    }
  }

  static public void diagonalPrint(Node root) {
    // add your code here.
    Queue<Pair> que = new LinkedList<>();
    Map<Integer, ArrayList<Integer>> map = new HashMap<>();
    que.add(new Pair(root, 0));

    int min = 0;

    while (!que.isEmpty()) {
      int size = que.size();

      while (size-- > 0) {
        Pair rmNode = que.poll();

        min = Math.min(rmNode.hd, min);

        if (map.containsKey(rmNode.hd)) {
          map.get(rmNode.hd).add(rmNode.node.data);
        } else {
          map.put(rmNode.hd, new ArrayList<>(Arrays.asList(rmNode.node.data)));
        }

        if (rmNode.node.left != null) {
          que.add(new Pair(rmNode.node.left, rmNode.hd - 1));
        }

        if (rmNode.node.right != null) {
          que.add(new Pair(rmNode.node.right, rmNode.hd));
        }
      }
    }

    for (int i = 0; i >= min; i--) {
      for (int el : map.get(i)) {
        System.out.print(el + " ");
      }
    }
  }

  public static void main(String[] args) throws IOException {
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    String line;
    while ((line = in.readLine()) != null) {
      Node root = ConstructTree.stringToTreeNode(line);
      diagonalPrint(root);
    }
  }
}