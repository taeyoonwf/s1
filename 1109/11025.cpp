#include<cstdio>
#include<cstring>

int n, m;

int main()
{
    scanf("%d%d", &n, &m);
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result = (result + m) % i;
        if (result == 0) result = i;
    }
    printf("%d\n", result);

    return 0;
}
