#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n;
int data[201];
int dp[201];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &data[i]);

    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
            if (dp[i] < dp[j] + 1 && data[i] > data[j])
                dp[i] = dp[j] + 1;
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, dp[i]);

    printf("%d\n", n - ans);

    return 0;
}
