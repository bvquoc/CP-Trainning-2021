#include<bits/stdc++.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define pri(a) printf("%d ", a)
#define pril(a) printf("%d\n", a)
#define fto(i, a, b) for(int i = a; i <= b; ++i)
#define fdto(i, a, b) for(int i = a; i >= b; --i)
#define vi vector<int>
#define pb push_back
#define sz(a) (int)a.size()
#define pi pair<int, int>
#define ff first
#define sd second
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ld long double
#define oo 1000000007
#define maxN 500005

using namespace std;

int n, q, color[maxN], deg[maxN], dep[maxN];
vi ke[maxN];

void solveS1() {
    int cnt = 0;
    fto(i, 1, n) if(color[i]) ++cnt;
    ++q;
    while(q--) {
        if(cnt <= 1) pril(0);
        else pril(1);

        if(q > 0) {
            int x;
            sci(x);
            color[x] = (color[x] + 1) % 2;
            if(color[x]) ++cnt;
            else --cnt;
        }
    }
}

int root, cnt_nhanh[4], id_nhanh[4];

int dfs(int u, int p, int nhanh) {
    if(u != root) id_nhanh[u] = nhanh;
    int sz_con = color[u];
    fto(i, 0, sz(ke[u])-1) {
        int v = ke[u][i];
        if(v != p) {
            if(u == root) cnt_nhanh[i] = dfs(v, u, i);
            else sz_con += dfs(v, u, i);
        }
    }
    return sz_con;
}

void solveS2() {
    fto(i, 1, n) if(deg[i] == 3) root = i;
    dfs(root, 0, 0); ++q;
    while(q--) {
        int sum = 0;
        if(cnt_nhanh[0]) ++sum;
        if(cnt_nhanh[1]) ++sum;
        if(cnt_nhanh[2]) ++sum;
        if(sum <= 1) pril(0);
        if(sum == 2) pril(1);
        if(sum == 3) pril(2);

        if(q > 0) {
            int x;
            sci(x);
            color[x] = (color[x] + 1) % 2;
            if(color[x]) ++cnt_nhanh[id_nhanh[x]];
            else --cnt_nhanh[id_nhanh[x]];
        }
    }
}

int heavy[maxN];

int dfs2(int u, vi &vs, vi &ex) {
    vs[u] = 1;
    int sz = color[u], mx_con = 0;
    if(ex[u]) sz = 0;
    heavy[u] = -1;
    fto(i, 0, sz(ke[u])-1) {
        int v = ke[u][i];
        if(!vs[v]) {
            int sz_con = dfs2(v, vs, ex);
            if(mx_con < sz_con) {
                mx_con = sz_con;
                heavy[u] = v;
            }
            sz += sz_con;
        }
    }
    return sz;
}

void dfs_heavy(int u, vi &vs) {
    vs[u] = 1;
    if(heavy[u] != -1) dfs_heavy(heavy[u], vs);
}

void get_dep(int u) {
    fto(i, 0, sz(ke[u])-1) {
        int v = ke[u][i];
        if(!dep[v]) {
            dep[v] = dep[u] + 1;
            get_dep(v);
        }
    }
}

struct Node {
    int id;
    bool operator < (const Node &o) const {
        return dep[id] < dep[o.id];
    }
};
Node make_node(int id) {Node x = {id}; return x;}

void vet() {
    set<Node> s;
    fto(i, 1, n) if(color[i]) s.insert(make_node(i));
    ++q;
    while(q--) {
        int ans = 0;

        if(s.size() <= 1) {
            pril(0);
            continue;
        }

        vi vs1(n+2, 0);
        for(set<Node>::iterator it = s.begin(); it != s.end(); ++it) {
            if(!vs1[(*it).id]) {
                ++ans;
                vi vs2(n + 2, 0);
                dfs2((*it).id, vs2, vs1);
                dfs_heavy((*it).id, vs1);
            }
        }

        pril(ans);
        if(q > 0) {
            int x;
            sci(x);
            color[x] = (color[x] + 1) % 2;
            if(color[x]) s.insert(make_node(x));
            else s.erase(make_node(x));
        }
    }
}

int main() {
    freopen("socks.inp", "r", stdin);
    freopen("socks.out", "w", stdout);

    scii(n, q);
    fto(i, 1, n) sci(color[i]);

    fto(i, 1, n-1) {
        int u, v;
        scii(u, v);
        ke[u].pb(v);
        ke[v].pb(u);
        ++deg[v];
        ++deg[u];
    }

    dep[1] = 1;
    get_dep(1);

    bool is_T1 = 1;
    fto(i, 1, n) if(deg[i] > 2) is_T1 = 0;

    bool is_T2 = 1;
    int cnt = 0;
    fto(i, 1, n) {
        if(deg[i] > 3) is_T2 = 0;
        if(deg[i] == 3) ++cnt;
    }
    if(cnt != 1) is_T2 = 0; 
    
    if(is_T1) {
        solveS1();
        return 0;
    }

    if(is_T2) {
        solveS2();
        return 0;
    }

    vet();

    return 0;
}