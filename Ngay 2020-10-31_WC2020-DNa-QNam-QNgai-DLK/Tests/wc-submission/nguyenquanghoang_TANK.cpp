#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k, ans;
ll a[100009];
bool check(int x) {
    for(int i = x; i <= n; ++ i) {
        if(a[i] - a[i - x] < k) return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> k >> n;
    for(int i = 1; i <= n; ++ i) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    int l = 1, r = n + 1, m = (l + r) / 2;
    while(l != m && m != r) {
        if(check(m)) r = m;
        else l = m;
    }
    for(int i = l; i <= r; ++ i) {
        if(check(i)) {
            cout << i;
            return 0;
        }
    }
}
