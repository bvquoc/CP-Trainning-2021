#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define Task "CONSTRUCT"

using namespace std;
typedef long long ll;

const int maxn = 1e6 + 5;

ll a[maxn], sum[maxn];
int N, Q, T;

int solve(int l, int r, ll now = 0)
{
    if (l == r){
        return a[l] - now;
    }
    if (l > r) return 0;
    int mi = 1e9;
    vector<int> pos;
    for (int i=l; i<=r; ++i){
        ///assert(a[i] > now);
        if (a[i] == now) continue;
        if (mi > a[i] - now){
            pos.clear();
            pos.pb(i);
            mi = a[i] - now;
        }
        else if (mi == a[i] - now){
            pos.pb(i);
        }
    }
    if (pos.size() == 1){
        ll res = mi;
        if (pos[0] == l){
            res += solve(l+1, r, mi + now);
        }
        else if (pos[0] == r) {
            res += solve(l, r-1, mi + now);
        }
        else {
            res += solve(l, pos[0]-1, mi + now);
            res += solve(pos[0] + 1, r, mi + now);
        }
        return res;
    }
    pos.pb(1e9);
    ll res = mi;
    for (int i=0 ;i<(int)pos.size() - 1; ++i){
        if (i == 0){
            if (pos[i] != l){
                res += solve(l, min(pos[i+1] - 1, r), now + mi);
            }
            else{
                res += solve(l+1, min(pos[i+1] - 1, r), now + mi);
            }
        }
        else{
            if (pos[i+1] != r)
                res += solve(pos[i] + 1, min(pos[i+1] - 1, r), now + mi);
            else res += solve(pos[i]+1, min(pos[i+1] - 1, r - 1), now + mi);
        }
    }
    return res;
}

void read(void)
{
    cin >> N >> Q;
    for (int i=1; i<=N; ++i){
        cin >> a[i];
        sum[i] = 0;
    }
    while (Q--){
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1){
            int val;
            cin >> val;
            sum[l] += val;
            sum[r+1] -= val;
        }
        else{
            for (int i=1; i<=N; ++i){
                sum[i] += sum[i-1];
                a[i] += sum[i];
            }
            for (int i=1; i<=N; ++i){
                sum[i] = 0;
            }
            cout << solve(l, r) << '\n';
        }
    }
}

signed main(void)
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    if (fopen("A.INP", "r")){
        freopen("A.INP", "r", stdin);
        freopen("A.OUT", "w", stdout);
    }
    if (fopen(Task".INP", "r")){
        freopen(Task".INP", "r", stdin);
        freopen(Task".OUT", "w", stdout);
    }
    cin >> T;
    while (T--){
        read();
    }
}
