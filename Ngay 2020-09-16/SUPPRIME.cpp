#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
using namespace std;

using ii = pair <int, int>;
using ld = long double;

const int N = 100005;
int n;
bool mark[N];

signed main() {
    FastIO;
    freopen("SUPPRIME.INP","r",stdin);
    freopen("SUPPRIME.OUT","w",stdout);
    cin >> n;
    mark[1]=true;
    for (int i=1; i*i<=100000; i++) {
        if (!mark[i]) {
            for (int j=i*i; j<=100000; j+=i) {
                mark[j] = true;
            }
        }
    }

    int u = 0, v = 2, l = 0;
    while (u!=n) {
        if (!mark[v]) {
            l++;
            if (!mark[l]) {
                u++;
            }
        }
        v++;
    }
    cout << v-1;
    return 0;
}