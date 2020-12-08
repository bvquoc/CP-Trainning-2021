#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 1e5 + 5;
const int oo = 1e9 + 7;

int Q, X, T, N;
int a[20], b[20];
int F[maxn], c[20];

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

void Subtask0_1()
{
    for (int i = 0; i <= T; ++i) F[i] = oo;
    F[0] = 0;
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= T; ++j)
            if (j >= b[i] && F[j - b[i]] != oo) F[j] = min(F[j], F[j - b[i]] + 1);
    }
    WriteInt(F[T]);
}

void Subtask0_2()
{
    int ans = oo;
    for (int x = 0; x < (1 << N); ++x) {
        int slc = 0;
        for (int i = 1; i <= N; ++i) if ((x >> (i - 1)) & 1) c[++slc] = b[i];
        int i = slc, cnt = 0;
        int Money = T;
        while (Money > 0 && i > 0) {
            while (i > 0 && c[i] > Money) --i;
            if (i == 0 && Money != 0) goto l1;
            cnt += Money / c[i];
            Money %= c[i];
        }
        if (Money > 0) goto l1;
        ans = min(ans, cnt);
        l1:;
    }
    WriteInt(ans);
}

void Input()
{
    a[1] = 1; a[2] = 3; a[3] = 5;
    for (int i = 4; i <= 15; ++i) a[i] = a[i - 3] * 10;
    Q = ReadInt();
    while (Q--) {
        X = ReadInt(); T = ReadInt();
        N = 0;
        for (int i = 1; i <= 15; ++i) b[++N] = a[i];
        b[++N] = X;
        sort(b + 1, b + 1 + 16);
        int N = unique(b + 1, b + 1 + 16) - b - 1;
        if (X <= 100000 && T <= 1000000) Subtask0_1();
        else Subtask0_2();
        putchar('\n');
    }
}

void Solve()
{

}

void Output()
{

}

int main()
{
    #define TASK "ODDCOIN"
    #ifdef TASK
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);
    #else
    freopen("INPUT.INP", "r", stdin);
    freopen("OUTPUT.OUT", "w", stdout);
    #endif // TASK
    Input();
    Solve();
    Output();
}

