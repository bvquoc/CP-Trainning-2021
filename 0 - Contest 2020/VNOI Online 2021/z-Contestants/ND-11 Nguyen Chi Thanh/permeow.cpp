#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb emplace_back
#define nmax 200010

const ll oo=1e9+7;
using namespace std;

int n,dem,a[nmax],b[nmax],bit[2*nmax];
ll res1,res2,f[nmax],gt[nmax];
vector<int> vt;
bool dd[nmax];
void update(int i,int val)
{
    for (;i<=n;i+=i&(-i)) bit[i]+=val;
}
int get(int i)
{
    int kq=0;
    for (;i>=1;i-=i&(-i)) kq+=bit[i];
    return kq;
}
void sx(int sz)
{
    for (int i=1;i<=sz;i++)
    {
        if (vt[i]==i) continue;
        int j;
        for (j=i+1;j<=sz;j++)
            if (vt[j]==i) break;
        swap(vt[i],vt[j]); ++dem;
    }
}
void sub1()
{
    vt.pb(0);
    for (int i=1;i<=n;i++) vt.pb(a[i]);
    sx(n);
    cout<<dem;
}
void sub2()
{
    cout<<f[n];
}
bool check1()
{
    for (int i=1;i<=n;i++)
        if (a[i]!=b[i]) return 0;
    return 1;
}
bool check2()
{
    for (int i=1;i<=n;i++)
        if (a[i]!=i) return 0;
    for (int i=1;i<=n;i++)
        if (b[i]!=n-i+1) return 0;
    return 1;
}
void sub4()
{
    for (int i=1;i<=n;i++) update(i,1);
    for (int i=1;i<=n;i++)
    {
        int sl=0;
        if (i<a[i] && dd[i]==0)
        {
            res1=(res1+dem*gt[n-i]%oo+f[n-i])%oo;
            --sl;
        }

        sl+=get(a[i]-1); ++dem;
        ll tam=(dem*gt[n-i]%oo+f[n-i])%oo;
        tam=tam*sl%oo;
        res1=(res1+tam)%oo; --dem;
        update(a[i],-1); dd[a[i]]=1;
        if (i==a[i]) continue;
        else if (a[i]>i) ++dem;
        else if (a[a[i]]==i) continue;
        else ++dem;
    }

    memset(bit,0,sizeof(bit));
    for (int i=1;i<=n;i++) update(i,1);
    memset(dd,0,sizeof(dd)); dem=0;

    for (int i=1;i<=n;i++)
    {
        int sl=0;
        if (i<b[i] && dd[i]==0)
        {
            res2=(res2+dem*gt[n-i]%oo+f[n-i])%oo;
            --sl;
        }

        sl+=get(b[i]-1); ++dem;
        ll tam=(dem*gt[n-i]%oo+f[n-i])%oo;
        tam=tam*sl%oo;
        res2=(res2+tam)%oo; --dem;
        update(b[i],-1); dd[b[i]]=1;
        if (i==b[i]) continue;
        else if (b[i]>i) ++dem;
        else if (b[b[i]]==i) continue;
        else ++dem;
    }

    dem=0; vt.clear(); vt.pb(0);
    for (int i=1;i<=n;i++) vt.pb(b[i]);
    sx(n); res2=(res2+dem)%oo;
    cout<<(res2-res1+oo)%oo;
}
int main()
{
    freopen("permeow.inp","r",stdin);
    freopen("permeow.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    gt[0]=1;
    for (int i=1;i<=200000;i++) gt[i]=gt[i-1]*i%oo;

    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];

    f[1]=0;
    for (int i=2;i<=n;i++)
        f[i]=(f[i-1]*i%oo+gt[i]-gt[i-1]+oo)%oo;

    if (check1())
    {
        sub1();
        return 0;
    }
    if (check2())
    {
        sub2();
        return 0;
    }
    if (n>2000)
    {
        sub4();
        return 0;
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=a[i];j++)
        {
            if (dd[j]==1) continue; ll ans=0;
            if (j==i) ans=dem;
            else if (j>i) ans=dem+1;
            else if (a[j]==i) ans=dem;
            else ans=dem+1;
            if (j<a[i]) res1=(res1+ans*gt[n-i]%oo+f[n-i])%oo;
            else dem=ans;
        }
        dd[a[i]]=1;
    }
    memset(dd,0,sizeof(dd)); dem=0;

    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=b[i];j++)
        {
            if (dd[j]==1) continue; ll ans=0;
            if (j==i) ans=dem;
            else if (j>i) ans=dem+1;
            else if (a[j]==i) ans=dem;
            else ans=dem+1;
            if (j<b[i]) res2=(res2+ans*gt[n-i]%oo+f[n-i])%oo;
            else dem=ans;
        }
        dd[b[i]]=1;
    }

    dem=0; vt.clear(); vt.pb(0);
    for (int i=1;i<=n;i++) vt.pb(b[i]);
    sx(n); res2=(res2+dem)%oo;
    cout<<(res2-res1+oo)%oo;
    return 0;
}
