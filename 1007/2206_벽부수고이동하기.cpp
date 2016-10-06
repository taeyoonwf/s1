#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>

using namespace std;

struct state {
    bool smash;
    int y, x;

    state() {}
    state(bool _smash, int _y, int _x) {
        smash = _smash;
        y = _y;
        x = _x;
    }
};

const int hy[4] = {-1, 0, 1, 0};
const int hx[4] = {0, 1, 0, -1};
int n, m;
char data[1001][1001];
int dist[2][1001][1001];

bool out(int y, int x)
{ return y < 0 || y >= n || x < 0 || x >= m; }

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", data[i]);
    
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < m; k++)
                dist[i][j][k] = 234234234;

    queue<state> q;
    dist[0][0][0] = 1;
    q.push(state(0, 0, 0));

    while (!q.empty()) {
        state cur = q.front(); q.pop();
        int cur_dist = dist[cur.smash][cur.y][cur.x];
        for (int i = 0; i < 4; i++) {
            state next;
            next.y = cur.y + hy[i];
            next.x = cur.x + hx[i];
            if (out(next.y, next.x)) continue;
            if (cur.smash && data[next.y][next.x] == '1')
                continue;
            next.smash = cur.smash || data[next.y][next.x] == '1';
            if (dist[next.smash][next.y][next.x] > cur_dist + 1) {
                dist[next.smash][next.y][next.x] = cur_dist + 1;
                q.push(next);
            }
        }
    }

    int ans = min(dist[0][n-1][m-1], dist[1][n-1][m-1]);
    printf("%d\n", ans < 234234234 ? ans : -1);
    return 0;
}
