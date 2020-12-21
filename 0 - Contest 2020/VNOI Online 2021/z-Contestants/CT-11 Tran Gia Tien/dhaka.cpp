#include<bits/stdc++.h>

#define bug(a) cout<< #a << ": " << a << endl;
#define bug2(a, b) cout<< #a << ": " << a << ", " << #b << ": " << b << endl;
#define bugarr(a, i, j) cout<< #a << "{" << i << "..." << j << "}: "; fto(k, i, j-1) cout<< a[k] << ", "; cout<< a[j] << endl;
#define fto(i, a, b) for(int i = a; i <= b; ++i)
#define fdto(i, a, b) for(int i = a; i >= b; --i)
#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d %d", &a, &b)
#define pril(a) printf("%d\n", a)
#define pris(a) printf("%d ", a)
#define ll long long
#define ii pair<int, int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vii vector<ii>
#define all(x) (x).begin(), (x).end()
#define oo 1000000007
#define maxN 10005
#define sz(a) (int)a.size()
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define sc(a) cout << "set_check: " << a << '\n'

using namespace std;

int c[maxN][maxN], b[maxN], avail[maxN], visited[maxN], d[maxN], dd[maxN];
int n, m, k, l;
int ans = oo, cnt, cut, pos = 0, w, ok;
vi f[maxN];

int check() {
    cnt = 0;
    w = 0;
    ok = 1;
    fto(i, 1, k) dd[i] = 0;
    fto(u, 1, n) {
        int t = c[b[u]][b[u+1]];
        if (t == oo || t == 0) {
            fto(j, 1, u) {
                fto(o, 0, sz(f[b[j]])-1) {
                int p = f[b[j]][o];
                    if (!dd[p]) {
                        dd[p] = 1;
                        ++cnt;
                    }
                }
            }
            //bug(cnt);
            //bug(w);
            if (b[u] != n) return 0;
            return (cnt >= l);
        }
        else w += t;
    }
    if (ok == 0) return 0;
    return (cnt >= l);
}

void sinhHV(int i) {
    ++pos;
    if (i > n) {
       if (check()) {
            ans = min(ans, w);
       }
        return;
    }
    fto(j, 2, n) {
        if (avail[j]) {
            b[i] = j;
            avail[j] = 0;
            sinhHV(i+1);
            avail[j] = 1;
        }
    }

}

int main () {
    freopen("dhaka.inp", "r", stdin);
    freopen("dhaka.out", "w", stdout);

    scii(n, m);
    scii(k, l);
    fto(i, 1, n) {
        fto(j, 1, n) {
            if (i == j) c[i][j] = 0;
            else c[i][j] = oo;
        }
    }
    fto(i, 1, n) {
        int x;
        sci(x);
        fto(j, 1, x) {
            int r;
            sci(r);
            f[i].pb(r);
        }
    }
    cnt = 0;
    fto(j, 1, n) {
        fto(o, 0, sz(f[j])-1) {
            int p = f[j][o];

            //bugarr(dd, 1, 2);
            if (!dd[p]) {
                dd[p] = 1;
                ++cnt;
            }
        }
    }
    if (cnt < k) {
        puts("-1");
        return 0;
    }
    fto(i, 1, n) {
        int u, v, w;
        scii(u, v);
        sci(w);
        c[u][v] = c[v][u] = w;
        //canh[i].pb(mp(w, mp(u, v)));
    }

    fto(i, 0, n) d[i] = oo;
    d[1] = 0;
    if (l == 0 || k == 1) {
        while(1) {
        int u = 0;
        fto(v, 1, n) if (d[v] < d[u] && visited[v] == 0) u = v;
        if (u == 0) break;
        //bug(u);
        visited[u] = 1;
        fto(v, 1, n) {
            d[v] = min(d[v], d[u] + c[u][v]);
            //bug(c[u][v]);
            }
        }
    cout << d[n] << '\n';

    }
    if (n <= 12) {
        fto(i, 1, n) avail[i] = 1;
        b[1] = 1;
        sinhHV(2);
        if (ans != oo) {
            cout << ans << '\n';
        } else puts("-1");

        //return 0;
    }




    return 0;
}
