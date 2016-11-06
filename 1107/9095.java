import java.util.*;
import java.lang.*;

public class Main {
    Scanner sc = new Scanner(System.in);
    int n;
    int[] dp;

    public void run()
    {
        dp = new int[11];
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= 10; i++)
            dp[i] = dp[i-3] + dp[i-2] + dp[i-1];

        int cases = sc.nextInt();
        while (cases-- > 0) {
            n = sc.nextInt();
            System.out.println(dp[n]);
        }
    }

    public static void main(String[] args)
    {
        new Main().run();
    }
}
