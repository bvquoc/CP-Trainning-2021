#include <bits/stdc++.h>
#define TASK "DECOR"
#define X first
#define Y second
#define ll long long
#define pi pair<int,int>
#define Bit(i) (1<<(i))
#define Get_Bit(i,x) (((x)>>i)&1)

using namespace std;
const int N = 5e5 + 5;
int n,m,k,a[N];
struct dd
{
    int u,v;
} e[N];

void Sub1()
{
    pi ans;
    int res,l,r;
    res = l = 0;
    r = -1;
    a[n+1] = 0;
    for (int i=1; i<=n+1; ++i) {
        if (a[i])
            if (a[i-1]==0) l = r = i; else r = i;
        if (a[i]==0) {
            if (res<r-l+1) {
                res = r-l+1;
                ans = {l,r};
            }
        }
    }
    if (res==0) cout << -1; else
    cout << ans.X << " " << ans.Y;
}

void Sub2()
{
    pi ans;
    int l = 1, r = 1, dem = (a[1]==0), res = -1;
    while (l<=r && r<n) {
        if ((dem==k && a[r+1]) || dem<k) {
            ++r;
            if (dem<k) dem += (a[r]==0);
        } else {
            dem -= (a[l]==0);
            ++l;
        }

        if (res<r-l+1) {
            if (r==l && a[r]==0) continue;
            res = r-l+1;
            ans = {l,r};
        }
    }
    if (res==-1) cout << -1; else
    cout << ans.X << ' ' << ans.Y;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
    cin >> n >> m >> k;
    for (int i=1; i<=n; ++i) {
        char c; cin >> c;
        a[i] = c - '0';
    }
    for (int i=1; i<=n; ++i)
        cin >> e[i].u >> e[i].v;
    if (m==0 && k==0) Sub1(); else
    if (m==0) Sub2();
    return 0;
}
