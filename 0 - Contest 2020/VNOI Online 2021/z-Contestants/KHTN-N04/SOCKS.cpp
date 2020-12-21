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

int n, q;
bool a[N];
pii edges[N];
int queries[N];

vi adj[N];

void readTest(){
    cin >> n >> q;
    ForE(i, 1, n){
        cin >> a[i];
    }
    For(i, 1, n){
        cin >> edges[i].fi >> edges[i].se;
        adj[edges[i].fi].push_back(edges[i].se);
        adj[edges[i].se].push_back(edges[i].fi);
    }
    ForE(i, 1, q){
        cin >> queries[i];
    }
}

// SUBTASK 1 ====================================

bool checkTest1(){
    ForE(i, 1, n){
        if (isz(adj[i]) > 2){
            return 0;
        }
    }
    return 1;
}

void solveTest1(){
    int cntRed = 0;
    ForE(i, 1, n){
        if (a[i]){
            cntRed++;
        }
    }
    cout << (cntRed <= 1 ? 0 : 1) << endl;
    ForE(i, 1, q){
        if (a[queries[i]]){
            a[queries[i]] = 0;
            cntRed--;
        }
        else{
            a[queries[i]] = 1;
            cntRed++;
        }
        cout << (cntRed <= 1 ? 0 : 1) << endl;
    }
}

// SUBTASK 2 ====================================

bool checkTest2(){
    bool isz3 = 0;
    ForE(i, 1, n){
        if (isz(adj[i]) > 2){
            if (isz(adj[i]) == 3){
                if (!isz3){
                    isz3 = 1;
                }
                else{
                    return 0;
                }
            }
            else{
                return 0;
            }
        }
    }
    return isz3;
}

int type2[N];

void dfs2(int u, int p, int t){
    type2[u] = t;
    Fora(&v, adj[u]){
        if (v == p){
            continue;
        }
        dfs2(v, u, t);
    }
}

void solveTest2(){
    ForE(i, 1, n){
        type2[i] = 0;
    }
    int root;
    ForE(i, 1, n){
        if (isz(adj[i]) == 3){
            root = i;
            break;
        }
    }
    int tmpT = 0;
    Fora(&v, adj[root]){
        dfs2(v, root, ++tmpT);
    }
    int cntRed = 0;
    int redType[4] = {0, 0, 0, 0};
    ForE(i, 1, n){
        if (a[i]){
            cntRed++;
            redType[type2[i]]++;
        }
    }
    if (cntRed <= 1){
        cout << 0 << endl;
    }
    else if (!redType[1] || !redType[2] || !redType[3]){
        cout << 1 << endl;
    }
    else{
        cout << 2 << endl;
    }
    ForE(i, 1, q){
        if (a[queries[i]]){
            a[queries[i]] = 0;
            cntRed--;
            redType[type2[queries[i]]]--;
        }
        else{
            a[queries[i]] = 1;
            cntRed++;
            redType[type2[queries[i]]]++;
        }
        if (cntRed <= 1){
            cout << 0 << endl;
        }
        else if (!redType[1] || !redType[2] || !redType[3]){
            cout << 1 << endl;
        }
        else{
            cout << 2 << endl;
        }
    }
}

// SUBTASK 3 ====================================

bool checkTest3(){
    return n <= 1000 && q <= 1000;
}

int deg3[N];
bool erased[N];

void solveQuery3(){
    ForE(i, 1, n){
        deg3[i] = isz(adj[i]);
        erased[i] = 0;
    }
    vi leaves;
    ForE(i, 1, n){
        if (deg3[i] == 1){
            leaves.push_back(i);
        }
    }
    while (isz(leaves)){
        int u = leaves.back(); leaves.pop_back();
        if (a[u]){
            continue;
        }
        int neighbour;
        Fora(&v, adj[u]){
            if (!erased[v]){
                neighbour = v;
                break;
            }
        }
        deg3[u]--;
        deg3[neighbour]--;
        erased[u] = 1;
        if (deg3[neighbour] == 1){
            leaves.push_back(neighbour);
        }
    }
    int cntLeaves = 0;
    ForE(i, 1, n){
        if (deg3[i] == 1){
            cntLeaves++;
        }
    }
    cout << (cntLeaves + 1) / 2 << endl;
}

void solveTest3(){
    solveQuery3();
    ForE(i, 1, q){
        if (a[queries[i]]){
            a[queries[i]] = 0;
        }
        else{
            a[queries[i]] = 1;
        }
        solveQuery3();
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("SOCKS.inp", "r", stdin);
    freopen("SOCKS.out", "w", stdout);
    readTest();
    if (checkTest1()){
        solveTest1();
    }
    else if (checkTest2()){
        solveTest2();
    }
    else if (checkTest3()){
        solveTest3();
    }
}

/*
==================================================+
INPUT:                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT:                                           |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/
