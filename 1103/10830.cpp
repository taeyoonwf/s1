#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int M = 1000;

struct matrix {
    long long m[5][5];
    int size;

    matrix() {}
    matrix(int _size)
    {
        size = _size;
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                m[i][j] = 0;
    }

    void identity()
    {
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                m[i][j] = (i == j);
    }

    matrix operator * (const matrix& s) const
    {
        matrix result(size);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                for (int k = 0; k < size; k++) {
                    result.m[i][j] += (m[i][k] * s.m[k][j]) % M;
                    result.m[i][j] %= M;
                }
            }
        }
        return result;
    }
};

matrix base[64];
int n;
long long b;

int main()
{
    cin >> n >> b;

    base[0] = matrix(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> base[0].m[i][j];

    for (int i = 1; i < 64; i++)
        base[i] = base[i-1] * base[i-1];

    matrix result(n);
    result.identity();
    for (int i = 0; i < 63; i++) {
        if ((b & (1LL << i)) == 0) continue;
        result = result * base[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << result.m[i][j] << " ";
        cout << endl;
    }

    return 0;
}
