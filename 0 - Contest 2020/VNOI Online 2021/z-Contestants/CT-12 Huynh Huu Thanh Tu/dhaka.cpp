#include <bits/stdc++.h>
using namespace std;

#define oo 1000000007
#define maxN 100010
#define fto(i,a,b) for (int i=a; i<=b; ++i)
#define fdto(i,a,b) for (int i=a; i>=b; --i)
#define sci(a) scanf("%d", &a)
#define scii(a,b) scanf("%d%d", &a, &b)
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz(a) (int)a.size()

int n, m, k, l, d[maxN][1 << 6], s[maxN], ans = oo;
vi melon[maxN];
vii ke[maxN];

void init() {
    fto(i, 1, n) fto(j, 0, 64) d[i][j] = oo;
}

int combine(int u, int s) {
//    cout << s << " " << sz(melon[u]) << endl;
    fto(i, 0, sz(melon[u])-1) {
        int a = melon[u][i]-1;
        s |= (1 << a);
    }
    return s;
}

int check(int a) {
    int a_tmp = a, num_a = 0, p = 1;
    while(a_tmp > 0) {p <<= 1; a_tmp >>= 1;}
    while(p > 0) {
        if (p & a) ++num_a;
        p >>= 1;
    }

    return num_a;
}

void dijkstra() {
    priority_queue<pair<int, ii>, vector<pair<int, ii> > >q;

    s[1] = combine(1, 0);
    d[1][s[1]] = 0;
    q.push(mp(0, mp(s[1], 1)));
    while(!q.empty()) {
        ii tmp = q.top().ss;
        int u = tmp.ss, su = tmp.ff, du = -q.top().ff;
        q.pop();

        if (d[u][su] != du) continue;

        if (u == n) {
            if (check(su) >= l && du < ans) ans = du;
        }

        //cout << u << " " << du << " " << su << endl;
        fto(i, 0, sz(ke[u])-1) {
            int v = ke[u][i].ff, dv = ke[u][i].ss;
            int s_tmp = combine(v, su);

            if (d[v][s_tmp] > du + dv) {
                d[v][s_tmp] = du + dv;

                q.push(mp(-d[v][s_tmp], mp(s_tmp, v)));
            }
        }

    }

}

int main() {
    freopen("dhaka.inp", "r", stdin);
    freopen("dhaka.out", "w", stdout);

    scii(n, m); scii(k, l);
    fto(i, 1, n) {
        int s; sci(s);

        fto(j, 1, s) {
            int a; sci(a);
            melon[i].pb(a);
        }
    }
    fto(i, 1, m) {
        int u, v, w;
        scii(u, v); sci(w);

        ke[u].pb(mp(v, w));
        ke[v].pb(mp(u, w));
    }

//    fto(i, 1, n) {
//        cout << "i=" << i << endl;
//        fto(j, 0, sz(melon[i])-1) cout << melon[i][j] << " ";
//        cout << endl;
//    }

    init();
    dijkstra();

    if (ans == oo) cout << -1;
    else cout << ans;
    return 0;
}


