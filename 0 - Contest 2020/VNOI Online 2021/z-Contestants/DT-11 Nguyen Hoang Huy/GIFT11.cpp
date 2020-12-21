#include<bits/stdc++.h>
using namespace std;
#define N 2005
int T,n,chan[N],le[N],a[N],f[12][12];
void xlchan()
{
    for (int i=1;i<=n;i++)
    {
        int x=a[i],j=1;
        while (x>0)
        {
            j++;
            if (j%2==0) chan[i]+=x%10;
            else le[i]+=x%10;
            x=x/10;
        }
        chan[i]%=11;
        le[i]%=11;
    }
    memset(f,0,sizeof(f));
    f[0][0]=1;
    for (int i=1;i<=n;i++)
        for (int s=11;s>=chan[i];s--)
        for (int t=11;t>=le[i];t--)
        {
            f[s%11][t%11]+=f[(11+s-chan[i])%11][(11+t-le[i])%11];
        }
    int kq=0;
    for (int i=0;i<=10;i++) kq+=f[i][i];
    cout<<kq<<'\n';
}
main()
{
    freopen("GIFT11.INP","r",stdin);
    freopen("GIFT11.OUT","w",stdout);
    cin>>T;
    while (T--)
    {
        cin>>n;
        bool chan=1,le=1;
        for (int i=1;i<=n;i++)
        {
            cin>>a[i];
            int x=a[i],dem=0;
            while (x>0) {dem++;x/=10;}
            if (dem%2==1) chan=0;
            else le=0;
        }
        if (chan) xlchan();
        //else xlle();
    }
}
