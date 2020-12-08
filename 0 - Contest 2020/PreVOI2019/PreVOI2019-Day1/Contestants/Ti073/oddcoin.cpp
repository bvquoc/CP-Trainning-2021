#include<bits/stdc++.h>
/*---------------------Define--------------------*/
#define next nextt
#define pii pair<int,int>
#define fi first
#define se second
#define rd random
#define ll long long
#define taskname "ODDCOIN"
#define pb push_back
#define mp make_pair
#define pb push_back
#define popb pop_back
#define popf pop_front
#define pf push_front
#define res(a,z,n) for(int i = 1 ; i<=n ; i ++) a[i] = z;
/*-------------------necesary---------------------*/
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/*------------------limit-------------------------*/
const int base  = 1e9+7;
const int oo = 1e6 + 10;
const int gh = 1e3 + 3 ;
//const int inf = 1e15 + 5 ;
/*-----------------globalvari-----------------------*/
int n,m,k,q;
int a[oo];
int f[] = {0,1,2,1,2,1,2,3,2,3};
int ok[oo];
vector<int> b;
/*-----------------code-----------------------*/
void pre()
{
    int t = 1;
    for(int i = 1 ; i <= 5 ; i++)
        {
            ok[1*t] = 1;
            ok[3*t] = 1;
            ok[5*t] = 1;
            b.pb(1*t);
            b.pb(3*t);
            b.pb(5*t);
            t*=10;
        }

}
void input()
{
    cin>>n>>m;
}

void cre()
{

}

int dp[50003];

int getans(int d)
{
    int cnt = 0;
    int r = 0;
    int p10 = 1;
    while(d)
    {
        cnt ++ ;
        if(cnt <= 5) r += f[d%10];
        else {
                r += (d%10)*2*p10;
                p10*=10;
        }
        d/=10;
    }
    return r;
}

void proc1()
{
    int t = m / n;
    int ans = m;
    for(int i = 0 ; i <= t; i ++)
    {
        int d = m - n*i;

        ans = min(ans,getans(d) + i);
    }
    cout<<ans<<"\n";
}

int MAXN = 50000;

void proc2()
{
    int q = m/MAXN;
    int t = m%MAXN;
    b.pb(n);
    int T = b.size();
    for(int i=0;i<=t;i++)
    {
        dp[i] = i;
    }
    for(int i=1;i<=t;i++)
    {

        for(int j = 0 ; j < T  ; j ++)
        {
            if(b[j] <= i)
                {
                    dp[i] = min(dp[i-b[j]]+1,dp[i]);
                }
        }
    }

    b.pop_back();
    cout<<q + dp[t]<<"\n";
}

void dpp()
{
    int q = 0;
    int t = m;
    b.pb(n);
    int T = b.size();
    for(int i=0;i<=t;i++)
    {
        dp[i] = i;
    }
    for(int i=1;i<=t;i++)
    {

        for(int j = 0 ; j < T  ; j ++)
        {
            if(b[j] <= i)
                {
                    dp[i] = min(dp[i-b[j]]+1,dp[i]);
                }
        }
    }

    b.pop_back();
   // cerr<<q<<" "<<dp[t]<<endl;
    cout<<q + dp[t]<<"\n";
    //for(int i 1 )
}

void solve()
{
    cre();
    int t = sqrt(m);

    if(m <=100000) dpp();
    else if(ok[n] == 1) {cout<<getans(m)<<"\n";}
    else if( n >= min(t,25000) || m <= 100000  )
    {
        proc1();
    }
    else proc2();
    //main code here :))
}

void ouput()
{

    //write
}

int32_t main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //#ifndef ONLINE_JUDGES
    if (ifstream("test.txt"))
    {
        freopen("test.txt", "r", stdin);
        #ifdef CHECKING
            freopen(taskname".out", "w", stdout);
        #else
            //\freopen("test.out", "w", stdout);
        #endif //CHECKING
    }
    else if (ifstream(taskname".inp"))
    {
        freopen(taskname".inp", "r", stdin);
        freopen(taskname".out", "w", stdout);
    }
    //#endif // ONLINE_JUDGES
    int t=1;
    cin>>t;
    pre();
    while(t--)
    {
    input();
    solve();
    ouput();
    }
}

//ilove??<3

