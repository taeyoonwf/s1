#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<iostream>
#include<queue>

using namespace std;

int n, m;
int indegree[1001];
int graph[1001][1001];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int cnt;
        scanf("%d", &cnt);
        int v, u;
        scanf("%d", &v);
        v--;
        for (int j = 0; j < cnt - 1; j++) {
            scanf("%d", &u);
            u--;
            graph[v][u] = 1;
            v = u;
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (graph[i][j])
                indegree[j]++;

    queue<int> q;
    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            q.push(i);

    vector<int> ans;
    while (!q.empty()) {
        int singer = q.front(); q.pop();
        ans.push_back(singer);
        for (int i = 0; i < n; i++)
            if (graph[singer][i]) {
                indegree[i]--;
                if (indegree[i] == 0)
                    q.push(i);
            }
    }

    if (ans.size() < n)
        printf("0\n");
    else {
        for (int i = 0; i < ans.size(); i++)
            printf("%d\n", ans[i] + 1);
    }
    return 0;
}
