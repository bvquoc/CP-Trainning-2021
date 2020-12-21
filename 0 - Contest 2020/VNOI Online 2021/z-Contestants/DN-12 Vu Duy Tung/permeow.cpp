#include<bits/stdc++.h>
#define mino "permeow"

#define ll long long
#define pb push_back
#define fi first
#define se second
#define mp make_pair

#define INC(i,a,b) for(int i=a; i<=b; i++)
#define DEC(i,a,b) for(int i=a; i>=b; i--)
#define REP(i,a,b) for(int i=a; i<b; i++)

#define turbo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define oo 1e17

const int N = 1e5 + 5;
const ll MOD = 1e9 + 7;

using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;


int n, sub1 = 1, sub2 = 1;
int a[N], b[N];
ll dp[N], gt[N];

void solve1()
{
    int dem = 0;
    INC(i,1,n)
    {
        INC(j,1,i-1)
        {
            if( a[j] > a[i] ) dem++;
        }
    }
    cout << dem;
}

void solve2()
{
    gt[0] = 1;
    INC(i,1,n) gt[i] = gt[i-1] * i % MOD;

    INC(i,1,n)
    {
        INC(j,0,i-1)
        {
            dp[i] = (dp[i] + (dp[i-1] + 1ll * j * gt[i-1] % MOD)) % MOD;
        }
    }
    cout << dp[n];
}

int main()
{
    freopen(mino".inp","r",stdin);
    freopen(mino".out","w",stdout);

    turbo

    cin >> n;

    INC(i,1,n)
    {
        cin >> a[i];
        if( a[i] != i ) sub2 = 0;
    }

    INC(i,1,n)
    {
        cin >> b[i];
        if( b[i] != a[i] ) sub1 = 0;
        if( b[i] != n-i+1 ) sub2 = 0;
    }

    if( sub1 ) solve1();
    else solve2();
}
