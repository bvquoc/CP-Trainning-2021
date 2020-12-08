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
#define ChauNgoanBacHo "oddcoin"
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
int tien[50000*2];
int dd[25];
void dq(int pos,int gtma)
{
    if(pos>=gtma)
    {
        int trc=0;
        int dem=0;
//       FOR(i,1,gtma)
//       {
//           cout<<dd[i]<<" ";
//       }
//       cout<<endl;
        FOR(i,1,gtma)
        {
            if(dd[i])
            {
                if(!tien[i-trc])
                    dem=oo;
                dem++;
                trc=i;
            }
        }
//       cout<<dem<<endl;
        res=min(res,dem);
//       cout<<res<<endl;
    }
    else
    {
        dd[pos]=1;
        dq(pos+1,gtma);
        dd[pos]=0;
        dq(pos+1,gtma);
    }
}
void sub1(int x, int t)
{
    for(int i=1; i<=5; i+=2)
    {
        tien[i]=tien[i*10]=tien[i*1000]=tien[i*10000]=1;
    }
    tien[x]=1;
    dd[t]=1;
    dq(1,t);
    dd[t]=0;
    for(int i=1; i<=5; i+=2)
    {
        tien[i]=tien[i*10]=tien[i*1000]=tien[i*10000]=0;
    }
    tien[x]=0;
}
int sl[15];
int xl(int a)
{
    int dem=0,re=0;
    int    so=1;
    while(a)
    {
        dem++;
        int du=a%10;
        if(dem>5)
            so*=10;
        re+=sl[du]*so;
        a/=10;
    }
    return re;
}
main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    #ifdef OK
    freopen(ChauNgoanBacHo".inp", "r", stdin);
    freopen(ChauNgoanBacHo".out", "w", stdout);
//    #endif // OK
    int Q;
    cin>>Q;
    sl[0]=0;
    sl[1]=1;
    sl[2]=2;
    sl[3]=1;
    sl[4]=2;
    sl[5]=1;
    sl[6]=2;
    sl[7]=3;
    sl[8]=2;
    sl[9]=3;
    while(Q--)
    {
        int x,t;
        cin>>x>>t;
        res=oo;
        if(x<=20&&t<=20)
        {
            sub1(x,t);
            cout<<res<<endl;
        }
        else if(t/x<=2000005)
        {
//            cout<<xl(30000);
            int chia=t/x;
            FOR(i,0,chia)
            {
                res=min(res,xl(t-x*i)+i);

            }
            cout<<res<<endl;
        }
        else
        {
            res=0;
            priority_queue<int> pq;
            for(int i=1; i<=10000; i*=10)
            {
                pq.push(i);
                pq.push(i*3);
                pq.push(i*5);
            }
            pq.push(x);
            while(t)
            {
                if(pq.top()<=t)
                {
                    res+=t/pq.top();
                    int del=t/pq.top();
                    t-=del*pq.top();
                }
                pq.pop();
            }
            while(pq.size())
                pq.pop();
            cout<<res<<endl;
        }
    }
}
