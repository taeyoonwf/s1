import java.util.*;
import java.lang.*;

public class Main {
    Scanner sc = new Scanner(System.in);
    int n;
    double[] data;
    double[] dp;

    public void run()
    {
        n = sc.nextInt();
        data = new double[n];
        for (int i = 0; i < n; i++)
            data[i] = sc.nextDouble();

        dp = new double[n];
        dp[0] = data[0];
        for (int i = 1; i < n; i++)
            dp[i] = Math.max(data[i], dp[i-1] * data[i]);

        double ans = 0;
        for (int i = 0; i < n; i++)
            ans = Math.max(ans, dp[i]);

        System.out.printf("%.3f\n", ans);
    }

    public static void main(String[] args)
    {
        new Main().run();
    }
}
