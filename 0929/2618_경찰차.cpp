#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<vector>

using namespace std;

int N, W;
int y[1005], x[1005];
int dp[1024][1024];
pair<int, int> from[1024][1024];

int main()
{
    scanf("%d%d", &N, &W);
    for (int i = 1; i <= W; i++)
        scanf("%d%d", &y[i], &x[i]);

    for (int i = 0; i < 1024; i++)
        for (int j = 0; j < 1024; j++)
            dp[i][j] = 234234234;

    dp[0][0] = 0;
    for (int i = 0; i < W; i++) { // start at (1, 1)
        for (int j = 0; j < W; j++) { // start at (N, N)
            int k = max(i, j) + 1;
            int x1, y1;
            int x2, y2;
            x1 = (i == 0) ? 1 : x[i];
            y1 = (i == 0) ? 1 : y[i];
            x2 = (j == 0) ? N : x[j];
            y2 = (j == 0) ? N : y[j];
            int dist1 = abs(y[k] - y1) + abs(x[k] - x1);
            int dist2 = abs(y[k] - y2) + abs(x[k] - x2);
            if (dp[k][j] > dp[i][j] + dist1) {
                dp[k][j] = dp[i][j] + dist1;
                from[k][j] = make_pair(i, j);
            }
            if (dp[i][k] > dp[i][j] + dist2) {
                dp[i][k] = dp[i][j] + dist2;
                from[i][k] = make_pair(i, j);
            }
        }
    }

    int ans = 234234234;
    int p, q;
    for (int i = 0; i < W; i++) {
        if (ans > dp[i][W]) {
            ans = dp[i][W];
            p = i, q = W;
        }
        if (ans > dp[W][i]) {
            ans = dp[W][i];
            p = W, q = i;
        }
    }

    printf("%d\n", ans);
    int last_p, last_q;
    vector<int> path;

    while (p > 0 || q > 0) {
        last_p = from[p][q].first;
        last_q = from[p][q].second;

        if (p != last_p)
            path.push_back(1);
        else
            path.push_back(2);

        // p = from[p][q].first;  (x)
        // q = from[p][q].second; (x)
        p = last_p;
        q = last_q;
    }
    reverse(path.begin(), path.end());
    for (auto p : path)
        printf("%d\n", p);
    return 0;
}
