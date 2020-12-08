#define taskname "oddcoin"
#include <bits/stdc++.h>
using namespace std;

const int val[15]={1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000};
int q,x,t;
int lim=4e4;

int cal(int num, int sum)
{
    int re=num;
    sum-=num*x;
    for(int i=14; i>=0; i--)
    {
        int cnt=sum/val[i];
        sum-=(cnt*val[i]);
        re+=cnt;
    }
    return re;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen(taskname".inp","r",stdin);
    freopen(taskname".out","w",stdout);
    cin>>q;
    while (q--)
    {
        cin>>x>>t;
        int res=2e9, ans=0;
        if (t%x==0) res=t/x;
        if (t/x>lim) {ans=(t-x*lim)/50000; t-=(50000*ans);}
        for(int i=0; i<=t/x; i++)
            res=min(res,cal(i,t)+ans);
        cout<<res<<'\n';
    }
}
