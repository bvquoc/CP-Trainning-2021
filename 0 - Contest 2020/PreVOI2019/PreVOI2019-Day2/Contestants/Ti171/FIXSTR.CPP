#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) ( (int)(x).size() )
#define fi first
#define se second
using LL = long long;

string s;
int m;
vector<int> root;

struct Info {
    int open, close;
    Info(int _open = 0, int _close = 0) : open(_open), close(_close) {}
    Info operator + (const Info& _) const { return open > _.close ?
                                                   Info(_.open + open - _.close, close) :
                                                   Info(_.open, close + _.close - open); }
};

struct Node {
    int lC, rC;
    Info info;
    Node() { lC = rC = 0; info = Info(); }
};

struct It {
    vector<Node> node;
    It() {
        node.assign(1, Node() );
    }

    void build(int i, int Left = 0, int Right = sz(s) - 1) {
        if (Left == Right) {
            node[i].info = (s[Left] == '(' ? Info(1, 0) : Info(0, 1) );
            return ;
        }
        int Mid = (Left + Right) >> 1;
        if (!node[i].lC) { node[i].lC = sz(node); node.emplace_back(Node() ); }
        if (!node[i].rC) { node[i].rC = sz(node); node.emplace_back(Node() ); }
        build(node[i].lC, Left, Mid);
        build(node[i].rC, Mid + 1, Right);
        node[i].info = node[ node[i].lC ].info + node[ node[i].rC ].info;
    }

    void upd(int pos, int i, int oldI, int Left = 0, int Right = sz(s) - 1) {
        if (Left == Right) {
            node[i] = node[oldI];
            swap(node[i].info.open, node[i].info.close);
            return ;
        }
        int Mid = (Left + Right) >> 1;
        if (pos <= Mid) {
            node[i].lC = sz(node); node.emplace_back(Node() );
            node[i].rC = node[oldI].rC;
            upd(pos, node[i].lC, node[oldI].lC, Left, Mid);
        }
        else {
            node[i].rC = sz(node); node.emplace_back(Node() );
            node[i].lC = node[oldI].lC;
            upd(pos, node[i].rC, node[oldI].rC, Mid + 1, Right);
        }
        node[i].info = node[ node[i].lC ].info + node[ node[i].rC ].info;
    }

    Info get(int l, int r, int i, int Left = 0, int Right = sz(s) - 1) {
        if (l <= Left && Right <= r) return node[i].info;
        int Mid = (Left + Right) >> 1;
        if (Mid < l) return get(l, r, node[i].rC, Mid + 1, Right);
        else if (r <= Mid) return get(l, r, node[i].lC, Left, Mid);
        else return get(l, r, node[i].lC, Left, Mid) + get(l, r, node[i].rC, Mid + 1, Right);
    }
} it;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("FIXSTR.INP", "r", stdin);
    freopen("FIXSTR.OUT", "w", stdout);

    cin >> s >> m;

    root.emplace_back(0);
    it.build(root[0]);

    for (int i = 0; i < m; ++i) {
        char type; int l; cin >> type >> l; --l;
        if (type == 'C') {
            root.emplace_back(sz(it.node) ); it.node.emplace_back(Node() );
            it.upd(l, root.back(), *(root.end() - 2) );
        }
        else if (type == 'Q') {
            int r; cin >> r; --r;
            Info tmp = it.get(l, r, root.back() );
            cout << tmp.open + tmp.close << '\n';
            root.emplace_back(root.back() );
        }
        else root.emplace_back(root[l]);
    }

    return 0;
}

