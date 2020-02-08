package lib;

public class Node {
  public int data;
  public int hd;
  public Node left;
  public Node right;

  public Node(int val) {
    this.data = val;
    this.left = null;
    this.right = null;
  }

  public Node(int val, Node left, Node right) {
    this.data = val;
    this.left = left;
    this.right = right;
  }

  public Node() {}
}