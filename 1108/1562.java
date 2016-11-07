import java.util.*;
import java.lang.*;

public class Main {
    Scanner sc = new Scanner(System.in);
    int n;
    int[][][] dp;
    final int M = 1000000000;

    public void run()
    {
        n = sc.nextInt();
        dp = new int[n + 1][10][1024];

        for (int i = 0; i < 10; i++)
            dp[1][i][1 << i] = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 10; j++) {
                for (int k = j - 1; k <= j + 1; k += 2) {
                    if (k < 0 || k > 9) continue;
                    for (int state = 0; state < 1024; state++) {
                        int next = state | (1 << k);
                        dp[i + 1][k][next] += dp[i][j][state];
                        dp[i + 1][k][next] %= M;
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 1; i < 10; i++)
            ans = (ans + dp[n][i][1023]) % M;
        System.out.println(ans);
    }

    public static void main(String[] args)
    {
        new Main().run();
    }
}
