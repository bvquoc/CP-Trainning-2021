#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;
typedef vector <vi> vvi;

const int N = 5e5 + 5;

int n, m, k;
string s;
pii edges[N];

void readTest(){
    cin >> n >> m >> k;
    cin >> s; s = ' ' + s;
    ForE(i, 1, m){
        cin >> edges[i].fi >> edges[i].se;
    }
}

struct DisjointSetUnion{
    int par[N], cnt[N];

    void reset(){
        memset(par, -1, sizeof(par));
        ForE(i, 1, n){
            cnt[i] = s[i] - '0';
        }
    }

    int root(int u){
        return par[u] < 0 ? u : (par[u] = root(par[u]));
    }

    void merge(int u, int v){
        if ((u = root(u)) == (v = root(v))){
            return;
        }
        if (par[u] > par[v]){
            swap(u, v);
        }
        par[u] += par[v];
        par[v] = u;
        cnt[u] += cnt[v];
        cnt[v] = 0;
    }
} dsu;

int curCnt[N], sum0;

void solveTest(){
    dsu.reset();
    ForE(i, 1, m){
        dsu.merge(edges[i].fi, edges[i].se);
    }
    int ans = 0, tl = -1, tr = -1, r = 0;
    ForE(i, 1, n){
        while (r != n){
            r++; int rt = dsu.root(r);
            curCnt[rt]++;
            if (curCnt[rt] > dsu.cnt[rt]){
                sum0++;
                if (sum0 > k){
                    sum0--;
                    curCnt[rt]--;
                    r--;
                    break;
                }
            }
        }
        if (r - i + 1 > ans){
            ans = r - i + 1;
            tl = i; tr = r;
        }
        int rt = dsu.root(i);
        if (curCnt[rt] > dsu.cnt[rt]){
            sum0--;
        }
        curCnt[rt]--;
    }
    if (ans == 0){
        cout << -1 << endl;
    }
    else{
        cout << tl << ' ' << tr << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("DECOR.inp", "r", stdin);
    freopen("DECOR.out", "w", stdout);
    readTest();
    solveTest();
}

/*
==================================================+
INPUT:                                            |
--------------------------------------------------|
5 3 1
00101
1 2
2 3
3 5
--------------------------------------------------|
5 0 3
11010
--------------------------------------------------|
==================================================+
OUTPUT:                                           |
--------------------------------------------------|
1 3
--------------------------------------------------|
1 5
--------------------------------------------------|
==================================================+
*/
