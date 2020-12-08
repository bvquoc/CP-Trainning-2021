#include <bits/stdc++.h>
#define forinc(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int N=1e5+1;
int a[20]={0,1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000};
int d[N],b[20];
int main()
{
    freopen("oddcoin.inp","r",stdin);
    freopen("oddcoin.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    queue<int> q;
    q.push(0);
    memset(d,-1,sizeof d);
    d[0]=0;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        forinc(i,1,15)
        {
            int y=x+a[i];
            if(y>=N) continue;
            if(d[y]==-1)
            {
                d[y]=d[x]+1;
                q.push(y);
            }
        }
    }
    int test;
    cin>>test;
    while(test--)
    {
        int x,t;
        cin>>x>>t;
        if(t<N)
        {
            if(x>t)
            {
                cout<<d[t]<<'\n';
                continue;
            }
            int res=INT_MAX;
            forinc(k,0,t/x)
            {
                res=min(res,k+d[t-k*x]);
            }
            cout<<res<<'\n';
            continue;
        }
        int res=0;
        forinc(i,1,15) b[i]=a[i];
        b[16]=x;
        sort(b+1,b+17);
        int i=16;
        while(t>0)
        {
            while(t<b[i]) --i;
            int k=t/b[i];
            res+=k;
            t-=k*b[i];
        }
        cout<<res<<endl;
    }
}
