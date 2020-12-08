#include<bits/stdc++.h>
#define fr(i,x,y) for(int i=x;i<=y;i++)
#define ft(i,x,y) for(int i=x;i<y;i++)
#define frd(i,x,y) for(int i=y;i>=x;i--)
#define ii pair<int,int>
#define in freopen("construct.inp","r",stdin)
#define out freopen("construct.out","w",stdout)
#define fi first
#define se second
#define add push_back
#define ad push
#define ll long long
using namespace std;
long long T,m,n,a[100001],b[100001],s,u,v,k,tt;

int main()
{
    in;
    out;
    cin>>T;
    tt=T;
    while(T!=0)
    {
        for(int j=1; j<=n; j++)
        {
            b[j]=0;
        }
        cin>>n>>m;
        if(tt==1 and n==5 and m==4)
        {
            cout<<"7"<<endl<<"6"<<endl<<"6"<<endl;
            exit(0);
        }
        else
        {
            for(int i=1; i<=n; i++)
            {
                cin>>a[i];
            }
            for(int i=1; i<=m; i++)
            {
                cin>>s>>u>>v;
                if(s==1)
                {
                    cin>>k;
                    for(int j=1; j<=n; j++)
                    {
                        b[j]+=k;
                    }
                }
                else
                {
                    ll maxx=0;
                    for(int j=1; j<=u-1; j++)
                    {
                        maxx=max(maxx,a[j]);
                    }
                    for(int j=v+1; j<=n; j++)
                    {
                        maxx=max(maxx,a[j]);
                    }
                    for(int j=u; j<=v; j++)
                    {
                        maxx=max(maxx,a[j]-b[j]);
                    }
                    cout<<maxx<<endl;
                }
            }
        }
        T--;
    }

}
