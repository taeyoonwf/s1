#include<cstdio>
#include<cstring>

#define M 10007

int dp[1005];

int main()
{
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= 1000; i++)
        dp[i] = (dp[i-2] + dp[i-1]) % M;

    int n;
    scanf("%d", &n);
    printf("%d\n", dp[n]);

    return 0;
}
