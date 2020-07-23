import java.util.*;

class test {
  public static void main(String[] args) {
    Scanner scn = new Scanner(System.in);
    int n = scn.nextInt();
    int ans = 0;

    int[] arr = new int[n];

    for (int i = 0; i < n; ++i) {
      arr[i] = scn.nextInt();
      if (arr[i] > 0)
        ans++;
    }

    int min = Integer.MAX_VALUE;
    for (int i = 0; i < arr.length; ++i) {
      if (arr[i] < min && arr[i] != 0) {
        min = arr[i];
      }
    }

    int logVal = log2(min);
    ans += logVal;

    int lim = 1 << logVal;

    for (int i = 0; i < arr.length; ++i) {
      ans += Math.max(arr[i] - lim, 0);
    }

    System.out.println(ans);
  }

  public static int log2(int num) {
    int count = 0;
    for (; num > 1; count++, num >>>= 1)
      ;
    return count;
  }
}

// yeh paste karna

class t {
  public static int playTheGame(int[] target) {
    int ans = 0;
    int min = Integer.MAX_VALUE;
    for (int i = 0; i < target.length; ++i) {
      if (target[i] < min && target[i] != 0) {
        min = target[i];
      }
    }

    int logVal = log2(min);
    ans += logVal;

    int lim = 1 << logVal;

    for (int i = 0; i < target.length; ++i) {
      ans += Math.max(target[i] - lim, 0);
    }

    return ans;
  }

  public static int log2(int num) {
    int count = 0;
    for (; num > 1; count++, num >>>= 1)
      ;
    return count;
  }
}