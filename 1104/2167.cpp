#include<cstdio>
#include<cstring>

int n, m;
int data[301][301];
int sum[301][301];

int rectangle(int r1, int c1, int r2, int c2)
{
    return sum[r2][c2] - sum[r1-1][c2] - sum[r2][c1-1] + sum[r1-1][c1-1];
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &data[i][j]);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            sum[i][j] = data[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            sum[i][j] += sum[i][j-1];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            sum[i][j] += sum[i-1][j];

    int K;
    scanf("%d", &K);
    while (K--) {
        int r1, c1, r2, c2;
        scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
        printf("%d\n", rectangle(r1, c1, r2, c2));
    }

    return 0;
}
