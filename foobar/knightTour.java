import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;

class Solution {
    
    public static int[][] dir = {{-2, 1}, {-1, 2}, {1, 2},   {2, 1},
    {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
    
    public static int solution(int src, int dest) {
        // use of bfs would be better than dfs
        boolean vis[][] = new boolean[8][8];
        Queue<Integer> que = new ArrayDeque<Integer>();
        
        que.add(src);
        int movesDist = 0;
        while (!que.isEmpty()) {
            int size = que.size();
            while (size-- > 0) {
                int idx = que.poll();
                if (idx == dest)
                return movesDist;
                int i = idx / 8, j = idx % 8;
                if (vis[i][j])
                continue;
                
                vis[i][j] = true;
                for (int itr = 0; itr < dir.length; ++itr) {
                    int r = i + dir[itr][0], c = j + dir[itr][1];
                    if (r < 0 || r >= 8 || c < 0 || c >= 8 || vis[r][c])
                    continue;
                    que.add((r * 8) + c);
                }
            }
            movesDist += 1;
        }
        return -1;
    }
    
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        String line;
        while ((line = scn.nextLine()) != null) {
            String[] arr = line.split(" ");
            int src = Integer.parseInt(arr[0]);
            int dest = Integer.parseInt(arr[1]);
            
            System.out.println(solution(src, dest));
        }
        scn.close();
    }
}