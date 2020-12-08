#include<bits/stdc++.h>
using namespace std;
#define fi   first
#define se   second
#define pb push_back
#define pu push
#define pii pair<int,int>
#define TASKNAME "oddcoin"
const int oo=2e9;
int tien[]={1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000};
int f[5000001];
int q,t[1000],x[1000],dem,res,maxt;
multiset<int>ms;
multiset<int>::iterator it;
int dq(int dong)
{
    int res=oo;
    if (f[dong]!=(-1) )return f[dong];
    for (auto z:ms)
    {
        if (z>dong) break;
        res=min(res,1+dq(dong-z));
    }
    return f[dong]=res;
}
void cbi()
{
    memset(f,-1,sizeof(f));
             f[0]=0;
             for (int i=1;i<=maxt;i++)
                for (int j=0;j<14;j++)
             {
                 int z=tien[j];
                 if (z>i) break;
                 if (f[i]==-1) f[i]=f[i-z]+1;
                 else f[i]=min(f[i],f[i-z]+1);
             }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen(TASKNAME".inp", "r", stdin);
    freopen(TASKNAME".out", "w", stdout);
    #endif
    for (int i=0;i<14;i++)ms.insert(tien[i]);
    cin>>q;
    cbi();
    for (int qq=1;qq<=q;qq++)
    {
         cin>>x[qq]>>t[qq];
         maxt=max(maxt,t[qq]);
    }
    cbi();
    for (int qq=1;qq<=q;qq++)
    {
         {
             res=oo;
             for (int i=0;i*x[qq]<=t[qq];i++) res=min(res,i+f[t[qq]-i*x[qq]]);
             cout<<res<<'\n';
         }
    }
    return 0;
}
