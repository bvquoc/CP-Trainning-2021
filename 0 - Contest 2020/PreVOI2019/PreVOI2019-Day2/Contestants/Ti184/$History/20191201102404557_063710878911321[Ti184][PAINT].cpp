#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 1e6 + 5;

int N, color[maxn];
int rem[30][maxn], sl[30];
vector<int> LT[maxn];
priority_queue<int> p;

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
    int type;
    char x, y;
    for (int q = 1; q <= N; ++q) {
        type = ReadInt(); cin >> x;
        if (type == 1) {
            for (int i = 1; i <= N; ++i) if (color[i] == 0) {
                color[i] = x - 'a' + 1; break;
            }
        }
        else {
            cin >>y;
            for (int i = 1; i <= N; ++i) if (color[i] == x - 'a' + 1) {
                color[i] = y - 'a' + 1;
            }
        }
        for (int i = 1; i <= N; ++i) if (color[i] != 0) putchar(color[i] + 'a' - 1); putchar('\n');
    }
    for (int i = 1; i <= N; ++i) if (color[i] != 0) putchar(color[i] + 'a' - 1);
}
/*
void Subtask0_2()
{
    for (int i = 1; i <= N; ++i) p.push(-i);
    int type; char x, y;
    for (int q = 1; q <= N; ++q) {
        type = ReadInt(); cin >>x;
        if (type == 1) {
            if (!p.empty()) {
                int u = -p.top(); p.pop();
                if (sl[x - 'a' + 1] == 0) {
                    ++sl[x - 'a' + 1];
                    rem[x - 'a' + 1][sl[x - 'a' + 1]] = u;
                    LT[u].push_back(u);
                }
                else {
                    int v = rem[x - 'a' + 1][1];
                    LT[v].push_back(u);
                }
            }
        }
        else {
            cin >>y;
            for (int i = 1; i <= sl[x - 'a' + 1]; ++i) rem[y - 'a' + 1][++sl[y - 'a' + 1]] = rem[x - 'a' + 1][i];
            sl[x - 'a' + 1] = 0;
        }
    }
    for (int i = 1; i <= 26; ++i) {
        for (int u = 1; u <= sl[i]; ++u) {
            for (int v : LT[rem[i][u]]) color[v] = i;
        }
    }
    for (int i = 1; i <= N; ++i) if (color[i] != 0) putchar(color[i] + 'a' - 1);
}
*/
void Input()
{
    N = ReadInt();
    if (N <= 5000) Subtask0_1();
    //else Subtask0_2();
}

void Solve()
{

}

void Output()
{

}

int main()
{
    #define TASK "PAINT"
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

