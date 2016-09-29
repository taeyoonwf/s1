#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<iostream>

using namespace std;

int n;
int data[1005][3];
int dp[1005][3];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            scanf("%d", &data[i][j]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            dp[i][j] = 234234234;

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            dp[i][0] = data[i][0];
            dp[i][1] = data[i][1];
            dp[i][2] = data[i][2];
            continue;
        }
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + data[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + data[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + data[i][2];
    }

    int ans = min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
    printf("%d\n", ans);
    return 0;
}
