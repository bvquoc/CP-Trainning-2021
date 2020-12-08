#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
#define sz(x) ( (int)(x).size() )
#define fi first
#define se second
using LL = long long;

int n, k;
vector<int> lead;

struct Dsu {
    vector<int> pSet, col;
    Dsu(int nSet) {
        pSet.assign(nSet, 0); iota(all(pSet), 0);
        col.assign(nSet, -1);
    }
    int findSet(int i) { return i == pSet[i] ? i : pSet[i] = findSet(pSet[i]); }
    void unite(int i, int j, int c) {
        i = findSet(i); j = findSet(j);
        if (i == j) {
            lead[ col[i] ] = -1;
            col[i] = c;
            lead[ col[i] ] = i;
        }
        else {
            lead[ col[i] ] = -1; lead[ col[j] ] = -1;
            pSet[i] = j;
            col[j] = c;
            lead[ col[j] ] = j;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("PAINT.INP", "r", stdin);
    freopen("PAINT.OUT", "w", stdout);

    cin >> n;

    lead.assign(26, -1);
    Dsu dsu(n);

    while (n--) {
        int type; char cX; cin >> type >> cX;
        int x = cX - 'a';
        if (type == 1) {
            dsu.col[k] = x;
            if (lead[x] == -1) lead[x] = k;
            else dsu.unite(lead[x], k, x);
            ++k;
        }
        else {
            char cY; cin >> cY;
            int y = cY - 'a';
            if (lead[x] != -1) dsu.unite(lead[x], lead[y] == -1 ? lead[x] : lead[y], y);
        }
    }

    for (int i = 0; i < k; ++i) cout << (char)(dsu.col[ dsu.findSet(i) ] + 'a');

    return 0;
}

