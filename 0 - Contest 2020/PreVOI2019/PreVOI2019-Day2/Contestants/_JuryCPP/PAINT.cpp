/*
#linked list
*/
#define taskname "PAINT"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <forward_list>
#include <string>
using namespace std;
const int maxN = 1e6;
const int maxC = 26;

int n, m;
forward_list<int> L[maxC];

inline char ReadDigit()
{
    char c;
    while (c = getchar(), c < '0' || c > '9');
    return c;
}

inline char ReadABC()
{
    char c;
    while (c = getchar(), c < 'a' || c > 'z');
    return c;
}

inline int ReadInt()
{
    int x = ReadDigit() - '0';
    char c;
    while (c = getchar(), c >= '0' && c <= '9')
        x = x * 10 + c - '0';
    return x;
}

void Solve()
{
    n = 0;
    m = ReadInt();
    while (m-- > 0)
    {
        char cmd = ReadDigit();
        if (cmd == '1')
        {
            int color = ReadABC() - 'a';
            L[color].push_front(n++);
        }
        else
        {
            int x = ReadABC() - 'a';
            int y = ReadABC() - 'a';
            if (x != y) L[y].splice_after(L[y].before_begin(), L[x]);
        }
    }
    string res;
    res.resize(n);
    for (int c = 0; c < maxC; ++c)
        for (int i: L[c])
            res[i] = char(c + 'a');
    for (char c: res)
        putchar(c);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".INP", "r", stdin);
    freopen(taskname".OUT", "w", stdout);
    Solve();
}
