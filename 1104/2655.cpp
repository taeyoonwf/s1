#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

struct stone
{
    int index, area, height, weight;

    stone() {}
    stone(int _index, int _area, int _height, int _weight)
    {
        index = _index;
        area = _area;
        height = _height;
        weight = _weight;
    }

    bool operator<(const stone& s) const
    {
        return area < s.area;
    }
};

int n;
stone data[101];
int dp[101];
int path[101];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        data[i].index = i + 1;
        scanf("%d%d%d", &data[i].area, &data[i].height, &data[i].weight);
    }
    sort(data, data + n);
    reverse(data, data + n);

    for (int i = 0; i < n; i++) {
        dp[i] = data[i].height;
        path[i] = -1;
        for (int j = 0; j < i; j++) {
            if (data[j].weight < data[i].weight) continue;
            if (dp[i] < dp[j] + data[i].height) {
                dp[i] = dp[j] + data[i].height;
                path[i] = j;
            }
        }
    }

    int ans = 0, start = -1;
    for (int i = 0; i < n; i++) {
        if (ans < dp[i]) {
            ans = dp[i];
            start = i;
        }
    }

    vector<int> result;
    while (start >= 0) {
        result.push_back(start);
        start = path[start];
    }

    printf("%d\n", (int)result.size());
    for (int i = 0; i < result.size(); i++)
        printf("%d\n", data[result[i]].index);
    return 0;
}
