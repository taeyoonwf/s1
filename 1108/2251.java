import java.util.*;
import java.lang.*;

public class Main {
    Scanner sc = new Scanner(System.in);
    int[] capacity;
    boolean[][][] possible;

    int[] pour(int[] current, int from, int to)
    {
        int[] next = current.clone();
        if (current[from] < capacity[to] - current[to]) {
            next[to] += next[from];
            next[from] = 0;
        }
        else {
            next[from] -= capacity[to] - next[to];
            next[to] = capacity[to];
        }
        return next;
    }

    void search(int[] current)
    {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == j) continue;
                int[] next = pour(current, i, j);
                if (possible[next[0]][next[1]][next[2]] == false) {
                    possible[next[0]][next[1]][next[2]] = true;
                    search(next);
                }
            }
        }
    }

    public void run()
    {
        int a, b, c;
        a = sc.nextInt();
        b = sc.nextInt();
        c = sc.nextInt();

        capacity = new int[] {a, b, c};
        possible = new boolean[a + 1][b + 1][c + 1];

        possible[0][0][c] = true;
        search(new int[] {0, 0, c});

        TreeSet<Integer> ans = new TreeSet<>();
        for (int i = 0; i <= b; i++)
            for (int j = 0; j <= c; j++)
                if (possible[0][i][j])
                    ans.add(j);

        for (Integer value : ans)
            System.out.print(value + " ");
        System.out.println();
    }

    public static void main(String[] args)
    {
        new Main().run();
    }
}
