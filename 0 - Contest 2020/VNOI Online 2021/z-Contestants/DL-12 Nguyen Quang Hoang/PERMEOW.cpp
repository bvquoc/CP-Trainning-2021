#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
int n, a[200002], b[200002];
ll ans;
void sub1() {
    ans = 0;
    for(int i = 1; i <= n; ++ i) {
        if(b[i] == i) continue;
        for(int j = n; j >= i; -- j) {
            if(b[j] == i) {
                while(j != i) {
                    ans = (ans + 1ll) % mod;
                    swap(b[j], b[j - 1]);
                    -- j;
                }
                break;
            }
        }
    }
    cout << ans;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen("test.inp", "r"))
        freopen("test.inp", "r", stdin);
    else {
        #define file "PERMEOW"
        freopen(file".INP", "r", stdin);
        freopen(file".OUT", "w", stdout);
    }
    cin >> n;
    for(int i = 1; i <= n; ++ i) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; ++ i) {
        cin >> b[i];
    }
    sub1();
    return 0;
}
