#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<iostream>

using namespace std;

string data;
int dp[512][512];
int n;

int solve(int i, int j)
{
    int& ret = dp[i][j];
    if (ret != -1)
        return ret;

    ret = 0;
    if (i >= j)
        return 0;
    string sij;
    sij += data[i];
    sij += data[j];
    if (sij == "at" || sij == "gc")
        ret = max(ret, solve(i+1, j-1) + 2);
    for (int k = i; k < j; k++)
        ret = max(ret, solve(i, k) + solve(k+1, j));

    return ret;
}

int main()
{
    cin >> data;
    n = data.size();

    memset(dp, -1, sizeof(dp));
    printf("%d\n", solve(0, n-1));
    return 0;
}
