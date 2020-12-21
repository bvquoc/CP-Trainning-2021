///*******ZoHuyHieuZo*******///
#include<bits/stdc++.h>
#define F first
#define S second
#define int long long
#define pii pair<int,int>
#define Zo "Permeow"
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
int fl=0,a[maxn],b[maxn],pos[maxn],d[maxn],gt[maxn];
void nhap()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        pos[a[i]]=i;
    }
    for(int i=1; i<=n; i++)
    {
        cin>>b[i];
        if(a[i]!=b[i])
            fl=1;
    }
    gt[0]=1;
    for(int i=1;i<=n;i++)
    {
        gt[i]=gt[i-1]*i;
    }
    int ans=0;
    if(fl==0)
    {
        for(int i=1; i<=n; i++)
        {
            int j=pos[i];
            while(a[j]<a[j-1]&&j>1)
            {
                ans++;
                swap(a[j],a[j-1]);
                swap(pos[a[j]],pos[a[j-1]]);
                j--;
            }
        }
        cout<<ans;
    }
    else
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=i; j++)
            {
                d[i]=(d[i]+d[i-1]+(j-1)*gt[i-1]%MOD)%MOD;
            }
        }
        cout<<d[n];
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
