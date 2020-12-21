#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;
typedef vector <vi> vvi;

const int N = 2e5 + 5, mod = 1e9 + 7;

int add(int a, int b){
    return ((a += b) >= mod ? a - mod : a);
}

int addAssign(int& a, int b){
    return ((a += b) >= mod ? a -= mod : a);
}

int sub(int a, int b){
    return ((a -= b) < 0 ? a + mod : a);
}

int subAssign(int& a, int b){
    return ((a -= b) < 0 ? a += mod : a);
}

int mul(int a, int b){
    return (ll)a * b % mod;
}

int mulAssign(int& a, int b){
    return (a = (ll)a * b % mod);
}

int binPow(int a, int b){
    int ans = 1;
    while (b){
        if (b & 1){
            mulAssign(ans, a);
        }
        mulAssign(a, a);
        b >>= 1;
    }
    return ans;
}

int inv2 = 5e8 + 4, fac[N], invfac[N];

int C(int a, int b){
    if (a < 0 || b < 0 || b > a){
        return 0;
    }
    return mul(fac[a], mul(invfac[b], invfac[a - b]));
}

void preCalculate(){
    fac[0] = invfac[0] = 1;
    For(i, 1, N){
        fac[i] = mul(fac[i - 1], i);
    }
    invfac[N - 1] = binPow(fac[N - 1], mod - 2);
    FordE(i, N - 2, 1){
        invfac[i] = mul(invfac[i + 1], i + 1);
    }
}

int n;
int a[N], b[N];

void readTest(){
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
    }
    ForE(i, 1, n){
        cin >> b[i];
    }
}

struct FenwickTree{
    int n;
    int bit[N];

    FenwickTree(int n): n(n) {
        memset(bit, 0, sizeof(bit));
    }

    void add(int idx, int val){
        for (; idx <= n; idx += idx & -idx){
            bit[idx] += val;
        }
    }

    int sum(int idx){
        int ans = 0;
        for (; idx > 0; idx -= idx & -idx){
            ans += bit[idx];
        }
        return ans;
    }

    int sum(int l, int r){
        return sum(r) - (l <= 1 ? 0 : sum(l - 1));
    }
};

int posPermSuff[N];

int calculatePerm(int arr[]){
    FenwickTree cac(n);
    ForE(i, 1, n){
        int prev = cac.sum(arr[i]);
        posPermSuff[i] = mul(arr[i] - 1 - cac.sum(arr[i]), fac[n - i]);
        cac.add(arr[i], 1);
        arr[i] -= prev;
    }
    FordE(i, n - 1, 1){
        addAssign(posPermSuff[i], posPermSuff[i + 1]);
    }
    ForE(i, 1, n){
        addAssign(posPermSuff[i], 1);
    }
    int ans = 0;
    For(i, 1, n){
        addAssign(ans, mul(arr[i] - 1, mul(mul(mul(n - i, n - i - 1), inv2), mul(fac[n - i], inv2))));
        if (arr[i] != 1){
            addAssign(ans, mul(mul(mul(arr[i] - 2, arr[i] - 1), inv2), fac[n - i]));
        }
        addAssign(ans, mul(arr[i] - 1, posPermSuff[i + 1]));
    }
    return ans;
}

void solveTest(){
    int ans = 0;
    if (prev_permutation(a + 1, a + 1 + n)) subAssign(ans, calculatePerm(a));
    addAssign(ans, calculatePerm(b));
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("PERMEOW.inp", "r", stdin);
    freopen("PERMEOW.out", "w", stdout);
    preCalculate();
    readTest();
    solveTest();
}

/*
==================================================+
INPUT:                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT:                                           |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/
