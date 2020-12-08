#include <bits/stdc++.h>

using namespace std;
long long n,m,mod,a[400005],f[4005][4005],t,x,haimuhain,kq,gt[400005],igt[400005];
bool check;
stack <int> st;
long long lt(long long x,long long y)
{
    if (y==0) return 1;
    if (y==1) return x;
    long long k=lt(x,y/2);
    if (y%2) return k*k%mod*x%mod;
             return k*k%mod;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("mine.inp","r",stdin);
    freopen("mine.out","w",stdout);
    cin>>n>>m;mod=1000003;
    for (int i=1;i<=2*n;++i) cin>>a[i];
    if (m>=a[2*n]-a[1])
    {
        gt[0]=1;
        for (int i=1;i<=2*n;++i) gt[i]=(gt[i-1]*i)%mod;
        igt[2*n]=lt(gt[2*n],mod-2);
        for (int i=2*n-1;i>=0;--i) igt[i]=(igt[i+1]*(i+1))%mod;
        cout<<((gt[2*n]*igt[n])%mod*igt[n+1])%mod;
        return 0;
    }
    if (n<=10)
    {
        haimuhain=(1<<(2*n));
        for (int i=1;i<haimuhain;++i)
        {
            t=0;check=true;
            for (int j=0;j<2*n;++j)
            if ((1<<j)&i)
            {
                t--;if (t<0) {check=false;break;}
            }
            else t++;
            if (check==false || t!=0) continue;
            while (!st.empty()) st.pop();
            for (int j=0;j<2*n;++j)
             if ((1<<j)&i)
            {
                x=st.top();
                st.pop();

                if (a[j+1]-a[x]>m) {check=false;break;}
            }
            else st.push(j+1);
            if (check==false) continue;

            kq=(kq+1)%mod;
        }
        cout<<kq;
        return 0;
    }
    for (int i=1;i<=2*n;++i) if (i>1) f[i-1][i]=(a[i]-a[i-1]<=m);

    for (int step=3;step<=2*n;step+=2)
     for (int i=1;i+step<=2*n;++i)
    {
        int j=i+step;
        if (a[j]-a[i]<=m) f[i][j]=f[i+1][j-1];
        t=0;
        for (int k=1;i+k+1<=j;k+=2)
          t=max(t,f[i][i+k]*f[i+k+1][j]);
        f[i][j]=(f[i][j]+t)%mod;

    }
    cout<<f[1][2*n];
    return 0;
}
