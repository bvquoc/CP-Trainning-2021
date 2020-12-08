#include<bits/stdc++.h>
#define int long long
using namespace std;
int x;
int a[]={1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000};
int f[50000001];
main()
{
    freopen("ODDCOIN.inp","r",stdin);
    freopen("ODDCOIN.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int q;
    cin>>q;
    while(q--)
    {
        int t;
        cin>>x>>t;
        f[0]=0;
        a[15]=x;
        if(x<=1e5&&t<=1e5)
        {
            for(int i=1;i<=t;i++)
            {
                f[i]=1e18;
                for(int j=0;j<16;j++)
                {
                    if(i>=a[j])f[i]=min(f[i-a[j]]+1,f[i]);
                }
            }
            cout<<f[t]<<'\n';
        }
        else if(x<=2*1e6&&t<=2*1e6)
        {
            int j=0;
            for(int i=1;i<=t;i++)
            {
                f[i]=1e18;
                if(i>=a[j+1])
                {
                    if(j<14)j++;
                    f[i]=f[i-a[j]]+1;
                }
                else
                {
                    f[i]=f[i-a[j]]+1;
                }
                if(i>=x)
                {
                    f[i]=min(f[i],f[i-x]+1);
                }
            }
            cout<<f[t]<<'\n';
        }
        else
        {
            sort(a,a+16);
            int res=0;
            while(t)
            {
                res+=t/a[j];
                t=t%a[j];
                j--;
            }
            cout<<res<<'\n';
        }
    }
}
