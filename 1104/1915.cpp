#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n, m;
int data[1001][1001];
int dp[1001][1001];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%1d", &data[i][j]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (data[i][j] == 0) continue;
            dp[i][j] = 1;
            if (i == 0 || j == 0) continue;

            dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
        }

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ans = max(ans, dp[i][j] * dp[i][j]);

    printf("%d\n", ans);

    return 0;
}
