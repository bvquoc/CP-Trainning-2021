#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 4e5 + 5;
const int MOD = 1e6 + 3;

int N, M;
int a[maxn], G[maxn];
int F[5005][5005];

int ReadInt()
{
    char ch;
    do ch = getchar();
    while (ch != '+' && ch != '-' && (ch < '0' || ch > '9'));
    int sign = (ch == '-') ? -1 : 1;
    int res = (ch >= '0' && ch <= '9') ? ch - '0' : 0;
    ch = getchar();
    while (ch >= '0' && ch <= '9') {
        res = res * 10 + ch - '0';
        ch = getchar();
    }
    return res * sign;
}

void WriteInt(int x)
{
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) WriteInt(x / 10);
    putchar(x % 10 + '0');
}

void Input()
{
    N = ReadInt(); M = ReadInt();
    for (int i = 1; i <= 2 * N; ++i) a[i] = ReadInt();
}

void Subtask0_1()
{
    for (int i = 0; i <= N; ++i) F[i][0] = 1;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= i; ++j)
            F[i][j] = (F[i - 1][j] + F[i][j - 1]) % MOD;

    G[0] = 1;
    for (int i = 2; i <= 2 * N; ++i) {
        int u = lower_bound(a + 1, a + 1 + 2 * N, a[i] - M) - a;
        if (u <= i - 1) G[i] = G[i - 2];
        for (int j = u; j < i; ++j) if ((i - j + 1) % 2 == 0) {
            if (j + 1 < i - 1) {
                int tmp = (1LL * G[j - 1] * F[(i - j - 1) / 2][(i - j - 1) / 2]) % MOD;
                (G[i] += tmp) % MOD;
            }
        }
    }
    WriteInt(G[2 * N]);
}

void Output()
{
    Subtask0_1();
}

int main()
{
    #define TASK "MINE"
    #ifdef TASK
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);
    #else
    freopen("INPUT.INP", "r", stdin);
    #endif // TASK
    Input();
    Output();
}

