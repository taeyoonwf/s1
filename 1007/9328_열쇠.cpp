#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<set>
#include<queue>

using namespace std;

struct point {
    int y, x;

    point() {}
    point(int _y, int _x) {
        y = _y;
        x = _x;
    }
};

const int hy[4] = {-1, 0, 1,  0};
const int hx[4] = { 0, 1, 0, -1};
int n, m;
char data[105][105];
set<char> keys;
bool movable[105][105];

bool forbid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return true;
    if (data[i][j] == '*')
        return true;
    if (isupper(data[i][j]) && keys.count(tolower(data[i][j])) == 0)
        return true;
    return false;
}

bool isEdge(int i, int j)
{ return i == 0 || i == n - 1 || j == 0 || j == m - 1; }

void collectNewKeys()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            movable[i][j] = false;

    queue<point> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (isEdge(i, j) && !forbid(i, j)) {
                movable[i][j] = true;
                q.push(point(i, j));
            }

    set<char> new_keys;
    while (!q.empty()) {
        point cur = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            point next;
            next.y = cur.y + hy[i];
            next.x = cur.x + hx[i];
            if (forbid(next.y, next.x))
                continue;
            if (movable[next.y][next.x])
                continue;
            movable[next.y][next.x] = true;
            q.push(next);
            if (islower(data[next.y][next.x]))
                new_keys.insert(tolower(data[next.y][next.x]));
        }
    }

    for (auto key : new_keys)
        keys.insert(key);
}

int main()
{
    int T;
    scanf("%d", &T);

    while (T--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            cin >> data[i];
        string start_keys;
        cin >> start_keys;
        keys.clear();
        for (auto key : start_keys)
            keys.insert(key);

        int key_cnt = keys.size();
        while (1) {
            collectNewKeys();
            if (key_cnt == keys.size())
                break;
            key_cnt = keys.size();
        } 

        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (movable[i][j] && data[i][j] == '$')
                    ans++;

        printf("%d\n", ans);
    }

    return 0;
}
