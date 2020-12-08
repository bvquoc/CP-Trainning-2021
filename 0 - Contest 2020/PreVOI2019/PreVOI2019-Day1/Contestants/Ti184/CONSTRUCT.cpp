#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 1e6 + 5;
const long long oo = 1e15;

typedef pair<int, int> II;
typedef pair<long long, II> III;

int T, N, M, sn = 0, lazy[4 * maxn];
long long a[maxn], it[4 * maxn], dt[4 * maxn];
long long s[maxn], Prev[maxn], Next[maxn];
III Query[maxn];

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

void WriteInt(long long x)
{
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) WriteInt(x / 10);
    putchar(x % 10 + '0');
}

void Update(int r, int k, int l, int u, int v, long long val)
{
    if (v < k || l < u) return;
    if (u <= k && l <= v) {
        lazy[r] =  1; dt[r] += val; return;
    }
    if (lazy[r] == 1) {
        lazy[2 * r] = lazy[2 * r + 1] = lazy[r];
        dt[2 * r] += dt[r]; dt[2 * r + 1] += dt[r];
        dt[r] = lazy[r] = 0;
    }
    int g = (k + l) / 2;
    Update(2 * r, k, g, u, v, val);
    Update(2 * r + 1, g + 1, l, u, v, val);
    it[r] = min(it[2 * r] + dt[2 * r], it[2 * r + 1] + dt[2 * r + 1]);
}

long long Get(int r, int k, int l, int u, int v)
{
    if (v < k || l < u) return oo;
    if (u <= k && l <= v) return it[r] + dt[r];
    if (lazy[r] == 1) {
        lazy[2 * r] = lazy[2 * r + 1] = lazy[r];
        dt[2 * r] += dt[r]; dt[2 * r + 1] += dt[r];
        dt[r] = lazy[r] = 0;
    }
    int g = (k + l) / 2;
    long long t1 = Get(2 * r, k, g, u, v);
    long long t2 = Get(2 * r + 1, g + 1, l, u, v);
    it[r] = min(it[2 * r] + dt[2 * r], it[2 * r + 1] + dt[2 * r + 1]);
    return min(t1, t2);
}

void Input()
{
    T = ReadInt();
    while (T--) {
        N = ReadInt(); M = ReadInt();
        for (int i = 1, u; i <= N; ++i) {
            u = ReadInt();
            a[i] = 1LL * u;
        }
        int type, L, R, k;
        while (M--) {
            type = ReadInt(); L = ReadInt(); R = ReadInt();
            if (type == 1) {
                k = ReadInt();
                for (int i = L; i <= R; ++i) a[i] += k;
            }
            else {
                for (int i = 1; i <= N; ++i) Update(1, 1, N, i, i, a[i]);
                a[0] = a[1] - 1; sn = 0;
                for (int i = 1; i <= N; ++i)
                    if (a[i] > a[i - 1]) Prev[i] = i, s[++sn] = i;
                    else {
                        while (sn > 0 && a[s[sn]] >= a[i]) --sn;
                        ++sn; Prev[i] = Prev[s[sn]]; s[sn] = i;
                    }
                a[N + 1] = a[N] - 1; sn = 0;
                for (int i = N; i >= 1; --i)
                    if (a[i] > a[i + 1]) Next[i] = i, s[++sn] = i;
                    else {
                        while (sn > 0 && a[s[sn]] >= a[i]) --sn;
                        ++sn; Next[i] = Next[s[sn]]; s[sn] = i;
                    }
                int slQ = 0;
                for (int i = 1; i <= N; ++i) Query[++slQ] = III(a[i], II(Prev[i], Next[i]));
                sort(Query + 1, Query + 1 + slQ);
                slQ = unique(Query + 1, Query + 1 + slQ) - Query - 1;
                long long ans = 0;
                for (int i = 1; i <= slQ; ++i) {
                    int u = Query[i].second.first, v = Query[i].second.second;
                    long long t = Get(1, 1, N, u, v);
                    ans += t;
                    Update(1, 1, N, u, v, -t);
                }
                WriteInt(ans); putchar('\n');
             }
        }
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
    #define TASK "CONSTRUCT"
    #ifdef TASK
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);
    #else
    freopen("INPUT.INP", "r", stdin);
    #endif // TASK
    Input();
    Solve();
    Output();
}

