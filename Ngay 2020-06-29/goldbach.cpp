/* http://lqdoj.edu.vn/problem/goldbach */
#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int n, ans = 0;
vector <bool> isPrime;

void sieve() {
    isPrime.assign(n+1,true);
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2; i * i <= n; ++i) {
         if(isPrime[i]) {
             for(int j = i * i; j <= n; j += i)
                 isPrime[j] = false;
        }
    }
}

int32_t main(void) {
    FastIO;
    freopen("goldbach.inp","r",stdin);
    freopen("goldbach.out","w",stdout);
    cin >> n;
    sieve();
    for (int i=2;i<=n/2;i++) {
        if (isPrime[i] && isPrime[n-i]) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}