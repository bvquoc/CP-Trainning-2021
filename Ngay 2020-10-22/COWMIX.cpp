#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
using namespace std;

using ii = pair <int, int>;
using ll = long long;
using ld = long double;

const int N = 21;
int n, k, a[N];
vector <int> hv;
ll res = 0;

signed main(void) {
    FastIO;
    freopen("COWMIX.INP","r",stdin);
    freopen("COWMIX.OUT","w",stdout);
    cin >> n >> k;
    FOR(i,0,n-1) {
        cin >> a[i];
        hv.push_back(i);
    }
    do {
        bool ok = true;
        FOR(i,0,hv.size()-2) {
            if (abs(a[hv[i]]-a[hv[i+1]])<=k) {
                ok = false;
                break;
            }
        }
        if (ok) res++;
    } while (next_permutation(hv.begin(),hv.end()));
    cout << res;
    return 0;
}