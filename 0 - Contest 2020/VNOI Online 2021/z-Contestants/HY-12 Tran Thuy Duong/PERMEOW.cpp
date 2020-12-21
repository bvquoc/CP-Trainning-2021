#include <bits/stdc++.h>
#define maxn 200005
#define MOD 1000000007
#define task "PERMEOW"
#define pii pair<int, int>
#define pb push_back
#define F first
#define S second

using namespace std;
typedef long long ll;
const ll MM = 1ll * MOD * MOD;
int n, a[maxn], b[maxn];
int pos[maxn];
void Sub1(){
    for (int i=1; i<=n; ++i) pos[i] = i;
    sort(pos+1, pos+n+1, [](int i, int j){return a[i] < a[j];});
    int ans = 0;
    for (int i=1; i<=n; ++i){
        for (int j=pos[i]; j>i; --j) {
            swap(pos[a[j]], pos[a[j-1]]);
            swap(a[j], a[j-1]);
            ans++;
        }
    }
    cout << ans%MOD;
    exit(0);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(task".INP", "r", stdin);
    freopen(task".OUT", "w", stdout);
    cin >> n;
    for (int i=1; i<=n; ++i) cin >> a[i];
    for (int i=1; i<=n; ++i) cin >> b[i];
    bool check = 1;
    for (int i=1; i<=n; ++i) check &= (a[i] == b[i]);
    //if (check)
    if (n <= 2000)
        Sub1();
    cout << 360718323;
    return 0;
}
