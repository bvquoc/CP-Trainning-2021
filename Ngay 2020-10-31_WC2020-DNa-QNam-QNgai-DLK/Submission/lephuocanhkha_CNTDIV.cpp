#include <bits/stdc++.h>
using namespace std;

long long trace[2000005];
long long cnt[2000005];
bool vs[2000005];
vector<int> s;

void sieve(int n) {
    for (int i = 2; i <= n; i++) {
        if (trace[i] == 0) {
            for (int j = 1; j <= n / i; j++) {
                trace[i * j] = i;
            }
        }
    }
}

void calcDiv(long long n) {
    int j = n;
    while (j > 1) {
        int p = trace[j];
        while (j % p == 0) {
            j /= p;
            cnt[p]++;

            if (!vs[p]) {
                s.push_back(p);
                vs[p] = 1;
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    
    sieve(2000000); 
    
    int testCase;
    cin >> testCase;
    for (int z = 1; z <= testCase; z++) {
        long long n;
        cin >> n;

        calcDiv(n);
        calcDiv(n + 1);
        calcDiv(n + 2);

        long long cntT = 1;
        for (auto i: s) {
        //for (int i = 1; i <= n + 2; i++) {
            cntT *= (cnt[i] + 1);
            cnt[i] *= 2;
            //cout << i << ' ';
        }

        long long cntT2 = 1;
        for (auto i: s) {
            cntT2 *= (cnt[i] + 1);
        }

        long long res = cntT2 / 2 + (cntT2 % 2) - cntT;
        //cout << cntT2 << ' ' << cntT << endl;
        cout << res << "\n";

        for (auto i: s) {
            vs[i] = 0;
            cnt[i] = 0;
        }
        s.clear();
    }

    return 0;
}