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
#define ChauNgoanBacHo "construct"
#define maxn 300050
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
int n,m,res=0;
int a[maxn];
main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    #ifdef OK
    freopen(ChauNgoanBacHo".inp", "r", stdin);
    freopen(ChauNgoanBacHo".out", "w", stdout);
//    #endif // OK
    int T;
    cin>>T;
//    FOR(i,1,T)
//    {
//        cin>>n[i]>>m[i];
//    }
    while(T--)
    {
        cin>>n>>m;
        FOR(i,1,n)
        {
            cin>>a[i];
        }
        while(m--)
        {
            int type,l,r,dc;
            cin>>type;
            if(type==1)
            {
                cin>>l>>r>>dc;
                FOR(i,l,r)
                {
                    a[i]+=dc;
                }
            }
            else
            {
                int trc=0,re=0;
                cin>>l>>r;
                FOR(i,l,r)
                {
                    if(a[i]>trc)
                    {
                        re+=a[i]-trc;
                    }
                    trc=a[i];
                }
                cout<<re<<endl;
            }
        }
    }
}
