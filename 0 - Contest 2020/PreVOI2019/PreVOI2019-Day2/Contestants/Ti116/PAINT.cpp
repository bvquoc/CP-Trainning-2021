#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

typedef pair<char, char> ii;
typedef pair<int, ii> iii;

iii b[1000005];

int n;
char a[1000005];
int lt[50], d[1000005];

void sub1() {
        int c = 0, id; char x, y;
        for(int i = 1; i <= n; ++ i) {
            scanf("%d", &id);
            if(id == 1) {
                cin >> x;
                a[++c] = x;
            } else {
                cin >> x >> y;
                for(int j = 1; j <= c; ++ j)
                    if(a[j] == x) a[j] = y;
            }
        }
        printf("%s", a + 1);
}

int Find(int u) {
        if(lt[u] == u) return u;
        return lt[u] = Find(lt[u]);
}

void sub2() {
        int c = 0, sb = 0, sd = 0, id; char x, y;
        for(int i = 1; i <= 26; ++ i) lt[i] = i;
        for(int i = 1; i <= n; ++ i) {
            scanf("%d", &id);
            if(id == 1) {
                cin >> x;
                a[++c] = x;
                d[++sd] = i;
            } else {
                cin >> x >> y;
                b[++sb] = iii(i, ii(x, y));
            }
        }
        int j = sb;
        for(int i = c; i >= 1; -- i) {
            while(j >= 1 && b[j].x > d[i]) {
                int u = b[j].y.x - 'a' + 1;
                int v = b[j].y.y - 'a' + 1;
                u = Find(u); v = Find(v);
                lt[u] = v; -- j;
            }
            a[i] = Find(a[i]-'a'+1) + 'a' - 1;
        }
        printf("%s", a+1);
}

void Solve() {
        scanf("%d", &n);
        if(n <= 10000) sub1();
        else sub2();
}

#define task "PAINT"
int main() {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
        Solve();
}
