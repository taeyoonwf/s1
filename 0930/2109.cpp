#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<iostream>
#include<queue>

using namespace std;

struct lecture
{
    int p, d;

    bool operator<(const lecture& l) const
    {
        return d < l.d;
    }
};

int n;
lecture data[10001];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &data[i].p, &data[i].d);
    sort(data, data + n);

    priority_queue<int> pq;
    int j = n - 1;
    int ans = 0;
    for (int day = 10000; day >= 1; day--) {
        for (; j >= 0 && data[j].d >= day; j--)
            pq.push(data[j].p);
        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }

    printf("%d\n", ans);
    return 0;
}
