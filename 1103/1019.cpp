#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

vector<int> f(int x)
{
    vector<int> result(10);

    if (x <= 9) {
        for (int i = 1; i <= x; i++)
            result[i] = 1;
        return result;
    }

    while (x % 10 != 9) {
        int t = x;
        while (t) {
            result[t % 10]++;
            t /= 10;
        }
        x--;
    }

    vector<int> div10 = f(x / 10);
    for (int i = 0; i < 10; i++)
        result[i] += div10[i] * 10 + (x / 10 + (i > 0));

    return result;
}

int main()
{
    int n;
    scanf("%d", &n);

    vector<int> result = f(n);
    for (int i = 0; i < 10; i++)
        printf("%d ", result[i]);
    printf("\n");

    return 0;
}
