#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr);
#define fi first
#define se second
using namespace std;

using ii = pair <int,int>;
using ll = long long;
using ld = long double;

const int N = 100005;
int n, a[N], b[N];
int res = 0;

signed main() {
    FastIO;
    freopen("IQ.INP","r",stdin);
    freopen("IQ.OUT","w",stdout);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> b[i];
    for (int i=1; i<=n; i++) cin >> a[i];

    if (n<=10) { // Subtask 1
        vector <int> x(1); int cur;
        for (int i=1; i<=n; i++) x.push_back(i);
        do {
            cur = 0;
            for (int i=1; i<=n; i++)
            if (a[i]>b[x[i]]) {
                cur++;
            }
            if (res<cur) res = cur;
        } while (next_permutation(x.begin()+1,x.end()));
        cout << res;
        return 0;
    }

    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    int j = 1;
    for (int i=1; i<=n; i++) {
        if (a[i]>b[j]) {
            res++;
            j++;
        }
    }
    cout << res;
    return 0;
}
