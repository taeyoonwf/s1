import java.util.*;
import java.lang.*;

public class Main {
    class State
    {
        int r, c, smash;

        State(int r, int c, int smash)
        {
            this.r = r;
            this.c = c;
            this.smash = smash;
        }
    }

    Scanner sc = new Scanner(System.in);
    int n, m, max_smash;
    String data[];
    int[][][] steps;
    final int r_dir[] = {-1, 0, 1, 0};
    final int c_dir[] = {0, 1, 0, -1};

    boolean movable(int r, int c)
    {
        if (r < 0 || r >= n || c < 0 || c >= m)
            return false;
        return true;
    }

    public void run()
    {
        n = sc.nextInt();
        m = sc.nextInt();
        max_smash = sc.nextInt();
        data = new String[n];
        for (int i = 0; i < n; i++)
            data[i] = sc.next();

        steps = new int[n][m][max_smash + 1];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                for (int k = 0; k < max_smash + 1; k++)
                    steps[i][j][k] = 234234234;

        Queue<State> q = new LinkedList<>();
        steps[0][0][0] = 1;
        q.offer(new State(0, 0, 0));

        while (!q.isEmpty()) {
            State cur = q.poll();
            int step = steps[cur.r][cur.c][cur.smash];
            for (int i = 0; i < 4; i++) {
                State next = new State(cur.r + r_dir[i], cur.c + c_dir[i], cur.smash);

                if (!movable(next.r, next.c))
                    continue;
                next.smash = cur.smash + (data[next.r].charAt(next.c) == '1' ? 1 : 0);
                if (next.smash > max_smash)
                    continue;
                if (steps[next.r][next.c][next.smash] > step + 1) {
                    steps[next.r][next.c][next.smash] = step + 1;
                    q.offer(next);
                }
            }
        }

        int ans = 234234234;
        for (int i = 0; i <= max_smash; i++)
            ans = Math.min(ans, steps[n - 1][m - 1][i]);
        System.out.println(ans);
    }

    public static void main(String[] args)
    {
        new Main().run();
    }
}
