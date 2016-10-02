#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int dp[32][1<<6];

int main()
{
    int n;
    scanf("%d", &n);

    if (n % 2) {
        printf("0\n");
        return 0;
    }

    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int state = 0; state < 1 << 6; state++) {
            //printf("%d %d\n", i, state);
            int& cur = dp[i][state];
            if ((state & 1) == 0) {
                if ((state &  2) == 0) dp[i][state | 3] += cur;
                if ((state &  8) == 0) dp[i][state | 9] += cur;
            }
            else if ((state & 2) == 0) {
                if ((state &  4) == 0) dp[i][state | 6] += cur;
                if ((state & 16) == 0) dp[i][state | 18] += cur;
            }
            else if ((state & 4) == 0) {
                if ((state & 32) == 0) dp[i][state | 36] += cur;
            }
        }
        for (int state = 0; state < 1 << 6; state++)
            if ((state & 7) == 7)
                dp[i+1][state >> 3] = dp[i][state];
    }

    printf("%d\n", dp[n][0]);
    return 0;
}
