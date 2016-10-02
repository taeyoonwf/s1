#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<iostream>
#include<queue>

using namespace std;

struct gem
{
    int m, v;

    bool operator<(const gem& g) const
    {
        return m < g.m;
    }
};

int N, K;
gem data[300001];
int cap[300001];

int main()
{
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++)
        scanf("%d%d", &data[i].m, &data[i].v);
    for (int i = 0; i < K; i++)
        scanf("%d", &cap[i]);
    sort(data, data + N);
    sort(cap, cap + K);

    priority_queue<int> pq;
    int j = 0;
    long long ans = 0;
    for (int i = 0; i < K; i++) {
        for (; j < N && data[j].m <= cap[i]; j++) {
            pq.push(data[j].v);
            //printf("push %d\n", data[j].v);
        }
        if (!pq.empty()) {
            //printf("pop %d\n", pq.top());
            ans += pq.top();
            pq.pop();
        }
    }
    printf("%lld\n", ans);

    return 0;
}
