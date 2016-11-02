#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int M = 1000000;

struct matrix {
    long long m[2][2];
    matrix() {}
    matrix(int v00, int v01, int v10, int v11)
    {
        m[0][0] = v00;
        m[0][1] = v01;
        m[1][0] = v10;
        m[1][1] = v11;
    }

    matrix operator * (const matrix& s) const
    {
        matrix result = matrix(0, 0, 0, 0);
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    result.m[i][j] += (m[i][k] * s.m[k][j]) % M;
                    result.m[i][j] %= M;
                }
            }
        }
        return result;
    }
};

matrix base[64];

int main()
{
    // initialize
    base[0] = matrix(1, 1, 1, 0);

    // expand to 2^63
    for (int i = 1; i < 64; i++)
        base[i] = base[i-1] * base[i-1];

    long long n;
    cin >> n;
    n--;

    matrix result = matrix(1, 0, 0, 0);
    for (int i = 0; i < 63; i++) {
        if ((n & (1LL << i)) == 0) continue;
        result = result * base[i];
    }

    cout << result.m[0][0];

    return 0;
}
