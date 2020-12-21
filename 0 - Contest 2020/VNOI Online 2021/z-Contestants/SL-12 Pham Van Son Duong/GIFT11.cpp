#include<bits/stdc++.h>
#define Task "GIFT11"
#define mod 998244353
#define MAX_N 2004

using namespace std;

int A[MAX_N], B[MAX_N], giaithua[MAX_N];
int n;

inline void add(int &a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
}

bool Calc() {
    vector<int> vt;
    for (int i = 1; i <= n; i++) {
        int ans = A[i];
        int cnt = 0;
        while(ans) {
            B[++cnt] = ans % 10;
            ans /= 10;
        }
        for (int j = cnt; j >= 1; j--)
            vt.push_back(B[j]);
    }
    int res = 0;
    for (int i = 0; i < vt.size(); i++)
        if (i & 1)
            res -= vt[i];
        else
            res += vt[i];
    return res % 11 == 0;
}

bool Drop(int a) {
    int dem = 0;
    while(a) {
        a /= 10;
        dem++;
    }
    return dem & 1;
}

bool s[MAX_N];
int a[MAX_N];
int kq;

bool check() {
    vector<int> vt;
    for (int i = 1; i <= n; i++) {
        int ans = A[a[i]];
        int cnt = 0;
        while(ans) {
            B[++cnt] = ans % 10;
            ans /= 10;
        }
        for (int j = cnt; j >= 1; j--)
            vt.push_back(B[j]);
    }
    int res = 0;
    for (int i = 0; i < vt.size(); i++)
        if (i & 1)
            res -= vt[i];
        else
            res += vt[i];
    return res % 11 == 0;
}

void BT(int i) {
    for (int j = 1; j <= n; j++) {
        if (!s[j]) {
            a[i] = j;
            s[j] = 1;
            if (i == n)
                add(kq, check());
            else
                BT(i + 1);
            s[j] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    int T;
    cin >> T;
    giaithua[0] = 1;
    for (int i = 1; i <= 2000; i++)
        giaithua[i] = 1ll * giaithua[i - 1] * i % mod;
    while(T--) {
        cin >> n;
        bool ok = 1;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
            if (Drop(A[i]))
                ok = 0;
        }
        if (ok) {
            cout << (Calc() ? giaithua[n] : 0) << '\n';
            continue;
        }
        fill_n(s + 1, n, 0);
        fill_n(a + 1, n, 0);
        kq = 0;
        BT(1);
        cout << kq << '\n';
    }
}
