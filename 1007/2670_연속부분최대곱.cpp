#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int n;
double data[10001];
double dp[10001];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lf", &data[i]);

    dp[0] = data[0];
    for (int i = 1; i < n; i++)
        dp[i] = max(data[i], dp[i-1] * data[i]);

    double ans = -1;
    for (int i = 0; i < n; i++)
        ans = max(ans, dp[i]);

    printf("%.3lf\n", ans);
    return 0;
}
