import java.util.*;
import java.lang.*;

public class Main {
    Scanner sc = new Scanner(System.in);
    int n, m;
    int[][] dp;

    public void run()
    {
        n = sc.nextInt();
        m = sc.nextInt();
        dp = new int[n + 1][m + 1];

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i == 1 || j == 1) {
                    dp[i][j] = Math.max(i, j) - 1;
                    continue;
                }

                dp[i][j] = 234234234;
                for (int k = 1; k < Math.max(i, j); k++) {
                    if (k < i)
                        dp[i][j] = Math.min(dp[i][j], dp[k][j] + dp[i-k][j] + 1);
                    if (k < j)
                        dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[i][j-k] + 1);
                }
            }
        }
        System.out.println(dp[n][m]);
    }

    public static void main(String[] args)
    {
        new Main().run();
    }
}
