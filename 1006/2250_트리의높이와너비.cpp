#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>

using namespace std;

int n;
int child[10001][2];
int size[10001];
int level_min[10001];
int level_max[10001];
int total_level;
int is_root[10001];

int calcSize(int v)
{
    int sum = 1; // myself
    for (int i = 0; i < 2; i++)
        if (child[v][i] >= 0)
            sum += calcSize(child[v][i]);
    size[v] = sum;
    return size[v];
}

int getLeftSize(int v)
{ return (child[v][0] >= 0) ? size[child[v][0]] : 0; }

int getRightSize(int v)
{ return (child[v][1] >= 0) ? size[child[v][1]] : 0; }

void dfs(int v, int level, int x)
{
    //printf("%d %d %d\n", v + 1, level, x);
    level_min[level] = min(level_min[level], x);
    level_max[level] = max(level_max[level], x);
    total_level = max(total_level, level);

    int left, right;
    left  = child[v][0];
    right = child[v][1];
    if (left >= 0)
        dfs(left, level + 1, x - getRightSize(left) - 1);
    if (right >= 0)
        dfs(right, level + 1, x + getLeftSize(right) + 1);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
        is_root[i] = true;
        level_min[i] = 234234234;
        level_max[i] = -234234234;
    }
    for (int i = 0; i < n; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        a--, b--, c--;
        child[a][0] = b;
        child[a][1] = c;
        is_root[b] = false;
        is_root[c] = false;
    }

    int root = -1;
    for (int i = 0; i < n; i++)
        if (is_root[i])
            root = i;
    calcSize(root);
    dfs(root, 1, getLeftSize(root) + 1);

    int ans = 0, ans_level = 0;
    for (int i = 1; i <= total_level; i++) {
        if (ans < level_max[i] - level_min[i] + 1) {
            ans = level_max[i] - level_min[i] + 1;
            ans_level = i;
        }
    }
    printf("%d %d\n", ans_level, ans);
    return 0;
}
