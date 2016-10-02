#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define M 1000000007

int n;
int data[200001];
int fullR[200001];
int fullL[200001];
int oneR[200001];
int oneL[200001];

int main()
{
    int T;
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &data[i]);

        for (int i = 0; i < n; i++)
            fullR[i] = fullL[i] = oneR[i] = oneL[i] = 0;

        fullR[n - 1] = max(data[n - 1], 0);
        for (int i = n - 2; i >= 0; i--)
            fullR[i] = max(fullR[i + 1] + data[i], 0);
        fullL[0] = max(data[0], 0);
        for (int i = 1; i < n; i++)
            fullL[i] = max(fullL[i - 1] + data[i], 0);

        oneR[n - 1] = max(data[n - 1], 0);
        for (int i = n - 2; i >= 0; i--)
            oneR[i] = max(fullR[i + 1], oneR[i + 1] + data[i]);
        oneL[0] = max(data[0], 0);
        for (int i = 1; i < n; i++)
            oneL[i] = max(fullL[i - 1], oneL[i - 1] + data[i]);

        /*
        for (int i = 0; i < n; i++) printf("%d ", fullR[i]); printf("\n");
        for (int i = 0; i < n; i++) printf("%d ", fullL[i]); printf("\n");
        for (int i = 0; i < n; i++) printf("%d ", oneR[i]); printf("\n");
        for (int i = 0; i < n; i++) printf("%d ", oneL[i]); printf("\n");
        */
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int full_l = (i == 0)   ? 0 : fullL[i - 1];
            int full_r = (i == n-1) ? 0 : fullR[i + 1];
            int one_l  = (i == 0)   ? 0 : oneL[i - 1];
            int one_r  = (i == n-1) ? 0 : oneR[i + 1];

            int best = max(full_l + full_r, max(full_l + one_r, one_l + full_r)) + data[i];
            best %= M;

            ans = (ans + best) % M;
        }
        printf("%d\n", ans);
    }
    return 0;
}
