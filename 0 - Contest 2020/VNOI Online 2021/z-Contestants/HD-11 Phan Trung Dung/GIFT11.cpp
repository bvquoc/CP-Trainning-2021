#include <bits/stdc++.h>
#define maxn 2005
#define mod 998244353

using namespace std;
typedef pair<int,int> II;
typedef pair<II,int> III;

int n, a[maxn], d[maxn], gt[maxn];

void sub1() {
    int res = 0;
    for(int i=1; i<=n; i++) d[i] = i;
    do {
        int sum1 = 0, sum2 = 0;
        int cnt = 0;
        for(int i=1; i<=n; i++) {
            int x = a[d[i]];
            while(x > 0) {
                ++cnt;
                if (cnt % 2) sum1 += x % 10;
                else sum2 += x % 10;
                x /= 10;
            }
        }
        if ((abs (sum1 - sum2)) % 11 == 0) ++res;
    } while (next_permutation(d+1,d+n+1));

    cout<<res;
}

void sub2() {
    int sum1 = 0, sum2 = 0;
    for (int i = 1; i <= n; i++) {
        int x = a[i];
        int cnt = 0;
        while (x > 0) {
            ++cnt;
            if (cnt % 2) sum1 += x % 10;
            else sum2 += x % 10;
            x /= 10;
        }
    }
    if ((abs (sum1 - sum2)) % 11 == 0) cout<<gt[n];
    else cout<<0;
}

int main() {
    freopen("GIFT11.inp", "r", stdin);
    freopen("GIFT11.out", "w", stdout);
    ios::sync_with_stdio (false);
    cin.tie(0); cout.tie(0);

    gt[0] = 1;
    for (int i=1; i<=2005; i++) gt[i] = (1ll * gt[i - 1] * i) % mod;

    int T;
    cin>>T;
    while (T --> 0) {
        cin>>n;
        for (int i = 1; i <= n; i++) cin>>a[i];

        if(n <= 10) sub1();
        else sub2();

        cout << "\n";
    }
}
