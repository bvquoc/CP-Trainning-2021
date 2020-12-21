#include <bits/stdc++.h>
#define task "PERMEOW"
typedef long long int ll;
using namespace std;

const ll mod = 1e9 + 7;

void add(ll &a, ll b) {
    a += b;
    if (a >= mod) a -= mod;
}

const int N = 200010;
int n, a[N], b[N], A[N];

bool check(int A[], int B[], int n) {
    for (int i = 1; i <= n; ++i) {
        if (A[i] != B[i]) return false;
    }
    return true;
}

ll calc(int x[], int n) {
    for (int i = 1; i <= n; ++i) A[i] = x[i];
    ll res = 0;
    bool ok = false;
    while (ok == false) {
        bool tmp = true;
        for (int i = 1; i < n; ++i) {
            if (A[i] > A[i+1]) {
                tmp = false;
                swap(A[i], A[i+1]);
                add(res, 1);
            }
        }
        ok = tmp;
    }
    return res;
}

void sub_trau(void) {

    bool checkRes = false;
    for (int i = 1; i <= n; ++i) {
        if (a[i] != b[i]) {
            if (a[i] > b[i]) checkRes = true;
            break;
        }
    }
    if (checkRes) {
        cout << 0;
        exit(0);
    }
    if (check(a, b, n)) {
        cout << calc(a, n);
        exit(0);
    }
    ll res = 0;
    do {
        add(res, calc(a, n));
    } while (next_permutation(a + 1, a + n + 1) && !check(a, b, n));
    add(res, calc(b, n));
    cout << res;
}

int main() {
    if (fopen(task".inp", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    sub_trau();
    return 0;
}

