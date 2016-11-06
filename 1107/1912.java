import java.util.*;
import java.lang.*;

public class Main {
    Scanner sc = new Scanner(System.in);
    int n;
    int[] data;
    int[] dp;

    public void run()
    {
        n = sc.nextInt();
        data = new int[n];
        for (int i = 0; i < n; i++)
            data[i] = sc.nextInt();

        dp = new int[n];
        dp[0] = data[0];
        for (int i = 1; i < n; i++)
            dp[i] = Math.max(data[i], dp[i-1] + data[i]);

        int ans = -234234234;
        for (int i = 0; i < n; i++)
            ans = Math.max(ans, dp[i]);

        System.out.println(ans);
    }

    public static void main(String[] args)
    {
        new Main().run();
    }
}
