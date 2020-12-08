#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9 + 7;

int m, n, x, y;
int it[5000005], dt[5000005];
char s[1000005], d[5005][5005], id;

void sub1() {
        for(int i = 1; i <= m; ++ i) {
            cin >> id;
            if(id == 'C') {
                scanf("%d", &x);
                s[x] = (s[x] == '(') ? ')' : '(';
            } else if(id == 'Q') {
                scanf("%d %d", &x, &y);
                int t = 0, res = 0;
                for(int j = x; j <= y; ++ j) {
                    t += (s[j] == '(') ? 1 : -1;
                    if(t < 0) ++ res, ++ t;
                }
                res += t;
                printf("%d\n", res);
            } else {
                scanf("%d", &x);
                for(int j = 1; j <= n; ++ j)
                    s[j] = d[x-1][j];
            }
            for(int j = 1; j <= n; ++ j)
                d[i][j] = s[j];
        }
}

void upd(int id, int l, int r, int u, int v, int d) {
        if(u > r || v < l) return;
        if(u <= l && r <= v) {
            dt[id] += d; return;
        }
        int mid = (l+r)/2;
        dt[2*id] += dt[id]; dt[2*id+1] += dt[id]; dt[id] = 0;

        upd(2*id,l,mid,u,v,d);
        upd(2*id+1,mid+1,r,u,v,d);

        it[id] = min(it[2*id]+dt[2*id], it[2*id+1]+dt[2*id+1]);
        return;
}

int get(int id, int l, int r, int u, int v) {
        if(u > r || v < l) return inf;
        if(u <= l && r <= v)
            return it[id] + dt[id];

        int mid = (l+r)/2;
        dt[2*id] += dt[id]; dt[2*id+1] += dt[id]; dt[id] = 0;

        int t1 = get(2*id,l,mid,u,v);
        int t2 = get(2*id+1,mid+1,r,u,v);

        it[id] = min(it[2*id]+dt[2*id], it[2*id+1]+dt[2*id+1]);
        return min(t1, t2);
}

void sub2() {
        int t = 0;
        for(int i = 1; i <= n; ++ i)
            t += (s[i] == '(') ? 1 : -1,
            upd(1,1,n,i,i,t);

        for(int i = 1; i <= m; ++ i) {
            cin >> id;
            if(id == 'C') {
                scanf("%d", &x);
                int t = (s[x] == '(') ? -2 : 2;
                s[x] = (s[x] == '(') ? ')' : '(';
                upd(1,1,n,x,n,t);
            } else if(id == 'Q') {
                scanf("%d %d", &x, &y);
                int u = 0, t, res = 0;
                if(x > 1)
                    u = get(1,1,n,x-1,x-1);
                t = get(1,1,n,x,y);
                if(u > t) res += u-t;
                t = res + get(1,1,n,y,y);
                if(t > u) res += t-u;
                printf("%d\n", res);
            }
        }
}

void Solve() {
        scanf("%s", s+1);
        scanf("%d", &m);
        n = strlen(s+1);
        if(max(m,n) <= 1000) sub1();
        else sub2();
}

#define task "FIXSTR"
int main() {
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
        Solve();
}
