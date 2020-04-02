import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class MinimumWindowSubstring_76 {
  
  static class Solution {
    public String minWindow(String s, String t) {
      HashMap<Character, Integer> tmap = new HashMap<>();

      // * put all the chars of t in tmap hashmap
      for (int i = 0; i < t.length(); i++) {
        tmap.put(t.charAt(i), tmap.getOrDefault(t.charAt(i), 0) + 1);
      }

      // * maintain a matched count and substring start position and end
      // * position
      int matchedCount = 0;
      int matchedStartIdx = 0;
      int matchedEndIdx = -1;

      int start = 0;

      HashMap<Character, Integer> sMap = new HashMap<>();

      /**
       * * What we are trying to do is aggressively trying to shrink the start
       * * of the window
       *
       * * We create a hm for string s (sMap) which contains count of valid
       * * characters we have seen
       *
       * * MatchedCount is maintained which maintains how many valid characters
       * * have been matched currently
       *
       * * Whenever we get a character that is valid, we put it in sMap with
       * * sMap[curCh] = sMap[curCh] + 1
       *
       * * Now we check if it is okay to leave the start Character (stCh)
       * * because of update by checking if stCh is valid or if the count of
       * * stCh is greater in sMap than in tmap. If any of both case we can
       * * increment start character.
       *
       * * After shrinking start if the matchedCount == t.length() then
       * * this is a valid answer, update answer if previous answer longer
       */

      for (int i = 0; i < s.length(); i++) {
        char curCh = s.charAt(i);
        char stCh = s.charAt(start);

        // * check if curCh is a valid character
        if (tmap.containsKey(curCh)) {
          // * Update the curCh with one increment
          sMap.put(curCh, sMap.getOrDefault(curCh, 0) + 1);
          // * check if need to increase matchedCount
          if (sMap.get(curCh) <= tmap.get(curCh)) {
            matchedCount++;
          }

          // * actively try to shrink start. If not valid or if excess
          // * start character, increment start
          while (!tmap.containsKey(stCh) || sMap.get(stCh) > tmap.get(stCh)) {
            // * if shrink was valid char, then decrement in sMap
            if (sMap.containsKey(stCh)) {
              sMap.replace(stCh, sMap.get(stCh) - 1);
            }

            start++;
            stCh = s.charAt(start);
          }

          // * update the result
          if (matchedCount == t.length()) {
            if (matchedEndIdx == -1 ||
                (i - start) < (matchedEndIdx - matchedStartIdx)) {
              matchedStartIdx = start;
              matchedEndIdx = i;
            }
          }
        }
        // * otherwise we don't care
      }

      if (matchedEndIdx != -1) {
        return s.substring(matchedStartIdx, matchedEndIdx + 1);
      }
      return "";
    }
  }

  public static void main(String[] args) throws IOException {
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    String line;
    while ((line = in.readLine()) != null) {
      String S = line.substring(1, line.length() - 1);
      line = in.readLine();
      String T = line.substring(1, line.length() - 1);

      String result = new Solution().minWindow(S, T);
      System.out.println(result);
    }
  }
}