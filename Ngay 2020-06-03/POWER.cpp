#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
#define int unsigned long long

const int N = 10004, A_i = 44;
int n, k, a[N], cnt[A_i];
int res = 1;

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

int32_t main() {
    FastIO;
    freopen("POWER.INP","r",stdin);
    freopen("POWER.OUT","w",stdout);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
    }

    vector <int> primes;
    primes.push_back(2);
    primes.push_back(3);
    primes.push_back(5);
    primes.push_back(7);
    primes.push_back(11);
    primes.push_back(13);
    primes.push_back(17);
    primes.push_back(19);
    primes.push_back(23);
    primes.push_back(29);
    primes.push_back(31);
    primes.push_back(37);
    primes.push_back(41);
    primes.push_back(43);

    for (int i=1; i<=n; i++) {
        for (int j: primes) {
            int cur = 0;
            while (a[i]%j == 0) {
                cur++;
                a[i] /= j;
            }
            cnt[j] = max(cnt[j], cur);
        }
    }

    for (int i: primes) {
        if (cnt[i]) {
            res *= pw(i,(cnt[i]+k-1)/k);
        }
    }

    cout << res;
    return 0;
}

// #include <bits/stdc++.h>
// #define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
// using namespace std;
// #define int unsigned long long

// const int N = 10004;
// int n, k, a[N], res;

// int __lcm(int a, int b) {
//     return (a*b)/__gcd(a,b);
// }

// int sqr(int x) {
//     return x*x;
// }

// int pw(int a, int b) {
//     if (b == 0) return 1;
//     else {
//         if (b % 2 == 0) {
//             return sqr(pw(a, b>>1));
//         } else {
//             return a * (sqr(pw(a, b>>1)));
//         }
//     }
// }

// int32_t main(void) {
//     FastIO;
//     freopen("POWER.INP","r",stdin);
//     freopen("POWER.OUT","w",stdout);
//     cin >> n >> k;
//     for (int i=1; i<=n; i++) {
//         cin >> a[i];
//     }

//     int bcnn = __lcm(a[1], a[2]);
//     for(int i=3; i<=n; i++) {
//         bcnn = __lcm(bcnn, a[i]);
//     }

//     for (int i=1; i<=bcnn; i++) {
//         if (pw(i,k)%bcnn == 0) {
//             // cout<<pw(i,k)<<endl;
//             res = i;
//             break;
//         }
//     }
//     // cout<<bcnn<<endl;
//     cout<<res;
//     return 0;
// }