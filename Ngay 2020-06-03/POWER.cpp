#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
#define int unsigned long long

const int N = 10004;
int n, k, a[N], res = LLONG_MAX;
int minPrime[100000000];

int __lcm(int a, int b) {
    return (a*b)/__gcd(a,b);
}

int sqr(int x) {
    return x*x;
}

int pw(int a, int b) {
    if (b == 0) return 1;
    else {
        if (b % 2 == 0) {
            return sqr(pw(a, b>>1));
        } else {
            return a * (sqr(pw(a, b>>1)));
        }
    }
}

vector<int> factorize (int n) {
    vector<int> res;
    while (n != 1) {
        res.push_back(minPrime[n]);
        n /= minPrime[n];
    }
    return res;
}

int32_t main(void) {
    FastIO;
    freopen("POWER.INP","r",stdin);
    freopen("POWER.OUT","w",stdout);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }

    int bcnn = __lcm(a[1], a[2]);
    for(int i=3; i<=n; i++) {
        bcnn = __lcm(bcnn, a[i]);    
    }

    // for (int i=2; i*i <= bcnn; ++i) {
    //     if (minPrime[i] == 0) {
    //         for (int j=i*i; j<=bcnn; j+=i) {
    //             if (minPrime[j]==0) {
    //                 minPrime[j]=i;
    //             }
    //         }
    //     }
    // }
    // for (int i=2; i<=bcnn; ++i) {
    //     if (minPrime[i]==0) {
    //         minPrime[i]=i;
    //     }
    // }
    
    // for (int x: factorize(bcnn)) {
    //     if (pw((bcnn/x),k)%bcnn == 0) {
    //         res = min(res, (bcnn/x));
    //     }
    // }
    // cout<<res;
    cout<<bcnn;
    return 0;
}