#include <iostream>
#include <fstream>
#include <algorithm>
#define int long long
using namespace std;
const int nax=2e5+5;
const int M=1e9+7;
int n,a[nax],b[nax],s[nax],cnt[nax],f[nax],res=0,cur=0;
void update(int p,int value1)
{
    for(int i=p;i<=n;i+=-i&i)
    {
        f[i]+=value1;
    }
}
int query(int p)
{
    int ans=0;
    for(int i=p;i>=1;i-=-i&i)
    {
        ans+=f[i];
    }
    return ans;
}
void cal(int i)
{
    if(i>n)
    {
        res+=cur;
        res%=M;
        return;
    }
    int c=query(a[i]-1);
    int su=c*(c-1)/2;
    su%=M;
    int j=n-i;
    res+=(su+cur*c%M)%M*cnt[j]%M;
    res%=M;
    res+=c*s[j]%M;
    res%=M;
    cur+=c;
    cur%=M;
    update(a[i],-1);
    cal(i+1);
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("permeow.inp","r",stdin);
    freopen("permeow.out","w",stdout);
    cin>>n;
    s[0]=0;
    cnt[0]=1;
    for(int i=1;i<=n;i++)
    {
        cnt[i]=cnt[i-1]*i%M;
        int tmp=i*(i-1)/2;
        tmp%=M;
        s[i]=(cnt[i-1]*tmp%M+s[i-1]*i%M)%M;
    }
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)f[i]=0;
    for(int i=1;i<=n;i++)update(i,1);
    cur=0;
    cal(1);
    res-=cur;
    res%=M;
    res+=M;
    res%=M;
    int res1=res;
    res=0;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)f[i]=0;
    for(int i=1;i<=n;i++)update(i,1);
    cur=0;
    cal(1);
    int res2=res;
    int ans=res2-res1;
    ans%=M;
    ans+=M;
    ans%=M;
    cout<<ans<<endl;
    return 0;
}
