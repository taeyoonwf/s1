import java.util.*;
import java.lang.*;

public class Main {
    Scanner sc = new Scanner(System.in);
    int n;

    int[] f(int n)
    {
        int[] result = new int[10];

        while (n > 0 && n % 10 != 9) {
            int t = n;
            while (t > 0) {
                result[t % 10]++;
                t /= 10;
            }
            n--;
        }

        if (n == 0) return result;

        int[] div10 = f(n / 10);
        for (int i = 0; i < 10; i++)
            result[i] += div10[i] * 10 + (n / 10) + 1;
        result[0]--;

        return result;
    }

    public void run()
    {
        n = sc.nextInt();
        int[] ans = f(n);

        for (int i = 0; i < 10; i++)
            System.out.print(ans[i] + " ");
        System.out.println();
    }

    public static void main(String[] args)
    {
        new Main().run();
    }
}
