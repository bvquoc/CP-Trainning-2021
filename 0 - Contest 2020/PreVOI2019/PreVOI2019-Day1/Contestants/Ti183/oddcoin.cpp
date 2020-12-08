#include <bits/stdc++.h>

using namespace std;
long long a[17]={0,1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000,0};
long long f[100005],t,q,haimumuoisau,kq,sl,T;
vector<long long> vec;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("oddcoin.inp","r",stdin);
    freopen("oddcoin.out","w",stdout);
    cin>>q;haimumuoisau=(1<<16);
    for (int test=1;test<=q;++test)
    {
        cin>>a[16]>>t;if (a[16]==0) a[16]=t+1;
        if (t<=100000)
        {

            for (int i=1;i<=t;++i)

             {
                 f[i]=i;
                 for (int j=1;j<=16;++j)
                   if (i-a[j]>=0) f[i]=min(f[i],f[i-a[j]]+1);
             }
            cout<<f[t];
        }
        else
        {
            kq=t;
            for (int i=1;i<haimumuoisau;++i)
            {
                vec.clear();sl=0;T=t;
                for (int j=0;j<16;++j)
                    if ((1<<j)&i) vec.push_back(a[j+1]);
                sort(vec.begin(),vec.end());
                for (int j=vec.size()-1;j>=0;--j)
                {
                    sl=sl+T/vec[j];
                    T%=vec[j];
                }
                if (T==0) kq=min(kq,sl);
            }
            if (t/a[16]<=100000)
            {
                for (int i=0;i<=t/a[16];++i)
                {
                    T=t-i*a[16];
                    sl=i;
                    for (int j=15;j>0;--j)
                    {
                        sl=sl+T/a[j];
                        T%=a[j];
                    }
                    kq=min(kq,sl);
                }
            }
            cout<<kq;
        }
        cout<<'\n';

    }
    return 0;
}
