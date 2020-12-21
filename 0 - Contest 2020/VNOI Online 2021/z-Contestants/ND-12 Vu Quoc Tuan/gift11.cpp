#include <bits/stdc++.h>

using namespace std;
long long mod,te,v[15],F[2005][12][2015],G[2005][12][2005],c[2][2005],le[2005],chan[2005],kq1[15],kq2[15],gt[2015];
int main()
{
    freopen("gift11.inp","r",stdin);
    freopen("gift11.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>te;

    mod=998244353;

    gt[0]=1;
    for (int i=1;i<=2010;++i) gt[i]=gt[i-1]*i%mod;



    while (te--)
    {
        int n,cnt,cnt2;cnt=cnt2=0;
        cin>>n;
        memset(c,0,sizeof(c));
        for (int i=1;i<=n;++i)
        {
            long long d=1;
            int x;
            cin>>x;
            int p=0;
            while (x)
            {
                v[++p]=x%10;
                x/=10;
            }
            if (p%2) le[++cnt]=i;else chan[++cnt2]=i;
            for (int j=p;j>0;--j)
            {
                c[0][i]=(c[0][i]+v[j]*d+11)%11;
                d=-d;
                c[1][i]=(c[1][i]+v[j]*d+11)%11;
            }
        }
        int b0,b1;
        if (cnt%2) b0=b1=cnt/2+1;
        else
        {
            b0=cnt/2+1;
            b1=cnt/2;
        }

        for (int i=0;i<=cnt2;++i)
         for (int j=0;j<11;++j)
          for (int x=0;x<=n+10;++x) F[i][j][x]=0;
        F[0][0][b0]=1;

        for (int i=0;i<cnt2;++i)
         for (int j=0;j<11;++j)
          for (int x=0;x<=n+10;++x)
          if (F[i][j][x])
          {

              F[i+1][(j+c[0][chan[i+1]])%11][x+1]+=F[i][j][x]*x;
              F[i+1][(j+c[0][chan[i+1]])%11][x+1]%=mod;

              int y=b1+i-(x-b0);

              F[i+1][(j+c[1][chan[i+1]])%11][x]+=F[i][j][x]*y;
              F[i+1][(j+c[1][chan[i+1]])%11][x]%=mod;
          }
        memset(kq1,0,sizeof(kq1));
        for (int j=0;j<11;++j)
         for (int x=0;x<=n+10;++x) kq1[j]=(kq1[j]+F[cnt2][j][x])%mod;

        int C,L;
        if (cnt%2)
        {
            C=cnt/2+1;
            L=cnt/2;
        }
        else C=L=cnt/2;

        for (int i=0;i<=cnt;++i)
         for (int j=0;j<11;++j)
          for (int x=0;x<=C;++x) G[i][j][x]=0;
        G[0][0][0]=1;

        for (int i=0;i<cnt;++i)
         for (int j=0;j<11;++j)
          for (int x=0;x<=C;++x)
           if (G[i][j][x])
        {
            G[i+1][(j+c[0][le[i+1]])%11][x+1]+=G[i][j][x];
            G[i+1][(j+c[0][le[i+1]])%11][x+1]%=mod;

            G[i+1][(j+c[1][le[i+1]])%11][x]+=G[i][j][x];
            G[i+1][(j+c[1][le[i+1]])%11][x]%=mod;

        }




        memset(kq2,0,sizeof(kq2));
        for (int j=0;j<11;++j) kq2[j]=(kq2[j]+G[cnt][j][C]*gt[C]%mod*gt[L]%mod)%mod;

        long long ans=0;
        ans=kq1[0]*kq2[0]%mod;
        for (int i=1;i<11;++i) ans=(ans+kq1[i]*kq2[11-i])%mod;
        cout<<ans<<'\n';
    }
    return 0;
}
