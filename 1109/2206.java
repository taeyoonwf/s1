import java.util.*;
import java.lang.*;

public class Main {
    class State
    {
        int r, c;
        boolean smash;

        State(int r, int c, boolean smash)
        {
            this.r = r;
            this.c = c;
            this.smash = smash;
        }
    }

    Scanner sc = new Scanner(System.in);
    int n, m;
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
        data = new String[n];
        for (int i = 0; i < n; i++)
            data[i] = sc.next();

        steps = new int[n][m][2];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                steps[i][j][0] = 234234234;
                steps[i][j][1] = 234234234;
            }

        Queue<State> q = new LinkedList<>();
        steps[0][0][0] = 1;
        q.offer(new State(0, 0, false));

        while (!q.isEmpty()) {
            State cur = q.poll();
            int step = steps[cur.r][cur.c][cur.smash ? 1 : 0];
            for (int i = 0; i < 4; i++) {
                State next = new State(cur.r + r_dir[i], cur.c + c_dir[i], cur.smash);

                if (!movable(next.r, next.c))
                    continue;
                if (cur.smash && data[next.r].charAt(next.c) == '1')
                    continue;
                next.smash = cur.smash | data[next.r].charAt(next.c) == '1';
                if (steps[next.r][next.c][next.smash ? 1 : 0] > step + 1) {
                    steps[next.r][next.c][next.smash ? 1 : 0] = step + 1;
                    q.offer(next);
                }
            }
        }

        int ans = Math.min(steps[n - 1][m - 1][0], steps[n - 1][m - 1][1]);
        System.out.println(ans);
    }

    public static void main(String[] args)
    {
        new Main().run();
    }
}
