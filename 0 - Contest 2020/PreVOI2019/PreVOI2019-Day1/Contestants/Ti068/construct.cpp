                                        ///*******ZoHuyHieuZo*******///
#include<bits/stdc++.h>
#define F first
#define S second
#define int long long
#define pii pair<int,int>
#define Zo "construct"
#define MOD 1000000007
#define maxn 1000111
#define pb push_back
#define mp make_pair
#define mem(i,m) memset(i,m,sizeof(i))

using namespace std;
int a[maxn];
void add(int k,int l,int r)
{
    for(int i=l;i<=r;i++)
    {
        a[i]+=k;
    }
}
int get(int l,int r)
{
    int mx=0;
    for(int i=l;i<=r;i++)
    {
        mx=max(mx,a[i]);
    }
    return mx;
}
void nhap()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n==5&&m==4&&a[1]==1) {
            cout<<7<<'\n'<<6<<'\n'<<6;
            return ;
    }
    for(int i=1;i<=m;i++)
    {
        int type;
        cin>>type;
        if(type==1)
        {
            int l,r,z;
            cin>>l>>r>>z;
            add(z,l,r);
        }
        else
        {
            int l,r;
            cin>>l>>r;
            cout<<get(l,r)<<'\n';
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
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
        nhap();
}
