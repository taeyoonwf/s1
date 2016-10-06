#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>

using namespace std;

int n;
string data;
int dp[201][201];

int number_length(int num)
{
    int len = 0;
    while (num) {
        num /= 10;
        len++;
    }
    return len;
}

int solve(int i, int j)
{
    int& ret = dp[i][j];
    if (ret != -1) return ret;
    if (i == j) return 1;

    ret = 234234234;
    for (int k = i; k < j; k++)
        ret = min(ret, solve(i, k) + solve(k + 1, j));
    
    int length = j - i + 1;
    for (int l = 1; l < length; l++) {
        if (length % l) continue;
        int c = length / l;
        // l = unit length, c = unit count
        bool all_same = true;
        string unit = data.substr(i, l);
        for (int k = 0; k < c; k++)
            if (unit != data.substr(i + k * l, l)) {
                all_same = false;
                break;
            }
        if (all_same)
            ret = min(ret, number_length(c) + 2 + solve(i, i + l - 1));
    }
    //cout << data.substr(i, j - i + 1) << " : " << ret << endl;
    return ret;
}

int main()
{
    cin >> data;
    n = data.size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = -1;

    printf("%d\n", solve(0, n - 1));
    return 0;
}
