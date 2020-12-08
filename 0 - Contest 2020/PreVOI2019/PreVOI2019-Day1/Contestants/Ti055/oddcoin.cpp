#include <bits/stdc++.h>
#define x first
#define y second
#define fu(_i,_a,_b) for (int _i=_a; _i<=_b; _i++)
#define fd(_i,_a,_b) for (int _i=_a; _i>=_b; _i--)
#define task "oddcoin"
#define pb push_back
#define ALL(vecS) vecS.begin(),vecS.end()

using namespace std;

typedef long long ll;
typedef pair <int,int> ii;
typedef pair <ll,int> li;

const int oo=1e9;

int q;
int dp[100005];

void solve(int nw, int ar[], int c)
{
    fill(dp,dp+100001,oo);
    ar[16]=nw;
    sort(ar+1,ar+17);
   // fu(i,1,16) cout << ar[i] << ' ';
    //cout << '\n';
    dp[0]=0;

    fu(i,1,c)
    {
        dp[i]=dp[i-1]+1;
        fu(j,2,16)
            if (ar[j]>i) break;
            else
        {
            dp[i]=min(dp[i-ar[j]]+1,dp[i]);
        }
    }
    cout << dp[c] << '\n';

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    cin >> q;
    int nw,c;
    while (q--)
    {
        cin >> nw >> c;
        int a[18]={0,1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000};
        solve(nw,a,c);
        //cout << '\n';
    }
    return 0;
}
