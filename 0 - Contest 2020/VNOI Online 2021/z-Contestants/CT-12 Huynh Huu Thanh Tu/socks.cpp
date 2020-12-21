#include <bits/stdc++.h>
using namespace std;

#define oo 1000000007
#define maxN 20010
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

int n, q, sock[maxN], deg[maxN], vt[maxN], par[maxN], num[5];
vi ke[maxN];

void solve1() {
    int num_sock = 0;
    fto(i, 1, n)
        if (sock[i]) ++num_sock;
    fto(i, 0, q) {
        if (i != 0) {
            int u; sci(u);
            if (sock[u] == 1) {
                sock[u] = 0;
                --num_sock;
            }
            else {
                sock[u] = 1;
                ++num_sock;
            }

        }

        if (num_sock <= 1) cout << 0 << endl;
        else cout << 1 << endl;
    }
}

void down(int u, int id) {
    if (sock[u] == 1) ++num[id];
    if (deg[u] == 1) return;
    vt[u] = id;
    //cout << u << " " << id << endl;
    fto(i, 0, sz(ke[u])-1) {
        int v = ke[u][i];
        if (par[u] != v) {
            par[v] = u;
            down(v, id);
        }
    }
}

void solve2() {
    int root = 0;
    fto(i, 1, n)
        if (deg[i] == 3) {root = i; break;}

    int cnt = 0;
    fto(i, 0, sz(ke[root])-1) {
        int u = ke[root][i];
        down(u, cnt);
        ++cnt;
    }

    fto(i, 0, q) {
        //cout << i << " ";
        int check1 = num[0], check2 = num[1], check3 = num[2], ok = 0;
        if (i != 0) {
            int u; sci(u);
            if (sock[u] == 1) {
                    sock[u] = 0;
                    --num[vt[u]];
            }
            else {
                sock[u] = 1;
                --num[vt[u]];

            }

        }
        int res = 0;
        if (check1 >= 1) {
            ++res;
            if (check1 == 1) ++ok;
        }
        if (check2 >= 1) {
            ++res;
            if (check2 == 1) ++ok;
        }
        if (check3 >= 1) {
            ++res;
            if (check1 == 1) ++ok;
        }

        //cout << res << endl;
        if (res == 1 || res == 3) cout << res - (ok > 0) << endl;
        else if (res == 2) cout << res << endl;

    }

}

void solve3() {
    fto(i, 1, q) cout << 1 << endl;
}

int main() {
    freopen("socks.inp", "r", stdin);
    freopen("socks.out", "w", stdout);

    scii(n, q);
    fto(i, 1, n) sci(sock[i]);


    fto(i, 1, n-1) {
        int u, v; scii(u, v);
        ke[u].pb(v); ke[v].pb(u);

        ++deg[u]; ++deg[v];
    }

    int id = 1, cnt = 0, no = 0;
    fto(i, 1, n) {
        if (deg[i] == 3) ++cnt;
        if (deg[i] >= 3) no = 1;
    }

    if (!no) solve1();
    else if (cnt == 1) solve2();
    else solve3();

    return 0;
}


