#include<cstdio>

int n, k;
int bino[1005][1005];
const int M = 10007;

int main()
{
    bino[0][0] = 1;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j <= i; j++) {
            bino[i+1][j]   = (bino[i+1][j] + bino[i][j]) % M;
            bino[i+1][j+1] = (bino[i+1][j+1] + bino[i][j]) % M;
        }
    }

    scanf("%d%d", &n, &k);
    printf("%d\n", bino[n][k]);

    return 0;
}
