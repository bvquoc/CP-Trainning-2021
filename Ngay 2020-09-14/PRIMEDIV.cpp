#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
#define int long long
using namespace std;

using ii = pair <int, int>;
using ld = long double;

const int N = 1000006;
bool isPrime[N];
vector <int> primes;

void sieve(int n) {
    FOR(i,0,n) isPrime[i] = true;
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i*i<=n; ++i) {
        if(isPrime[i]) {
            for(int j = i*i; j<=n; j+=i) isPrime[j] = false;
        }
    }
    FOR(i,2,n) {
        if (isPrime[i]) primes.push_back(i);
    }
}

set<int> factorize(int n) {
    set <int> res;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            res.insert(i);
            n /= i;
        }
    }
    if (n != 1) {
        res.insert(n);
    }
    return res;
}


signed main(void) {
    FastIO;
    freopen("PRIMEDIV.INP","r",stdin);
    freopen("PRIMEDIV.OUT","w",stdout);
    int n;
    cin >> n;
    set <int> res = factorize(n);
    for (int x: res) cout << x << ' ';

    return 0;
}