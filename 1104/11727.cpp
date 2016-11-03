#include<cstdio>
#include<cstring>

int n;
int dp[1001];
const int M = 10007;

int main()
{
    scanf("%d", &n);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = (dp[i-1] + dp[i-2] * 2) % M;

    printf("%d\n", dp[n]);

    return 0;
}
