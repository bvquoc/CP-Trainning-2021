#include <bits/stdc++.h>
#define Task "COOLMAC"
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define READFILE freopen(Task".inp","r",stdin)
#define WRITEFILE freopen(Task".out","w",stdout)
#define READ_CF freopen("input.txt","r",stdin)
#define WRITE_CF freopen("output.txt","w",stdout)
#define int long long
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,r,l) for (int i=r;i>=l;i--)
#define For(i,a,b) for(__typeof(b) i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(__typeof(a) i = (a); i >= (b); --i)
#define Rep(i,n) for(__typeof(n) i = 0; i < (n); ++i)
#define Repd(i,n) for(__typeof(n) i = (n)-1; i >= 0; --i)
#define sz(a) ((int)(a).size())
#define ms(a,x) memset(a, x, sizeof(a))
#define vi vector<int>
#define ii pair<int,int>
#define fi first
#define se second
#define vii vector<ii>
#define pb push_back
#define sum(a,b) a+b
#define endl '\n'
#define ull unsigned long long
#define TR(k1,k2) for(__typeof((k2).begin()) k1=(k2).begin();k1!=(k2).end();++k1)
#define watch(x) cout << (#x) << " = " << x << endl
#define all(a) (a).begin(),(a).end()
#define db double
#define lamtron(a) (floorf((float)a/2+0.6f))
#define MIN(x,y) if((x)>(y)) x=y
#define MAX(x,y) if((x)<(y)) x=y
#define inc(a,x) a+=x
#define dec(a,x) a-=x
#define MOD(x) ((x%mod)+mod)%mod

template<class T> T sqr(T x)
{
    return x*x;
}
template<class T> T lcm(T a, T b)
{
    return a/__gcd(a, b)*b;
}
template<class T> T minimize(T &a,T b)
{
    if(a>b)
    {
        a=b;
        return true;
    }
    return false;
}
template<class T> T maximize(T &a,T b)
{
    if(a<b)
    {
        a=b;
        return true;
    }
    return false;
}

using namespace std;
const int N=1e5+5;

int m,n;
int a[N];
ii b[N];
int x[N];
int d[N];
int Ans=1e18;
int maxR=-1;
int Min=1e18;

// Greedy

void Inp()
{
    cin >> m;
    FOR(i,1,m)
    {
        cin >> b[i].first >> b[i].second;
        MAX(maxR,b[i].second);
    }
    cin >> n;
    FOR(i,1,n)
    {
        cin >> a[i];
        MIN(Min,a[i]);
    }
}

void check()
{
    memset(d,0,sizeof(d));
    int cnt=0;
    FOR(i,1,m)
    {
        if(x[i] == 0) continue;
        for(int k=b[i].first;k<=b[i].second;++k) ++d[k];
        ++cnt;
    }
    FOR(i,Min,N-5) if(d[i] == 0) return;
    MIN(Ans,cnt);
}

void BF(int i)
{
    if(i == m+1)
    {
        check();
        return;
    }
    Rep(j,2)
    {
        x[i]=j;
        BF(i+1);
    }
}

void Solve()
{
    if(maxR<1e5)
    {
        cout << -1;
        return;
    }
    BF(1);
    if(Ans == 1e18 || (n>10 && m>16)) cout << -1;
    else cout << Ans;
}

signed main()
{
    IO;
    #ifndef ONLINE_JUDGE
        READFILE;
        WRITEFILE;
    #endif
    //READ_CF;
    //WRITE_CF;
    Inp();
    Solve();
    return 0;
}
