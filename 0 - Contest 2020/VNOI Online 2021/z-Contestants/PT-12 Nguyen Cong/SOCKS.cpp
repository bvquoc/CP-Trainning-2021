#include <bits/stdc++.h>
using namespace std;

#define MAXN 500010
int n, q;
int VNUM = 0;
int A[MAXN];
vector <int> Adj[MAXN];
int IN[MAXN], OUT[MAXN];
int cnt = 0;

void DFS(int u, int pa) {
    IN[u] = ++ cnt;
    for(auto v : Adj[u]) {
        if(v == pa) continue;
        DFS(v, u);
    }
    OUT[u] = cnt;
}


int numNode;
int Tree[2000010];

void Update(int i, int l, int r, int pos, int val)
{
    if (l > r)
        return;
    if(l == r && l == pos)
    {
        Tree[i] = val;
        return;
    }

    int mid = (l + r )/ 2;
    if(pos <= mid)
        Update(2 * i, l, mid, pos, val);
    else
        Update(2 * i + 1, mid + 1, r, pos, val);

    Tree[i] = Tree[2 * i] + Tree[2 * i + 1];
}

int Get(int i, int l, int r, int u, int v)
{
    if(l > r)
        return 0;
    if(v < l || r < u)
        return 0;
    if(u <= l && r <= v)
        return Tree[i];
    int mid = (l + r) / 2;
    return (Get(2 * i, l, mid, u, v) + Get(2 * i + 1, mid + 1, r, u, v));
}

main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("SOCKS.inp", "r", stdin);
    freopen("SOCKS.out", "w", stdout);

    cin >> n >> q;
    for(int i = 1; i <= n; i ++)
    {
        cin >> A[i];
    }

    for(int i = 1; i < n; i ++)
    {
        int u, v;
        cin >> u >> v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
    }
    DFS(1,1);
//    for(int i = 1; i <= n; i ++) {
//
//        cout << "ID : " << i << " " << IN[i] << " " << OUT[i] << endl;
//    }
    for(int i = 1; i <= n; i ++)
    {
        if(A[i])
        {
            VNUM ++;
            Update(1, 1, n, IN[i], 1);
        }
    }
    int Res = 0;
    for(int i = 1; i <= n; i ++)
    {
        int sl = Get(1, 1, n, IN[i] + 1, OUT[i]);
        if(sl == 0 && A[i] == 1) {
            Res ++;
            continue;
        }
        if(Tree[1] - Get(1, 1, n, IN[i], OUT[i]) == 0 && A[i] == 1) {
            Res ++;
        }
    }
    if(VNUM == 1) {
        cout << 0 << '\n';
    } else
        cout << (Res + 1) / 2 << '\n';
    while(q --) {
        int u;
        cin >> u;
        if(A[u] == 1) {
            if(Get(1, 1, n, IN[u] + 1, OUT[u]) == 0) Res --;
            else {
                if(Tree[1] - Get(1, 1, n, IN[u], OUT[u]) == 0) {
                    Res --;
                }
            }
            VNUM --;
            A[u] = 0;
            Update(1, 1, n, IN[u], 0);
        } else {
//            cout << "INDEX " << u << endl;
            if(Get(1, 1, n, IN[u] + 1, OUT[u]) == 0) {
                Res ++;
//                cout << ",." << endl;
            }
            else {
                if(Tree[1] - Get(1, 1, n, IN[u], OUT[u]) == 0) {
                    Res ++;
                }
            }
            VNUM ++;
            A[u] = 1;
            Update(1, 1, n, IN[u], 1);
        }
        if(VNUM == 1) {
            cout << 0 << '\n';
        } else {
            cout << (Res + 1) / 2 << '\n';
        }
    }
}
