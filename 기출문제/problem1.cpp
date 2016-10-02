#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define M 1000000007

struct point {
    int y, x;

    bool operator<(const point& p) const
    {
        if (y != p.y) return y < p.y;
        return x < p.x;
    }
};

int n;
point data[2001];
int dp[2001];

int main()
{
    int T;
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d%d", &data[i].y, &data[i].x);
        sort(data + 1, data + n - 1);

        for (int i = 0; i < n; i++)
            dp[i] = 0;
        dp[0] = 1;

        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) {
                if (data[i].y >= data[j].y || data[i].x >= data[j].x)
                    continue;
                dp[j] = (dp[i] + dp[j]) % M;
            }

        printf("%d\n", dp[n-1]);
    }
    return 0;
}
