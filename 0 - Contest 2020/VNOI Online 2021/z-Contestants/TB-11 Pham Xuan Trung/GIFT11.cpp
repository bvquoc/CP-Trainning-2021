#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define BIT(x,i) (1&((x)>>(i)))
using namespace std;
const int mod = 998244353;
const int N = 2001;
int T , n , ans , d[N] , pos[N];
int num[2001];
string s[N];
void add(int &x , const int &y)
{
    x+=y;
    if(x >= mod) x-=mod;
}
void ADD(int &x , const int &y)
{
    x+=y;
    if(x >= 11) x-=11;
}
void SUB(int &x , const int &y)
{
    x-=y;
    if(x < 0) x+=11;
}
void upd()
{
    int tmp = 0 , c = 0;
    for(int i=1 ; i<=n ; ++i)
    {
        int j = pos[i];
        for(int k=0 ; k<(int)s[j].length() ; ++k)
        {
            if(c == 0) ADD(tmp , (int)s[j][k] - 48);
            else SUB(tmp , (int)s[j][k] - 48);
            c = 1-c;
        }
    }
    if(tmp == 0) add(ans , 1);
}
void go(int i)
{
    if(i == n+1)
    {
        upd();
        return;
    }
    for(int j=1 ; j<=n ; ++j)
    {
        if(!d[j])
        {
            pos[i] = j;
            d[j] = 1;
            go(i+1);
            d[j] = 0;
        }
    }
}
void subtask1()
{
    memset(d , 0 , sizeof(d));
    ans = 0;
    go(1);
    cout << ans << '\n';
}
void subtask2()
{
    int c = 0 , tmp=0;
    for(int i=1 ; i<=n ; ++i)
    {
        for(int j=0 ; j<(int)s[i].size() ; ++j)
        {
            if(c == 0) ADD(tmp , (int)s[i][j] - 48);
            else SUB(tmp , (int)s[i][j] - 48);
            c = 1-c;
        }
    }
    if(tmp != 0)
    {
        cout << 0 << '\n';
        return;
    }
    cout << num[n] << '\n';
}
// p : chan , q : le
// dpijk : i : vitri , j : so le , k : du
int p , q;
int dp[2001][2001][12];
void subtask3()
{
    memset(dp , 0 , sizeof(dp));
    dp[0][0][0] = 1;
    int p = n/2 , q = n-p;
    for(int i=0 ; i<n ; ++i)
    {
        int c = 0 , sum = 0;
        for(int j=0 ; j<(int)s[i+1].length() ; ++j)
        {
            if(c == 0) ADD(sum , (int)s[i+1][j] - 48);
            else SUB(sum , (int)s[i+1][j] - 48);
            c = 1-c;
        }
        for(int j=0 ; j<=min(i , q) ; ++j)
        {
            for(int k=0 ; k<11 ; ++k)
            {
                if(!dp[i][j][k]) continue;
                if(j < q)
                {
                    int tmp = k+sum >= 11 ? k+sum-11 : k+sum;
                    add(dp[i+1][j+1][tmp] , dp[i][j][k]);
                }
                if(i-j < p)
                {
                    int tmp = k-sum < 0 ? k-sum+11 : k-sum;
                    add(dp[i+1][j][tmp] , dp[i][j][k]);
                }
            }
        }
    }
    int ans = 1;
    ans = (1LL*ans*dp[n][q][0]*num[q])%mod;
    ans = (1LL*ans*num[p])%mod;
    cout << ans;
}
int getSubtask()
{
    if(n <= 8) return 1;
    bool ok = 1;
    for(int i=1 ; i<=n ; ++i)
    {
        int c = s[i].length();
        if(c%2)
        {
            ok = 0;
            break;
        }
    }
    if(ok) return 2;
    for(int i=1 ; i<=n ; ++i)
    {
        int c = s[i].length();
        if(c%2 == 0)
        {
            ok = 1;
            break;
        }
    }
    if(!ok) return 3;
    return 4;
}
void solve()
{
    cin >> n;
    for(int i=1 ; i<=n ; ++i) cin >> s[i];
    int st = getSubtask();
    if(st == 1) subtask1();
    else if(st == 2) subtask2();
    else subtask3();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("GIFT11.INP" , "r" , stdin);
    freopen("GIFT11.OUT" , "w" , stdout);
    num[0] = 1;
    for(int i=1 ; i<=2000 ; ++i)
    {
        num[i] = (1LL*num[i-1]*i)%mod;
    }
    cin >> T;
    while(T--) solve();
    return 0;
}
