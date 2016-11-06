import java.util.*;
import java.lang.*;

public class Main {
    Scanner sc = new Scanner(System.in);
    int n;
    int[] data;
    int[][] dp;

    public void run()
    {
        n = sc.nextInt();
        data = new int[n];
        for (int i = 0; i < n; i++)
            data[i] = sc.nextInt();

        dp = new int[n][3];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < 3; j++)
                dp[i][j] = -234234234;

        dp[0][0] = 0;
        dp[0][1] = data[0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (j == 0 && k > 0)
                        dp[i][j] = Math.max(dp[i][j], dp[i-1][k]);
                    else if (j == k + 1)
                        dp[i][j] = Math.max(dp[i][j], dp[i-1][k] + data[i]);
                }
            }
        }

        int ans = 0;
        for (int i = 1; i < 3; i++)
            ans = Math.max(ans, dp[n-1][i]);
        System.out.println(ans);
    }

    public static void main(String[] args)
    {
        new Main().run();
    }
}
