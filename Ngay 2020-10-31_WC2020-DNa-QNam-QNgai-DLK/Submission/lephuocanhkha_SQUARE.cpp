#include <bits/stdc++.h>
using namespace std;

bool solve(long long n) {  
    if (n < 0) return 0; 
    long long m = sqrt(n);
    return (m * m == n);
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    long long k;
    cin >> k;

    long long res = 1e18;
    long long m = sqrt(abs(k));
    for (int i = 1; i <= m; i++) {
        if (abs(k) % i == 0) {
            long long j = abs(k) / i;
            if ((i + j) % 2 == 0) {
                if (k >= 0) res = min(res, (i + j) / 2);
                else res = min(res, (j - i) / 2);
            }
        }
    }

    if (res == 1e18) cout << "none";
    else cout << res;

    // cout << endl;

    // if (solve(k)) {
    //     long long n = sqrt(k);
    //     cout << n;
    //     return 0;
    // }

    // for (int i = 1; i <= 999; i += 2) {
    //     k += i;
    //     if (solve(k)) {
    //         long long kk = sqrt(k);
    //         cout << kk;
    //         return 0;
    //     }
    // }
    
    // cout << "none";

    return 0;
}