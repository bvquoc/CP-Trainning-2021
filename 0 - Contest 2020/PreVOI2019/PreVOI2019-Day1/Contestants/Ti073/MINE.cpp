#include<bits/stdc++.h>
/*---------------------Define--------------------*/
//#define int long long
#define next nextt
#define pii pair<int,int>
#define fi first
#define se second
#define rd random
#define ll long long
#define taskname "MINE"
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
const int base  = 1000003;
const int oo = 2e3 + 1;
const int gh = 1e3 + 3 ;
//const int inf = 1e15 + 5 ;
/*-----------------globalvari-----------------------*/
int n,m,k,q;
int a[2*oo];
/*-----------------code-----------------------*/


void input()
{
    //read
    cin>>n>>m;
    for(int i=1;i<=2*n;i++)
        cin>>a[i];
}

int dp[4001];
int p[2*oo];
int f[oo+1][oo+1];

void cre()
{
    p[0] = 1;
    f[0][0] = 1;
    for(int j=0 ; j < oo ; j++)
        for(int i=0 ; i < oo; i++)
            {
                (f[i+1][j]+=f[i][j])%=base;
                if(j<i)
                    (f[i][j+1]+=f[i][j])%=base;
            }
  //  cerr<<f[2][2]<<endl;
    for(int i=1;i<oo;i++)
    {

        p[i] = f[i][i];
        //  cerr<<i<<" "<<p[i]<<endl;
        //p[i] = p[i-1]*2%base;
    }

    //cerr<<p[1]<<endl;
}


void solve()
{
    cre();
    if(n<=2000)
    {
        dp[0] = 1;
        for(int i=1;i<=2*n;i+=2)
            for(int j=i+1;j<=2*n;j+=2)
            {
                if(a[j] - a[i] <= m)
                {

                    if(j-i>1)
                        dp[j] = (dp[j] + (1LL*dp[i-1]*p[(j-i)/2] % base)) % base;
                    else dp[j] = (dp[j] + dp[i-1])%base;
                }

            }

        if(dp[2*n]<0) dp[2*n] += base;
        cout<<dp[2*n];
    }
    else cout<<p[n-1];

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
   // cin>>t;

    while(t--)
    {
    input();
    solve();
    ouput();
    }
}

//ilove??<3

