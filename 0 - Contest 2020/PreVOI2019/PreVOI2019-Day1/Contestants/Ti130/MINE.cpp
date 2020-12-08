#include<bits/stdc++.h>
#define int long long
using namespace std;
int f[2000][2000];
int a[2000];
int mod=1e6+3;
main()
{
    freopen("MINE.inp","r",stdin);
    freopen("MINE.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=2*n;i++)
    {
        cin>>a[i];
    }
    //sort(a+1,a+2*n+1);
    /*if(n<=10)
    {
        while(next_permutation(p))
        {
            for(int i=0;i<p.size();i++)
            {
                if(p[i]<=n)
                {
                    in[p[i]]=i;
                }
                else
                {
                    out[n-p[i]]=i;
                }
            }
            for(int i=1;i<=n;i++)
            {
                if(a[in[i]]>a[out[i]]||a[out[i]]-a[in[i]]>m)
                {
                    check=1;
                    break;
                }
                if(in[i]<in[i-1])
                {
                    check=1;
                    break;
                }
                for(int j=1;j<=n;j++)
                {
                    if(in[i]>in[j]&&out[i]>out[j]&&in[i]<out[j])
                    {
                        check=1;
                        break;
                    }
                }
            }
            if(check==0)res++;
            cout<<res;
        }
    }
    else if(m==1000000)
    {
        f[0]=1;
        f[1]=1;
        for(int i=2;i<=n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                f[i]=(f[i]+f[j]*f[i-1-j])%mod;
            }
        }
        cout<<f[n];
    }*/
    if(n<=2000)
    {
        for(int len=2;len<=2*n;len+=2)
        {
            for(int i=1;i<=2*n;i++)
            {
                int j=i+len-1;
                if(j>2*n)break;
                for(int x=i+1;x<j;x+=2)
                {
                    f[i][j]+=f[i][x]*f[x+1][j];
                    f[i][j]%=mod;
                }
                if(a[j]-a[i]<=m)f[i][j]++;
                //f[i][j]=(f[i][j]+1)/2;
                //cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
            }
        }
    }
    cout<<((f[1][2*n]+1)/2)%mod;
}
