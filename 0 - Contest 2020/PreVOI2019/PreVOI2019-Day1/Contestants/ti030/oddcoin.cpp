#include <bits/stdc++.h>

using namespace std;
long long T;
typedef pair<long long,long long> ii;
ii ans[100000000]
int main()
{
    freopen("oddcoin.inp","r",stdin);
    freopen("oddcoin.out","W",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    for (int k=1;k<=T;k++)
    {
        long long x,t,vt,ans=0;
        cin>>x>>t;
        bool ok=false;
        long long a[18]={0,1,3,5,10,30,50,10,300,500,1000,3000,5000,10000,30000,50000};
        a[16]=x;
        double b[18];
        sort(a+1,a+1+16);
        for (int i=1;i<=16;i++)
        {
            long long sl=t/=a[i];
            if (sl*a[i]==t)
             {
                 cout<<sl<<'\n';
                 ok=true;
             }
        }
        if(ok) continue;
        while(t>0)
        {
            long double dif=1e9;
            long long mn=1e9;
            vt=upper_bound(a+1,a+1+16,t)-a;
            for (int i=1;i<=vt;i++)
            {
                b[i]=(1.0*t)/a[i];
                if(i!=1)
                if(b[i]-trunc(b[i])<dif && trunc(b[i])<mn)
                {
                    mn=trunc(b[i]);
                    dif=b[i]-trunc(b[i]);
                }
                t-=a[i]*mn;
                ans+=mn;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
