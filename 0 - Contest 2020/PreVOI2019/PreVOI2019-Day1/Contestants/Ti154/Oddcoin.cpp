#include<bits/stdc++.h>

using namespace std;

int n,t,x,s,a[20]={1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000};

main()
{
    freopen("Oddcoin.inp","r",stdin);
    freopen("Oddcoin.out","w",stdout);
    cin>>t;
    n=15;
    while(t--)
    {
        int y;
        cin>>x>>y;
        int ans=1e9;
        int bas=y/x,kq;
        for(int j=0;j<=bas;j++)
        {
            s=y-j*x;
            kq=j;
            for(int i=n-1;i>=0;i--)
            {
                if(s>=a[i])
                {
                    kq+=s/a[i];
                    s=s%a[i];
                }
                if(s==0) break;
            }
            ans=min(ans,kq);
        }
        cout<<ans<<'\n';
    }
}
