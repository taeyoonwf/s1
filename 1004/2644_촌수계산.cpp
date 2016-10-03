#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<iostream>
#include<queue>

using namespace std;

int n;
int p1, p2;
int m;
int graph[101][101];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 234234234;

    scanf("%d%d", &p1, &p2);
    p1--, p2--;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--, b--;
        graph[a][b] = graph[b][a] = 1;
    }

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);

    int chonsu = graph[p1][p2];
    printf("%d\n", chonsu == 234234234 ? -1 : chonsu);
    return 0;
}
