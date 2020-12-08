#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

const int maxn = 1e6 + 5;

int N, M;
char s[maxn], t[5005][5005];
int d[maxn], lazy[4 * maxn];
int dt[4 * maxn], it[4 * maxn];

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
    scanf("%s", s + 1); N = strlen(s + 1);
    M = ReadInt();
}

void Subtask0_1()
{
    for (int i = 1; i <= N; ++i) t[i][0] = s[i];
    char ch; int u, v;
    for (int q = 1; q <= M; ++q) {
        cin >> ch; u = ReadInt();
        for (int i = 1; i <= N; ++i) t[i][q] = t[i][q - 1];
        if (ch == 'C') {
            if (t[u][q - 1] == '(') t[u][q] = ')';
            else if (t[u][q - 1] == ')') t[u][q] = '(';
        }
        else if (ch == 'U') {
            for (int i = 1; i <= N; ++i) t[i][q] = t[i][u - 1];
        }
        else {
            v = ReadInt();
            int sn = 0, cnt = 0;
            for (int i = u; i <= v; ++i) {
                if (t[i][q] == '(') ++sn;
                else {
                    if (sn == 0) ++cnt;
                    else --sn;
                }
            }
            cnt += sn;
            WriteInt(cnt); putchar('\n');
        }
    }
}

void Update(int r, int k, int l, int u, int v, int val)
{
    if (v < k || l < u) return;
    if (u <= k && l <= v) {
        lazy[r] = 1; dt[r] += val; return;
    }
    int g = (k + l) / 2;
    if (lazy[r] == 1) {
        lazy[2 * r] = lazy[2 * r + 1] = 1;
        dt[2 * r] += dt[r], dt[2 * r + 1] += dt[r];
        lazy[r] = dt[r] = 0;
    }
    Update(2 * r, k, g, u, v, val);
    Update(2 * r + 1, g + 1, l, u, v, val);
    it[r] = it[2 * r] + dt[2 * r] * (g - k + 1) + it[2 * r + 1] + dt[2 * r + 1] * (l - g);
}

int Get(int r, int k, int l, int u, int v)
{
    if (v < k || l < u) return 0;
    if (u <= k && l <= v) return it[r] + dt[r] * (l - k + 1);
    int g = (k + l) / 2;
    if (lazy[r] == 1) {
        lazy[2 * r] = lazy[2 * r + 1] = 1;
        dt[2 * r] += dt[r], dt[2 * r + 1] += dt[r];
        lazy[r] = dt[r] = 0;
    }
    int t1 = Get(2 * r, k, g, u, v);
    int t2 = Get(2 * r + 1, g + 1, l, u, v);
    it[r] = it[2 * r] + dt[2 * r] * (g - k + 1) + it[2 * r + 1] + dt[2 * r + 1] * (l - g);
    return t1 + t2;
}

void Subtask0_2()
{
    for (int i = 1; i <= N; ++i) {
        if (s[i] == '(') Update(1, 1, N, i, N, 1);
        else Update(1, 1, N, i, N, -1);
    }
    char ch; int u, v;
    for (int q = 1; q <= M; ++q) {
        cin >> ch; u = ReadInt();
        for (int i = 1; i <= N; ++i)
        if (ch == 'C') {
            if (s[u] == '(') s[u] = ')', Update(1, 1, N, u, N, -2);
            else s[u] = '(', Update(1, 1, N, u, N, 2);
        }
        else if (ch == 'Q') {
            v = ReadInt();
            WriteInt(abs(Get(1, 1, N, v, v) - Get(1, 1, N, u - 1, u - 1))); putchar('\n');
        }
    }
}

void Output()
{
    if (1LL * M * N <= 100000000) Subtask0_1();
    else Subtask0_2();
}

int main()
{
    #define TASK "FIXSTR"
    #ifdef TASK
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);
    #else
    freopen("INPUT.INP", "r", stdin);
    #endif // TASK
    Input();
    Output();
}

