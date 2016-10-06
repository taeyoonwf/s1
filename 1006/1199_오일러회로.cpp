#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

int n;
int graph[1001][1001];
int degree[1001];
vector<int> ans;

void dfs(int v)
{
    for (int i = 0; i < n; i++) {
        if (!graph[v][i]) continue;
        graph[v][i]--;
        graph[i][v]--;
        degree[v]--;
        degree[i]--;
        dfs(i);
    }
    ans.push_back(v);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            degree[i] += graph[i][j];

    int odd = 0, odd_idx = -1;
    for (int i = 0; i < n; i++)
        if (degree[i] % 2)
            odd++, odd_idx = i;

    if (odd > 2) {
        printf("-1\n");
        return 0;
    }

    dfs(0);
    for (int i = 0; i < n; i++)
        if (degree[i]) {
            printf("-1\n");
            return 0;
        }

    for (auto v : ans)
        printf("%d ", v + 1);
    printf("\n");

    return 0;
}
