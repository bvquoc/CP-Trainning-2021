///      5 Dieu Bac Ho Day    ///
/// 1. Yeu to quoc, yeu dong bao
/// 2. Hoc tap tot, lao dong tot
/// 3. Doan ket tot, ki luat tot
/// 4. Giu gin ve sinh that tot
/// 5. Khiem ton, that tha, dung cam
#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define ChauNgoanBacHo "paint"
#define maxn 1000050
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
#define FOR(i,j,k) for(int i=j;i<=k;++i)
#define FORD(i,j,k) for(int i=j;i>=k;--i)
#define ll long long
#define endl "\n"
//#define int long long

using namespace std;
//mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
//#define rand rd
int const oo=1e9+7;
int n,m;
stack<int> res;
int root[2*maxn];
int gr(int u)
{
    if(root[u]==u) return u;
    return (root[u]) ? root[u]=gr(root[u]) : u;
}
int type[maxn];
char x[maxn],y[maxn];
main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    #ifdef OK
    freopen(ChauNgoanBacHo".inp", "r", stdin);
    freopen(ChauNgoanBacHo".out", "w", stdout);
//    #endif // OK
    cin>>n;
    int dem=0;
    FOR(i,1,n)
    {
        cin>>type[i]>>x[i];
        if(type[i]==2) cin>>y[i];

    }
    FORD(i,n,1)
    {

       if(type[i]==1)
        {
            ++dem;
            root[dem]=x[i]+maxn;
            int kq=gr(dem);
//            cout<<char(kq-maxn);
            res.push(kq-maxn);
        }
        else
        {
            root[x[i]+maxn]=gr(y[i]+maxn);
//            cout<<root[x+maxn];
        }
    }
    while(res.size())
    {
        cout<<char(res.top());
        res.pop();
    }
}
