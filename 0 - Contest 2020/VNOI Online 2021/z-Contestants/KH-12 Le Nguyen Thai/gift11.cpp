#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
long long t,n,a[2010];
string s[2010];
int main()
{
    freopen("GIFT11.inp","r",stdin);
    freopen("GIFT11.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    for(int x=1;x<=t;x++)
    {
        cin>>n;
        for(int i=1;i<=n;i++) cin>>s[i];
        long long sum=0;
        for(int i=1;i<=n;i++)
        {
            int cnt=0;
            for(int j=s[i].length()-1;j>=0;j--)
            {
                cnt++;
                int v=s[i][j]-'0';
                if((cnt)%2==1)
                {
                    sum=sum+v;
                }
                else sum-=v;
            }
        }
        if(sum%11==0)
        {
            long long ans=1;
            for(int i=1;i<=n;i++)
            {
                ans=(ans*i)%MOD;
            }
            cout<<ans<<endl;
        }
        else cout<<0<<endl;
    }
    return 0;
}
