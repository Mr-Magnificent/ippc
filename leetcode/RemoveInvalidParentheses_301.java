import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

public class RemoveInvalidParentheses_301 {
  static class Solution {
    public List<String> removeInvalidParentheses(String s) {
      return solution_bfs(s);
      // if (lst.size() == 0) {
      //     return new ArrayList<String>(Arrays.asList(""));
      // } else {
      //     return lst;
      // }
    }

    //         public  void solution(String str, int minRemoval, HashSet <
    //         String > ans) {
    //         //write your code here
    //         if (minRemoval == 0) {
    //             if (isValid(str) && !ans.contains(str)) {
    //                 System.out.println(str);
    //                 ans.add(str);
    //             }
    //             return;
    //         }

    //         for (int i = 0; i < str.length(); ++i) {
    //             String remStr = str.substring(0, i) + str.substring(i + 1);
    //             solution(remStr, minRemoval - 1, ans);
    //         }
    //     }

    // public static solution_subseq(String str, String ans, HashSet<string>
    // ans, int totalLen) {
    //     if (str.length() == 0) {
    //         if (ans.length() == totalLen - minRemoval && ) {

    //         }

    //         return;
    //     }
    // }

    private List<String> solution_bfs(String str) {
      HashSet<String> hs = new HashSet<>();

      List<String> lst = new ArrayList<>();
      Queue<String> que = new ArrayDeque<>();

      que.add(str);

      boolean found = false;

      while (!que.isEmpty()) {
        int size = que.size();

        while (size-- > 0) {
          String temp = que.poll();
          if (hs.contains(temp)) continue;
          if (isValid(temp)) {
            lst.add(temp);
            hs.add(temp);
            found = true;
            continue;
          }

          for (int i = 0; i < temp.length(); ++i) {
            String remStr = temp.substring(0, i) + temp.substring(i + 1);
            que.offer(remStr);
          }
        }
        if (found)
          break;
      }
      return lst;
    }

    private int getMin(String str) {
      // write your code here
      int count = 0;
      int stackptr = 0;
      for (int i = 0; i < str.length(); ++i) {
        char ch = str.charAt(i);
        if (ch == '(') {
          stackptr++;

        } else if (ch == ')') {
          if (stackptr == 0) {
            count++;
          } else {
            stackptr--;
          }
        }
      }

      return count + stackptr;
    }

    private boolean isValid(String str) {
      int count = 0;
      for (int i = 0; i < str.length(); ++i) {
        char ch = str.charAt(i);
        if (ch == '(') {
          count++;
        } else if (ch == ')') {
          count--;
        }

        if (count < 0)
          return false;
      }

      return count == 0;
    }
  }

  public static void main(String[] args) {
    Scanner scn = new Scanner(System.in);
    String line;
    while (!(line = scn.nextLine()).equals("EOF")) {
      System.out.println(new Solution().removeInvalidParentheses(line));
    }
    scn.close();
  }
}