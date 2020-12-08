#include<bits/stdc++.h>
#define fr(i,x,y) for(int i=x;i<=y;i++)
#define ft(i,x,y) for(int i=x;i<y;i++)
#define frd(i,x,y) for(int i=y;i>=x;i--)
#define ii pair<int,int>
#define in freopen("mine.inp","r",stdin)
#define out freopen("mine.out","w",stdout)
#define fi first
#define se second
#define add push_back
#define ad push
#define ll long long
using namespace std;
long long n,m,a[400001],tt,t,dem,ans;

int main()
{
    in;
    out;
    cin>>n>>m;
    for(int i=1; i<=2*n; i++)
        cin>>a[i];
    ll vt=lower_bound(a+1,a+2*n+1,a[1]+m)-a;
    if(a[vt]>a[1]+m)
        vt--;
    if(vt%2!=0)
        vt--;
    a[2*n+1]=1e18;
    while(vt!=0)
    {
        tt=vt+1;
        dem=1;
        //cout<<tt<<endl;
        while(tt<=2*n)
        {
            //tt=vt+1;
            ll t=lower_bound(a+tt,a+2*n+1,a[tt]+m)-a;
            //cout<<t<<endl;
            if(a[t]>a[tt]+m)
                t--;
            if((t-tt+1)%2!=0)
                t--;
            dem*=(t-tt+1)/2;
            //cout<<tt<<" "<<t<<endl;
            tt=t+1;
            //cout<<vt<<" "<<t<<endl;
        }
        //cout<<"cc"<<endl;
        ans+=dem;
        vt-=2;
    }
    cout<<ans;
    return 0;
}
