						///*******ZoHuyHieuZo*******///
#include<bits/stdc++.h>
#define F first
#define S second
#define int long long
#define pii pair<int,int>
#define Zo "Decor"
#define MOD 1000000007
#define maxn 1000111
#define pb push_back
#define mp make_pair
#define mem(i,m) memset(i,m,sizeof(i))
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1) // kiem tra bit i
#define SET_ON(x, i) ((x) | MASK(i)) // bat bit thu i cua x
#define SET_OFF(x, i) ((x) & ~MASK(i)) // tat bit thu i cua x

using namespace std;
    int n,m,k;
    int sum[maxn],a[maxn];
    string s;
bool check(int g)
{
    for(int i=1;i<=n;i++)
    {
        int j=i+g-1;
        if(sum[j]-sum[i-1]+k>=g)
            return true;
    }
    return false;
}
void tv(int g)
{
    for(int i=1;i<=n;i++)
    {
        int j=i+g-1;
        if(sum[j]-sum[i-1]+k>=g)
        {
            cout<<i<<" "<<j;
            return ;
        }
    }
}
void nhap()
{
    cin>>n>>m>>k;
    cin>>s;
    s=' '+s;
    for(int i=1;i<s.size();i++)
    {
        a[i]=s[i]-'0';
        sum[i]=sum[i-1]+a[i];
    }
    if(m==0)
    {
        int l=1,r=n,res=-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(check(mid)==true)
            {
                res=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        if(res==-1)
        {
            cout<<res;
        }
        else
        {
            tv(res);
        }
    }

}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(Zo".inp","r",stdin);
    freopen(Zo".out","w",stdout);
    nhap();
}
