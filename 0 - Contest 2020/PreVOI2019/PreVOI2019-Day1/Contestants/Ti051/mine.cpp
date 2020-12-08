#include<bits/stdc++.h>
#define task "mine"
#define nmax 200005
#define PB push_back
#define mod 1000003
#define oo 1000000007

using namespace std;

typedef vector<int> vti;

int A[nmax];
int n, m;
int t = 0;
int amin = oo;

void Enter() {
    cin >> n >> m;
    int cnt = 1;
    int dau = 1;
    for(int i = 1; i <= 2 * n; i++) {
        cin >> A[i];
        if(i < 2 * n)
            amin = min(amin, A[i + 1] - A[i]);
        if(A[i] - A[1] <= m)
            t = i;
    }
    for(int i = 1; i < 2 * n; i++)
        amin = min(amin, A[i + 1] - A[i]);
    if(amin > m) {
        cout << 0;
        exit(0);
    }
}

void Solve() {
    int res = 1;
    for(int i = 4; i <= t; i += 2) {
        res = (res + ((t - 2) >> 1)) % mod;
    }
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
    Enter();
    Solve();
}
