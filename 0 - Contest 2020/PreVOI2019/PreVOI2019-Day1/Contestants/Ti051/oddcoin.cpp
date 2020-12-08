#include<bits/stdc++.h>
#define nmax 50000007
#define task "oddcoin"

using namespace std;

int x, t;
int A[18] = {0, 1, 3, 5, 10, 30, 50, 100, 300, 500, 1000, 3000, 5000, 10000, 30000, 50000};
int F[nmax];

void Solve() {
    F[0] = 0;
    A[16] = x;
    for(int i = 1; i <= t; i++) {
        F[i] = t + 1;
        for(int j = 1; j <= 16; j++)
            if(i >= A[j])
                F[i] = min(F[i], F[i - A[j]] + 1);
    }
    cout << F[t] << '\n';
}

void Enter() {
    cin >> x >> t;
    Solve();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    int q;
    cin >> q;
    while(q--) {
        Enter();
    }
}
