import java.io.*;
import java.util.*;

public class RankTeamsbyVotes_1366 {
  static class Solution {
    class Node implements Comparable<Node> {
      char ch;
      int[] pos;

      Node(char ch) {
        this.ch = ch;
        pos = new int[26];
      }

      @Override
      public int compareTo(Node other) {
        for (int i = 0; i < 26; i++) {
          if (this.pos[i] > other.pos[i]) {
            return -1;
          } else if (this.pos[i] < other.pos[i]) {
            return 1;
          }
        }

        if (this.ch < other.ch) {
          return -1;
        }
        return 1;
      }

      @Override
      public String toString() {
        StringBuilder str = new StringBuilder();
        str.append(this.ch);
        str.append("\n");
        for (int i = 0; i < 26; i++) {
          str.append(i + " " + this.pos[i] + "\n");
        }
        return str.toString();
      }
    }

    public String rankTeams(String[] votes) {

      Node[] arr = new Node[26];

      for(int i = 0; i < 26; i++) {
        arr[i] = new Node((char)(i + 'A'));
      }

      int length = votes[0].length();
      for (String str : votes) {
        for (int i = 0; i < length; i++) {
          int idx = str.charAt(i) - 'A';
          arr[idx].pos[i]++;
        }
      }

      Arrays.sort(arr);

      StringBuilder strBld = new StringBuilder(length);
      for (int i = 0; i < length; i++) {
        strBld.append(arr[i].ch);
      }

      return strBld.toString();
    }
  }

  public static String[] stringToStringArray(String line) {
    line = line.substring(2, line.length() - 2);
    String[] votes = line.split("\",\"");
    return votes;
  }

  public static void main(String[] args) throws IOException {
    // RankTeamsbyVotes_1366 obj = new RankTeamsbyVotes_1366();
    
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    String line;
    while ((line = in.readLine()) != null) {
      String[] votes = stringToStringArray(line);

      String ret = new RankTeamsbyVotes_1366.Solution().rankTeams(votes);

      String out = (ret);

      System.out.print(out);
    }
  }
}