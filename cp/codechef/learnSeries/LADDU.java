import java.util.Scanner;

class LADDU {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int t = scn.nextInt();
        while (t --> 0) {
            int n = scn.nextInt();
            String eth = scn.next();
            boolean isIndian = (eth.equals("INDIAN"));

            int score = 0;
            while (n --> 0) {
                String inp = scn.next();
                switch(inp) {
                    case "CONTEST_WON":
                    int rank = scn.nextInt();
                    score += 300 + ((rank <= 20) ? (20 - rank) : 0);
                    break;

                    case "TOP_CONTRIBUTOR":
                    score += 300;
                    break;

                    case "BUG_FOUND":
                    int sev = scn.nextInt();
                    score += sev;
                    break;

                    case "CONTEST_HOSTED":
                    score += 50;
                    break;
                }
            }
            System.out.println((isIndian) ? (score / 200) : (score / 400));
        }
    }
}
