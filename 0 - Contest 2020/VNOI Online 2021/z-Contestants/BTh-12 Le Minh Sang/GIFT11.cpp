#include <bits/stdc++.h>
#define TASK "GIFT11"
#define X first
#define Y second
#define ll long long
#define pi pair<int,int>
#define Bit(i) (1<<(i))
#define Get_Bit(i,x) (((x)>>i)&1)

using namespace std;
const int MOD = 998244353;
const int N = 2005;
int T,n,a[N];

void Sub1()
{
    int res = 0;
    vector<int> p;
    for (int i=1; i<=n; ++i) p.push_back(i);

    do {
        int ans1 = 0, ans2 = 0, d = 0;
        for (int i=0; i<p.size(); ++i) {
            int x = a[p[i]];
            while (x!=0) {
                ++d;
                if (d%2) ans1 += x%10; else ans2 += x%10;
                x /= 10;
            }
        }
        if ((((ans1-ans2)%11)+11) % 11 == 0) ++res;
    } while (next_permutation(p.begin(),p.end()));
    cout << res << "\n";
}

int f[N][11][N],sum[2][N];
int Dp(int i, int d, int vc, int vl)
{
    if (i>n) return (d==0);
    int &res = f[i][d][vc];
    if (res!=-1) return res;
    res = 0;
    res += (1ll*vl*Dp(i+1,d+sum[1][i],vc,vl+1)%MOD +
           1ll*vc*Dp(i+1,d+sum[0][i],vc+1,vl)%MOD) % MOD;
    return res;
}

void Sub2()
{
    for (int i=1; i<=n; ++i) sum[1][i] = sum[0][i] = 0;
    for (int i=1; i<=n; ++i) {
        int x = a[i];
        int ans1 = 0, ans2 = 0, d = 0;
        while (x!=0) {
            ++d;
            if (d%2) ans1 += x%10; else ans2 += x%10;
            x /= 10;
        }
        sum[1][i] = (((ans1-ans2)%11)+11) % 11;
        sum[0][i] = (((ans2-ans1)%11)+11) % 11;
    }
    memset(f,-1,sizeof f);
    cout << Dp(1,0,1,0) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(TASK ".inp", "r", stdin);
    freopen(TASK ".out", "w", stdout);
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i=1; i<=n; ++i) cin >> a[i];
        if (n<=9) Sub1(); else
        Sub2();
    }
    return 0;
}
