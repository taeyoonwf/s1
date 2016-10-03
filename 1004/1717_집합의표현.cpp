#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<iostream>

using namespace std;

int n, m;
int root[1000001];

int getRoot(int v)
{
    int r = v;
    while (root[r] != r)
        r = root[r];
    while (v != r) { // speed up!
        int u = v;
        v = root[v];
        root[u] = r;
    }
    return r;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n + 1; i++)
        root[i] = i;

    for (int i = 0; i < m; i++) {
        int op, a, b;
        scanf("%d%d%d", &op, &a, &b);
        a = getRoot(a);
        b = getRoot(b);
        if (op == 0)
            root[b] = a;
        else
            printf("%s\n", (a == b) ? "YES" : "NO");
    }
    return 0;
}
