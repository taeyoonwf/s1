#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<iostream>

using namespace std;

int n;
int dt[100001];
int dp[100001];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &dt[i]);

    dp[0] = dt[0];
    for (int i = 1; i < n; i++)
        dp[i] = max(dp[i - 1] + dt[i], dt[i]);

    int ans = -234234234;
    for (int i = 0; i < n; i++)
        ans = max(ans, dp[i]);
    printf("%d\n", ans);

    return 0;
}
