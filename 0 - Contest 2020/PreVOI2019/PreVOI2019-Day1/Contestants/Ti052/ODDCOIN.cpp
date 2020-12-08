#include<bits/stdc++.h>
using namespace std;
#define ft first
#define se second
#define iP pair<int,int>
#define iiP pair<int,pair<int,int> >
#define ll long long
#define lP pair<ll,int>
#define db long double
template <typename T> inline void read(T &x)
{
    x=0;
    char c=getchar();
    while(!isdigit(c)) c=getchar();
    while(isdigit(c))
    {
        x=x*10+c-48;
        c=getchar();
    }
}
int q;
int x,t;
//priority_queue<iP ,vector<iP >,greater<iP > > p;
queue<iP > p;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("ODDCOIN.INP","r",stdin);
    freopen("ODDCOIN.OUT","w",stdout);
    read(q);
    //cout<<log2(4000);
    while(q--)
    {
        read(x);
        read(t);
        int sum[]={0,1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000};
        int d=15;
        sum[d+1]=x;
         sort(sum+1,sum+d+1+1);
        if(x<=20 && t<=20)
        {
            int f[21],d1[21];
            fill(d1+1,d1+21+1,21);
            for(int i=1;i<=16;i++)
                {
                    if(sum[i]>20) break;
                    f[sum[i]]=d1[sum[i]]=1;
                }
            f[0]=1;
            d1[0]=0;
            //for(int i=1;i<=)
            for(int i=2;i<=t;i++)
            for(int j=1;j<=16;j++)
                {
                if(sum[j]>i) break;
                if(f[i-sum[j]]==1) {f[i]=1;d1[i]=min(d1[i],d1[i-sum[j]]+1);
                }
            }

            cout<<d1[t]<<endl;
            continue;
        }
        if(x<=100000 && t<=100000)
        {
            int f[100001],d1[100001];
            fill(d1+1,d1+100000+1,100001);
            for(int i=1;i<=16;i++)
                {
                    f[sum[i]]=d1[sum[i]]=1;
                }
            f[0]=1;
            d1[0]=0;
            //for(int i=1;i<=)
            for(int i=2;i<=t;i++)
            for(int j=1;j<=16;j++)
                {
                if(sum[j]>i) break;
                if(f[i-sum[j]]==1) {f[i]=1;d1[i]=min(d1[i],d1[i-sum[j]]+1);
                }
            }

            cout<<d1[t]<<endl;
            continue;
        }
        int g=0;
        int minc=INT_MAX;
        for(int i=1;i<=d+1;i++)
            if(t%sum[i]==0) minc=min(t/sum[i],minc);
        //int x=upper_bound(sum+1,sum+d+2,t)-sum-1;
        while(t>sum[16])
            {t-=sum[16];
            g++;}
        while(!p.empty())
            p.pop();
        p.push({t,0});
        int ok=1;

        while(!p.empty())
        {
            int u=p.front().ft;
            int d1=p.front().se;
            p.pop();
            int j=upper_bound(sum+1,sum+d+2,u)-sum-1;
            //if(d1+u/sum[j]>minc) continue;
            //cout<<j<<endl;
            //cout<<sum[j]<<endl;
            int limit=0;
            if(u>=10000) limit=lower_bound(sum+1,sum+d+2,10000)-sum;
            if(u<10000) limit=lower_bound(sum+1,sum+d+2,1000)-sum;
            if(u<1000) limit=lower_bound(sum+1,sum+d+2,100)-sum;
            if(u<100) limit=lower_bound(sum+1,sum+d+2,10)-sum;
            if(u<10) limit=lower_bound(sum+1,sum+d+2,1)-sum;
            for(int i=j;i>=limit;i--)
                {
                    //if(u/sum[i]+d1>minc) continue;
                    //if(t[i])
                    int tmp=u-sum[i];
                    int tmp1=d1+1;
                    if(tmp>=0 && tmp1>minc) break;
                    if(tmp==0) {minc=min(tmp1+g,minc);break;}
                    p.push({tmp,tmp1});
                }
            if(ok==0) break;
        }
        cout<<minc<<endl;
    }
    return 0;
}

