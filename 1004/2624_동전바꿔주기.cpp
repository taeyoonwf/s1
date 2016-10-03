#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<iostream>

using namespace std;

int T;
int n;
int cost[1001];
int num[1001];
int dp[10001];

int main()
{
    scanf("%d", &T);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &cost[i], &num[i]);

    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = T - 1; j >= 0; j--) {
            if (dp[j] == 0) continue;
            for (int k = 1; k <= num[i]; k++) {
                if (j + cost[i] * k > T) continue;
                dp[j + cost[i] * k] += dp[j];
            }
        }
    }

    printf("%d\n", dp[T]);
    return 0;
}
