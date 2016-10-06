#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

int n;
string magic;
string bridge[2];
int dp[25][105][2];

int main()
{
    cin >> magic;
    cin >> bridge[0] >> bridge[1];

    magic = " " + magic;
    bridge[0] = " " + bridge[0];
    bridge[1] = " " + bridge[1];
    n = bridge[0].size();

    dp[0][0][0] = 1;
    dp[0][0][1] = 1;
    
    for (int i = 0; i < magic.size(); i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 2; k++) {
                if (dp[i][j][k] == 0)
                    continue;
                int ni = i + 1;
                int nk = 1 - k;
                for (int nj = j + 1; nj < n; nj++) {
                    if (magic[ni] != bridge[nk][nj])
                        continue;
                    dp[ni][nj][nk] += dp[i][j][k];
                }
            }
        }
    }

    int ans = 0;
    for (int j = 0; j < n; j++)
        for (int k = 0; k < 2; k++)
            ans += dp[magic.size() - 1][j][k];
    printf("%d\n", ans);

    return 0;
}
