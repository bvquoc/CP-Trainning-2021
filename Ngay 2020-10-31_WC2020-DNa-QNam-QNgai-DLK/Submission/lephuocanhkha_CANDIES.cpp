#include <bits/stdc++.h>
using namespace std;

vector<long long> fibo;
long long cnt[100005];

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    fibo.resize(100);

    fibo[1] = fibo[2] = 1;
    for (int i = 3; i <= 80; i++) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }

    for (int i = 1; i <= 100000; i++) {
        int p = i;
        while (p > 0) {
            int j = upper_bound(fibo.begin(), fibo.end(), p) - fibo.begin();
            p -= fibo[j - 1];
            cnt[i]++;                
        }
    }

    int t;
    cin >> t;
    for (int z = 1; z <= t; z++) {
        int n, k;
        cin >> n >> k;

        int res = 0;

        for (int i = 1; i <= n; i++) {
            if (cnt[i] >= k) res += cnt[i];
        }

        cout << res << "\n";
    }    

    return 0;
}