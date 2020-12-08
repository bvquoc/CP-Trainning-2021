#include <bits/stdc++.h>

using namespace std;

const int mod = 1000003;

int n, m;
int a[1000005];
int ans = 0, d[50], g[50];

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

void Try(int u) {
        if(u > 2*n) {
            int c = 0;
            for(int i = 1; i <= n; ++ i) g[i] = 0;
            for(int i = 1; i <= 2*n; ++ i) {
                if(d[i]) {
                    if(c < n) ++ c, g[c] = a[i];
                    else return;
                } else {
                    if(!c) return;
                    if(a[i]-g[c]>m) return;
                    -- c;
                }
            }
            if(c) return;
            ans ++; ans %= mod; return;
        }
        for(int i = 0; i <= 1; ++ i)
            d[u] = i, Try(u+1);
}

void sub1() {
        Try(1);
        WriteInt(ans);
}

void Solve() {
        n = ReadInt(); m = ReadInt();
        for(int i = 1; i <= 2*n; ++ i)
            a[i] = ReadInt();
        sub1();
}

#define task "Mine"
int main() {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
        Solve();
}
