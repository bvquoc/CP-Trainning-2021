#include <bits/stdc++.h>

using namespace std;
long long A[20],kt[20],t,n,ans,a[10009],v,i,j,dem,chan,le,demchan,demle,h;
const int Nmod = 998244353;
int scs(int n)
{
    int dem=0;
    while (n>0)
    {
        n=n/10;
        dem++;
    }
    return dem;
}
void Try(int k) {
    for (int i = 1; i <= n; i++)
    {
        if (!kt[i]) {
            A[k] = a[i];
            kt[i] = 1;
            if (k == n)
            {
                int v,z,chan=0,le=0,b[20],demm=0,h;
                for (int j=1;j<=n;j++)
                {
                    v=A[j];z=0;
                    while (v>0)
                    {
                        z++;
                        b[z]=v%10;
                        v/=10;
                    }
                    for (int u=z;u>=1;u--)
                    {
                        demm++;
                        if (demm%2==1)
                            le+=b[u];
                        else chan+=b[u];
                    }
                }
                h=abs(chan-le);
                if (h%11==0)
                    ans++;
            }
            else
                Try(k + 1);
            kt[i] = 0;
        }
    }
}
int main()
{
    freopen("GIFT11.INP","r",stdin);
    freopen("GIFT11.OUT","w",stdout);
    cin>>t;
    while (t--)
    {
        cin>>n;
        demchan=0;demle=0;
        for (i=1;i<=n;i++)
        {
            cin>>a[i];
            if (scs(a[i])%2==0)
                demchan++;
            if (scs(a[i])%2==1)
                demle++;
        }
        if (demchan==n)
        {
            chan=0;le=0;
            for (i=1;i<=n;i++)
            {
                v=a[i];
                while (v>0)
                {
                    h=v%10;
                    dem++;
                    if (dem%2==1)
                        chan+=h;
                    else le=le+h;
                    v/=10;
                }
            }
            h=abs(chan-le);
            if (h%11!=0)
                cout<<0<<endl;
            else {
                v=1;
                for (i=2;i<=n;i++)
                    v=((v%Nmod)*(i%Nmod))%Nmod;
                cout<<v<<endl;
            }
        }
        else
        {
            for (i=1;i<=n;i++)
                A[i]=a[i];
            for (i=0;i<=18;i++)
                kt[i]=0;
            ans=0;
            Try(1);
            cout<<ans<<endl;
        }
    }
    return 0;
}
