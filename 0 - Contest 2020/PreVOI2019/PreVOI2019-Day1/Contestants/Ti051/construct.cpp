#include<bits/stdc++.h>
#define nmax 100005
#define task "construct"

using namespace std;
typedef long long ll;

int n, m;
ll H[nmax];

void Enter() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> H[i];
    H[0] = 0;
}

void Add(const int &l, const int &r, const int k) {
    for(int i = l; i <= r; i++)
        H[i] += k;
}

ll Query(int l, int r) {
    ll res = H[l];
    for(int i = l + 1; i <= r; i++)
        if(H[i] > H[i - 1])
            res += (H[i] - H[i - 1]);
    return res;
}

void Solve() {
    while(m--) {
        int x, l, r, k;
        cin >> x >> l >> r;
        if(x == 1) {
            cin >> k;
            Add(l, r, k);
        }
        else
            cout << Query(l, r) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        Enter();
        Solve();
    }
}
