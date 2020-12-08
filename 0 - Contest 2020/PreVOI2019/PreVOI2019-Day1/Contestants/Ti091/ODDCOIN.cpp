#include<bits/stdc++.h>
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define st first
#define nd second
#define int long long
#define mid (l+r)/2
using namespace std;
const int N=1e6+4;
int q;
int f[N],a[20];
main()
{
    freopen("ODDCOIN.inp","r",stdin);
    freopen("ODDCOIN.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie();cout.tie();
    a[1]=1,a[2]=3,a[3]=5;
    forinc(i,4,15) a[i]=a[i-3]*10;
    cin >> q;
    while(q--)
    {
        int x,t,res=0   ;
        cin >> x >> t;
        a[16]=x;
        sort(a+1,a+1+16);
        if (t>5e7)
        {
            res+=t/a[16];
            t-=res*a[16];
        }
        memset(f,127,sizeof f);
        f[0]=0;
        forinc(i,1,t)
        {
            forinc(j,1,16)
            {
                if (i-a[j]>=0) f[i]=min(f[i-a[j]]+1,f[i]);
            }
        }
        cout << f[t] << "\n";
    }
}
