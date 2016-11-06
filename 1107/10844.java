import java.util.*;
import java.lang.*;

public class Main {
    Scanner sc = new Scanner(System.in);
    int n;
    int[][] dp;
    final static int M = 1000000000;

    public void run()
    {
        n = sc.nextInt();
        dp = new int[n + 1][10];

        for (int i = 0; i < 10; i++)
            dp[1][i] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < 10; j++) {
                for (int k = j - 1; k <= j + 1; k += 2) {
                    if (k < 0 || k > 9) continue;
                    dp[i][j] = (dp[i][j] + dp[i-1][k]) % M;
                }
            }
        }

        int ans = 0;
        for (int i = 1; i < 10; i++)
            ans = (ans + dp[n][i]) % M;

        System.out.println(ans);
    }

    public static void main(String[] args)
    {
        new Main().run();
    }
}
