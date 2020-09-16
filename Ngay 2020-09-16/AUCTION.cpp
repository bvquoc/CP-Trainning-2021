#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
using namespace std;

using ii = pair <int, int>;
using ld = long double;

const int N = 100005;
bool isPrime[N];

void sieve(int lim) {
    FOR(i,0,lim) isPrime[i] = true;
    isPrime[0] = isPrime[1] = false;
    for(int i=2; i*i<=lim; ++i) {
        if(isPrime[i]) {
            for(int j=i*i; j<=lim; j+=i)
                isPrime[j] = false;
        }
    }
}

int A, B, res = 0;

bool isDoiXung(int x) {
    string cur = "";
    do {
        cur += (x%10) + '0';
        x/=10;
    } while (x!=0);
    
    string newStr = cur;
    reverse(newStr.begin(),newStr.end());

    return cur == newStr;
}

signed main(void) {
    FastIO;
    freopen("AUCTION.INP","r",stdin);
    freopen("AUCTION.OUT","w",stdout);
    cin >> A >> B;

    sieve(B+1);
    FOR(x,A,B) {
        if (isPrime[x] && isDoiXung(x)) {
            res++;
        }
    }

    cout << res;
    return 0;
}