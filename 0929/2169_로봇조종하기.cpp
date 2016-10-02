#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>

using namespace std;

int n, m;
int data[1005][1005];
int dp[1005][1005][3];
bool cache[1005][1005][3];

// 0 from up
// 1 from left
// 2 from right

int solve(int i, int j, int from)
{
    int& ret = dp[i][j][from];
    if (cache[i][j][from])
        return ret;

    ret = -234234234;
    int& here = data[i][j];
    if (i == 0 && j == 0 && from < 2)
        ret = here;
    if (from == 0 && i - 1 >= 0) {
        ret = max(ret, solve(i-1, j, 0) + here);
        ret = max(ret, solve(i-1, j, 1) + here);
        ret = max(ret, solve(i-1, j, 2) + here);
    }
    if (from == 1 && j - 1 >= 0) {
        ret = max(ret, solve(i, j-1, 0) + here);
        ret = max(ret, solve(i, j-1, 1) + here);
    }
    if (from == 2 && j + 1 < m) {
        ret = max(ret, solve(i, j+1, 0) + here);
        ret = max(ret, solve(i, j+1, 2) + here);
    }
    cache[i][j][from] = true;
    return ret;
}

void test()
{
    printf("100 1000\n");
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 1000; j++) {
            printf("%d ", -100 + rand() % 200);
        }
        printf("\n");
    }
}

int main()
{
    //test();
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &data[i][j]);

    printf("%d\n", max(solve(n-1, m-1, 0), solve(n-1, m-1, 1)));
    return 0;
}
