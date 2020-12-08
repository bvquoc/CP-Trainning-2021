#include <bits/stdc++.h>

using namespace std;

const int inf = 2e9 + 7;

int t, q, x, a[20], f[100005];

int b[16] = {0, 1, 3, 5, 10, 30, 50, 100, 300, 500, 1000, 3000, 5000, 10000, 30000, 50000 };

int ReadInt() {
        char ch;
        do
                ch = getchar();
        while(ch != '-' && ch != '+' && (ch < '0' || ch > '9'));
        int sign = (ch == '-') ? -1 : 1;
        int val  = (ch >= '0' && ch <= '9') ? ch - '0' : 0;
        ch = getchar();
        while(ch >= '0' && ch <= '9') {
                val = 10*val + ch - '0';
                ch  = getchar();
        }
        return sign * val;
}

void WriteInt(int x) {
        if(x < 0) putchar('-'), x = -x;
        if(x > 9) WriteInt(x / 10);
        putchar(x%10 + '0');
}

void sub1() {
        a[16] = x;
        for(int i = 1; i <= 15; ++ i)
            a[i] = b[i];
        f[0] = 0;
        for(int i = 1; i <= t; ++ i) f[i] = inf;
        for(int i = 1; i <= t; ++ i)
        for(int j = 1; j <= 16; ++ j) if(i >= a[j])
                if(f[i-a[j]] < inf) f[i] = min(f[i], f[i-a[j]] + 1);
        WriteInt(f[t]); putchar(10);
}

void Solve() {
        q = ReadInt();
        while(q --) {
            x = ReadInt(); t = ReadInt();
            sub1();
        }
}

#define task "Oddcoin"
int main() {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
        Solve();
}
