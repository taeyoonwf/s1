#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

int n, m;
int remain[5001];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        remain[i] = i;

    int index = 0;
    m--;

    vector<int> result;
    int t = n;
    for (int i = 0; i < t; i++) {
        index = (index + m) % n;
        result.push_back(remain[index]);
        for (int j = index; j < n; j++)
            remain[j] = remain[j+1];
        n--;
    }

    for (int i = 0; i < t; i++) {
        if (i == 0)
            printf("<");
        else
            printf(", ");
        printf("%d", result[i] + 1);
    }
    printf(">");

    return 0;
}
