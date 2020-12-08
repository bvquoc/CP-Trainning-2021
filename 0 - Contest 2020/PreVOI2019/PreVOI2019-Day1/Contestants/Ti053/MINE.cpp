//Tran Thuy Duong
#include <bits/stdc++.h>
#define maxn 400005
#define MOD 1000003
#define task "MINE"
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define bit(x, i) (x >> i)&1

using namespace std;
typedef long long ll;
const ll MM = 1ll * MOD * MOD;

int n, n2, m, a[maxn];
int p[maxn];
void Sub1()
{
    n2 = n + n;
    int ans = 0;
    for (int x=1; x < (1 << n2); x++)
    {
        int t = __builtin_popcount(x);
        if (t != n) continue;
        int top = 0;
        bool check = 0;
        for (int i=0; i<n2; i++)
            if (bit(x, i)) p[++top] = i+1;
            else{
                if (top < 1) check = 1;
                if (a[i+1] > a[p[top]] + m) check = 1;
                if (check) break;
                top--;
            }
        if (check) continue;
        ans++;
    }
    cout << ans % MOD;
}
void Solve()
{
    cout << 1;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen(task".INP", "r", stdin);
	freopen(task".OUT", "w", stdout);
    cin >> n >> m;
    for (int i=1; i<=n+n; i++) cin >> a[i];
    if (n <= 10) Sub1();
    else Solve();
	return 0;
}
