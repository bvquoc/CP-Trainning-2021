#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) ( (int)(x).size() )
#define fi first
#define se second
using LL = long long;

int nTest, n, m;
vector<int> a;

struct Node {
    LL res, l, r;
    Node(LL _res = 0, LL _l = 0, LL _r = 0) : res(_res), l(_l), r(_r) {}
    Node operator + (const Node& _) const { return Node(res + _.res - min(r, _.l), l, _.r); }
};

struct It {
    vector<Node> node;
    vector<LL> lz;
    It(int nNode) {
        node.assign(nNode, Node() );
        lz.assign(nNode, 0);
    }

    void build(int i = 1, int Left = 0, int Right = n - 1) {
        if (Left == Right) {
            node[i] = Node(a[Left], a[Left], a[Left]);
            return ;
        }
        int Mid = (Left + Right) >> 1;
        build(i << 1, Left, Mid); build(i << 1 | 1, Mid + 1, Right);
        node[i] = node[i << 1] + node[i << 1 | 1];
    }

    void trueVal(int i, int Left, int Right) {
        if (!lz[i]) return ;
        node[i].res += lz[i];
        node[i].l += lz[i];
        node[i].r += lz[i];
        if (Left != Right) {
            lz[i << 1] += lz[i];
            lz[i << 1 | 1] += lz[i];
        }
        lz[i] = 0;
    }

    void add(int l, int r, int val, int i = 1, int Left = 0, int Right = n - 1) {
        trueVal(i, Left, Right);
        if (r < Left || Right < l) return ;
        if (l <= Left && Right <= r) {
            lz[i] = val; trueVal(i, Left, Right);
            return ;
        }
        int Mid = (Left + Right) >> 1;
        add(l, r, val, i << 1, Left, Mid);
        add(l, r, val, i << 1 | 1, Mid + 1, Right);
        node[i] = node[i << 1] + node[i << 1 | 1];
    }

    Node get(int l, int r, int i = 1, int Left = 0, int Right = n - 1) {
        trueVal(i, Left, Right);
        if (l <= Left && Right <= r) return node[i];
        int Mid = (Left + Right) >> 1;
        if (Mid < l) return get(l, r, i << 1 | 1, Mid + 1, Right);
        else if (r <= Mid) return get(l, r, i << 1, Left, Mid);
        else return get(l, r, i << 1, Left, Mid) + get(l, r, i << 1 | 1, Mid + 1, Right);
    }
};

void Main() {
    cin >> n >> m;
    a.assign(n, 0);
    for (int i = 0; i < n; ++i) cin >> a[i];

    It it( (n + 5) << 2);
    it.build();

    while (m--) {
        int type, l, r; cin >> type >> l >> r; --l; --r;

        if (type == 1) {
            int k; cin >> k;
            it.add(l, r, k);
        }
        else cout << it.get(l, r).res << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("construct.INP", "r", stdin);
    freopen("construct.OUT", "w", stdout);

    cin >> nTest;
    while (nTest--) Main();

    return 0;
}

