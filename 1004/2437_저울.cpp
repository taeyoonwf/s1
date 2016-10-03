#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<iostream>
#include<queue>

using namespace std;

int n;
int data[1001];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &data[i]);
    sort(data, data + n);

    int current_max = 0;
    for (int i = 0; i < n; i++) {
        if (current_max + 1 < data[i])
            break;
        current_max += data[i];
    }
    printf("%d\n", current_max + 1);

    return 0;
}
