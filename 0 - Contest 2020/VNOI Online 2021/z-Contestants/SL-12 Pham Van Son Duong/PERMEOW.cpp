#include <bits/stdc++.h>
#define mod 1000000007
#define MAX_N 200005
#define Task "PERMEOW"

using namespace std;

int n;
int A[MAX_N], B[MAX_N], C[MAX_N];

void Update(int i) {
    for (; i; i -= (i & -i))
        C[i]++;
}

int Query(int i) {
    int res = 0;
    for (; i <= n; i += (i & -i))
        res += C[i];
    return res;
}

inline void add(int &a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
}

int bbsort() {
    fill_n(C + 1, n, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += Query(A[i]);
        Update(A[i]);
    }
    return ans;
}

bool check() {
    for (int i = 1; i <= n; i++)
        if (A[i] != B[i])
            return 0;
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> A[i];
    for (int i = 1; i <= n; i++)
        cin >> B[i];
    if (check())
        return cout << bbsort(), 0;
    int ans = bbsort();
    if (check())
        return cout << ans, 0;
    while(next_permutation(A + 1, A + n + 1)) {
        add(ans, bbsort());
        if (check())
            break;
    }
    cout << ans;
    return 0;
}
