#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;

struct edge {
    int to, cost;

    edge() {}
    edge(int _to, int _cost)
    {
        to = _to;
        cost = _cost;
    }

    bool operator<(const edge& e) const
    {
        return cost < e.cost;
    }
};

int n, m;
vector<edge> adj[1001];
int prim[1001];
bool visit[1001];

int main()
{
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--, b--;
        adj[a].push_back(edge(b, c)); 
        adj[b].push_back(edge(a, c)); 
    }
    for (int i = 0; i < n; i++)
        prim[i] = 234234234;
    prim[0] = 0;
    
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (visit[j]) continue;
            if (v == -1 || prim[v] > prim[j])
                v = j;
        }
        visit[v] = true;
        for (auto e : adj[v])
            if (!visit[e.to] && prim[e.to] > e.cost)
                prim[e.to] = e.cost;
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += prim[i];

    printf("%d\n", sum);
    return 0;
}
