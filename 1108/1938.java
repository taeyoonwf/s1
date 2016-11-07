import java.util.*;
import java.lang.*;

public class Main {
    class State
    {
        int r, c;
        boolean vertical;

        State(int r, int c, boolean vertical)
        {
            this.r = r;
            this.c = c;
            this.vertical = vertical;
        }
    }

    Scanner sc = new Scanner(System.in);
    int n;
    String data[];
    int[][][] steps;
    final int r_dir[] = {-1, 0, 1, 0};
    final int c_dir[] = {0, 1, 0, -1};

    boolean movable(int r, int c, boolean vertical)
    {
        if (vertical) {
            if (r - 1 < 0 || r + 1 >= n || c < 0 || c >= n)
                return false;
            if (data[r - 1].charAt(c) == '1' ||
                data[r + 0].charAt(c) == '1' ||
                data[r + 1].charAt(c) == '1')
                return false;
        }
        else { // horizontal
            if (r < 0 || r >= n || c - 1 < 0 || c + 1 >= n)
                return false;
            if (data[r].charAt(c - 1) == '1' ||
                data[r].charAt(c + 0) == '1' ||
                data[r].charAt(c + 1) == '1')
                return false;
        }
        return true;
    }

    boolean rotatable(int r, int c)
    {
        if (r - 1 < 0 || r + 1 >= n || c - 1 < 0 || c + 1 >= n)
            return false;

        for (int i = r - 1; i <= r + 1; i++)
            for (int j = c - 1; j <= c + 1; j++)
                if (data[i].charAt(j) == '1')
                    return false;
        return true;
    }

    State findStick(char what)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (data[i].charAt(j) == what) {
                    if (i + 1 < n && data[i + 1].charAt(j) == what)
                        return new State(i + 1, j, true);
                    if (j + 1 < n && data[i].charAt(j + 1) == what)
                        return new State(i, j + 1, false);
                }

        return new State(-1, -1, false);
    }

    public void run()
    {
        n = sc.nextInt();
        data = new String[n];
        for (int i = 0; i < n; i++)
            data[i] = sc.next();

        steps = new int[n][n][2];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                steps[i][j][0] = 234234234;
                steps[i][j][1] = 234234234;
            }

        State begin = findStick('B');
        State end = findStick('E');

        Queue<State> q = new LinkedList<>();
        steps[begin.r][begin.c][begin.vertical ? 1 : 0] = 0;
        q.offer(begin);

        while (!q.isEmpty()) {
            State cur = q.poll();
            int step = steps[cur.r][cur.c][cur.vertical ? 1 : 0];
            for (int i = 0; i < 4; i++) {
                State next = new State(cur.r + r_dir[i], cur.c + c_dir[i], cur.vertical);
                if (!movable(next.r, next.c, next.vertical))
                    continue;

                if (steps[next.r][next.c][next.vertical ? 1 : 0] > step + 1) {
                    steps[next.r][next.c][next.vertical ? 1 : 0] = step + 1;
                    q.offer(next);
                }
            }
            if (rotatable(cur.r, cur.c)) {
                State next = new State(cur.r, cur.c, !cur.vertical);
                if (steps[next.r][next.c][next.vertical ? 1 : 0] > step + 1) {
                    steps[next.r][next.c][next.vertical ? 1 : 0] = step + 1;
                    q.offer(next);
                }
            }
        }

        int ans = steps[end.r][end.c][end.vertical ? 1 : 0];
        System.out.println((ans < 234234234 ? ans : 0));
    }

    public static void main(String[] args)
    {
        new Main().run();
    }
}
