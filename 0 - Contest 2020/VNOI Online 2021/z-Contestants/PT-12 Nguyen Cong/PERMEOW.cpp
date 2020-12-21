#include <bits/stdc++.h>
using namespace std;

#define int long long
int n, A[200010], B[200010];
int BIT[200010];

void Update(int u, int val) {
    if(u == 0) return;
    while(u) {
        BIT[u] += val;
        u -= u & -u;
    }
    return;
}

int Get(int u) {
    int Res = 0;
    while(u <= 200000) {
        Res += BIT[u];
        u += u & -u;
    }
    return Res;
}
const int mod = 1e9 + 7;
int Pow(int a, int b)
{
    int ans = 1, temp = a;
    while(b)
    {
        if(b & 1)
            ans = 1LL * ans * temp % mod;
        b >>= 1;
        temp = 1LL * temp * temp % mod;
    }
    return ans;
}


main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("PERMEOW.inp", "r", stdin);
    freopen("PERMEOW.out", "w", stdout);

    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> A[i];
    }
    int ok = 1;
    for(int i = 1; i <= n; i ++) {
        cin >> B[i];
        if(B[i] != A[i]) ok = 0;
    }
    if(ok == 0) {
        int Ans = 0;
        for(int i = 1; i <= n ; i ++) {
            Ans += Get(A[i]);
            Update(A[i], 1);
        }
        cout << Ans << endl;
    } else {


    int SS = 1;
    for(int i = 1; i <= n; i ++) {
        SS = (1LL * SS * i) % mod;
    }
    int WW = 1LL * SS * Pow(6, mod - 2) % mod;
    int ANS1 = 9LL * WW % mod;
//    cout << ANS1 << endl;
//    cout << (WW - 1 + mod) % mod << endl;
    int VV = 6LL * ((1LL * ((WW - 1 + mod) % mod) * WW % mod) * Pow(2, mod - 2) % mod) % mod;

    cout << (ANS1 + VV) % mod;
    }


}
