import java.util.*;
import java.lang.*;

public class Main {
    class State
    {
        int r, c;

        State(int r, int c)
        {
            this.r = r;
            this.c = c;
        }
    }

    Scanner sc = new Scanner(System.in);
    int n, m;
    String data[];
    int[][] steps;
    final int r_dir[] = {-1, 0, 1, 0};
    final int c_dir[] = {0, 1, 0, -1};

    boolean movable(int r, int c)
    {
        if (r < 0 || r >= n || c < 0 || c >= m)
            return false;
        return data[r].charAt(c) == '1';
    }

    public void run()
    {
        n = sc.nextInt();
        m = sc.nextInt();
        data = new String[n];
        for (int i = 0; i < n; i++)
            data[i] = sc.next();

        steps = new int[n][m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                steps[i][j] = 234234234;

        Queue<State> q = new LinkedList<>();
        steps[0][0] = 1;
        q.offer(new State(0, 0));

        while (!q.isEmpty()) {
            State cur = q.poll();
            int step = steps[cur.r][cur.c];
            for (int i = 0; i < 4; i++) {
                State next = new State(cur.r + r_dir[i], cur.c + c_dir[i]);

                if (!movable(next.r, next.c))
                    continue;
                if (steps[next.r][next.c] > step + 1) {
                    steps[next.r][next.c] = step + 1;
                    q.offer(next);
                }
            }
        }

        System.out.println(steps[n - 1][m - 1]);
    }

    public static void main(String[] args)
    {
        new Main().run();
    }
}
