#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
typedef pair<int, int> ii;

const int maxn = 1000005;

ii c[maxn];

int t;
int n, m;
int a[maxn], b[maxn], d[maxn];

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

void WriteInt(int64_t x) {
        if(x < 0) putchar('-'), x = -x;
        if(x > 9) WriteInt(x / 10);
        putchar(x%10 + '0');
}

void Solve() {
        t = ReadInt();
        while(t --) {
            n = ReadInt(); m = ReadInt();
            for(int i = 1; i <= n; ++ i)
                a[i] = ReadInt();
            while(m --) {
                int id;
                id = ReadInt();
                if(id == 1) {
                    int l, r, k;
                    l = ReadInt(); r = ReadInt(); k = ReadInt();
                    for(int i = l; i <= r; ++ i) a[i] += k;
                } else {
                    int l, r;
                    l = ReadInt(); r = ReadInt();
                    int sl = 0;
                    for(int i = l; i <= r; ++ i) b[++sl] = a[i];
                    sl = unique(b+1, b+sl+1) - b - 1;

                    c[0] = ii(0, 0);
                    for(int i = 1; i <= sl; ++ i)
                        c[i] = ii(b[i], i);

                    sort(c+1, c+sl+1);
                    int64_t ans = 0;
                    int lt = 0, j = sl;

                    for(int i = 0; i <= sl+1; ++ i) d[i] = 0;
                    for(int i = sl; i >= 0; -- i) {
                        while(c[j].x > c[i].x) {
                            if(d[c[j].y-1] == 0 && d[c[j].y+1] == 0) lt ++;
                            if(d[c[j].y-1] == 1 && d[c[j].y+1] == 1) lt --;
                            d[c[j].y] = 1;
                            -- j;
                        }
                        ans += 1ll*lt*(c[i+1].x-c[i].x);
                    }
                    WriteInt(ans); putchar(10);
                }
            }
        }
}

#define task "Construct"
int main() {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
        Solve();
}
