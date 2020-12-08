#include <bits/stdc++.h>
using namespace std;
#define int long long
#define y1 zzz
#define fi first
#define se second
#define PII pair<int,int>
#define PII2 pair<int,PII >
#define PII3 pair<PII,int >
#define PII4 pair<PII,PII >
#define pb push_back;
int t_val[2000010],t_diff[2000010],diff[1000010],a[1000010];
int n,m;
void upd_val(int l,int r,int val)
{
    for(l+=n,r+=n;l<r;l>>=1,r>>=1)
    {
        if(l&1)t_val[l++]+=val;
        if(r&1)t_val[--r]+=val;
    }
}
int get_val(int i)
{
    int res=a[i];
    for(i+=n;i>0;i>>=1)res+=t_val[i];
    return res;
}
void build()
{
    for(int i=1;i<n;i++)t_diff[i+n]=max(0LL,diff[i]);
    for(int i=n-1;i>0;i--)t_diff[i]=t_diff[i<<1]+t_diff[i<<1|1];
}
void upd_diff(int i)
{
    int new_diff=get_val(i)-get_val(i-1);
    new_diff=max(0LL,new_diff);
    for(t_diff[i+=n]=new_diff;i>0;i>>=1)t_diff[i>>1]=t_diff[i]+t_diff[i^1];
}
int get_diff(int l,int r)
{
    int res=0;
    for(l+=n,r+=n;l<r;l>>=1,r>>=1)
    {
        if(l&1)res+=t_diff[l++];
        if(r&1)res+=t_diff[--r];
    }
    return res;
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=2*n;i++)
    {
        t_val[i]=0;
        t_diff[i]=0;
    }
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=1;i<n;i++)diff[i]=a[i]-a[i-1];
    build();
    for(int i=0;i<m;i++)
    {
        int ope,l,r,k;
        cin>>ope>>l>>r;
        if(ope==1)
        {
            cin>>k;
            upd_val(l-1,r,k);
            if(l>1)upd_diff(l-1);
            if(r<n)upd_diff(r);
            upd_diff(l);
            upd_diff(r-1);
        }
        else
        {
            cout<<get_val(l-1)+get_diff(l,r)<<'\n';
        }
        //for(int j=n;j<2*n;j++)cerr<<t_diff[j]<<" ";cerr<<'\n';
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    freopen("construct.inp", "r", stdin);
    freopen("construct.out", "w", stdout);
    int test;cin>>test;while(test--)
    solve();
    return 0;
}
/*
2
5 4
1 3 1 4 5
2 1 5
1 3 4 2
2 2 4
2 1 5
6 4
1 8 2 4 5 3
1 4 5 2
2 2 3
2 4 6
2 4 4
*/
