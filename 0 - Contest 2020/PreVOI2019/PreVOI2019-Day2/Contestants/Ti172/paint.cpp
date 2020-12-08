// Ssusanoo

#include <bits/stdc++.h>
#define N 1000010
#define mod
#define LL long long
#define fi first
#define se second
#define MP make_pair
#define pii pair <int, int>
#define endl "\n"
#define Task "paint"

using namespace std;

int q, cnt;
int d[N];
string res;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);

    cin >> q;
    vector < pii > g1[q + 1], g[q + 1];
    while ( q-- ) {
        int type; cin >> type;
        if ( type == 1 ) {
            char cl; cin >> cl;
            d[++cnt] = cl - 97;
            g[cl - 97].push_back(MP(cnt, cl - 97));
        }
        else {
            char cl1, cl2; cin >> cl1 >> cl2;
            if ( cl1 == cl2 ) continue;
            g[cl1 - 97].push_back(MP(0, cl2 - 97));
            g1[cl1 - 97].push_back(MP(cnt, cl2 - 97));
        }
    }
    for (int i = cnt; i >= 1; i--) {
        int vt = d[i];
        pii top = g[vt].back();
        g[vt].pop_back();
        if ( top.fi == 0 ) {
            pii top1 = g[vt].back(); g[vt].pop_back();
            if ( top1.fi == 0 ) {
                res += (char)(top1.se + 97);
                g[vt].pop_back();
                g[vt].push_back(top1);
            }
            else {
                res += (char)(top.se + 97);
                g[vt].push_back(top);
            }
        }
        else res += char(top.se + 97);
    }
    for (int i = 0; i < cnt; i++) {
        int vt1 = i;
        while ( true ) {
            int vt = res[i] - 97;
            for (int j = 0; j < g1[vt].size(); j++)
                if ( g1[vt][j].fi >= cnt - vt1 ) {
                    res[i] = (char)(g1[vt][j].se + 97);
                    vt1 = g1[vt][j].fi;
                    break;
                }
            if ( (res[i] - 97) == vt ) break;
        }
    }
    reverse(res.begin(), res.end());
    cout << res;

    return 0;
}
