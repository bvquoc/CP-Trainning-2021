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
#define ChauNgoanBacHo "mine"
#define maxn 300050
#define remain(x) if (x > MOD) x -= MOD
#define pii pair<int, int>
#define FOR(i,j,k) for(int i=j;i<=k;++i)
#define FORD(i,j,k) for(int i=j;i>=k;--i)
#define ll long long
#define endl "\n"
#define int long long

using namespace std;
//mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
//#define rand rd
int const oo=1000003;
int n,m,res=0;
int dd[25],td[25];
void dq(int x)
{
    if(x>2*n)
    {
        int re=0;
        int bien=1;
        FOR(i,1,2*n)
        {
            bien*=2;
            if(dd[i])
                re+=bien;
        }

//        cout<<re<<endl;
//if(re==84)
//{
//    cout<<"check";
//}
         if(accumulate(dd+1,dd+1+2*n,0)!=n)
            return;
        stack<int> st;
        FOR(i,1,2*n)
        {
            if(!dd[i])
                st.push(i);
            else
            {
                if(st.size()==0)
                    return;
                int vt=st.top();
                st.pop();
                if(td[i]-td[vt]>m)
                    return;
            }
        }
        res++;
//         FOR(i,1,2*n)
//        {
//            cout<<dd[i]<<" ";
//        }cout<<endl;
    }
    else
    {
        dd[x]=1;
        dq(x+1);
        dd[x]=0;
        dq(x+1);
    }
}
int dp[maxn];
main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    #ifdef OK
    freopen(ChauNgoanBacHo".inp", "r", stdin);
    freopen(ChauNgoanBacHo".out", "w", stdout);
//    #endif // OK
    cin>>n>>m;
    FOR(i,1,2*n)
    {
        cin>>td[i];
    }
    if(n<=10)
    {
        dq(1);
           cout<<res;
    }
//    dp[2]=1;
    else if(m==1000000)
    {
        dp[0]=1;
        dp[2]=1;
        for(int i=2; i<=2*n; i+=2)
        {
            for(int j=2; j<i; j+=2)
            {
                (dp[i]+=dp[j]*dp[i-j-2])%=oo;
            }
            if(i>2) (dp[i]+=dp[i-2])%=oo;
        }
        cout<<dp[2*n];
    }


}
