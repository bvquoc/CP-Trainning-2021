#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t, n, d[1000009], cnt[1000009], u, v, ans;
vector<int> p;
void sang() {
    for(int i = 1; i <= 1e6 + 5; ++ i) d[i] = i;
    d[0] = d[1] = 0;
    for(int i = 2; i <= 1e6 + 5; ++ i) {
        if(d[i] == i) {
            if(i > 1000) continue;
            for(int j = i * i; j <= 1e6 + 5; j += i) {
                d[j] = i;
            }
        }
    }
}
void sparse(int x) {
    while(x > 1) {
        int res = d[x];
        ++ cnt[res];
        if(cnt[res] == 1) p.push_back(res);
        x /= res;
    }
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    sang();
    cin >> t;
    while(t --) {
        u = 1;
        v = 1;
        cin >> n;
        sparse(n);
        sparse(n + 1);
        sparse(n + 2);
        for(int i : p) {
            //cout << i << '\n';
            u *= 2 * cnt[i] + 1;
            v *= (cnt[i] + 1);
            cnt[i] = 0;
        }
        //cout << u << ' ' << v << '\n';
        ans = u / 2 + 1 - v;
        cout << ans << '\n';
        p.clear();
    }
    return 0;
}
