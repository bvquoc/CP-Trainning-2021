#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+7;
int n;
struct FT
{
    vector<int> t;
    ll Get(int x )
    {
        ll res=0;
        for(;x;x-=x&-x)
            res+=0ll+t[x];
        return res;
    }
    void Update(int x,int val)
    {
        for(;x<=n;x+=x&-x)
            t[x]+=val;
    }
}BIT;
bool isSub1=1;
int a[N],b[N];
void inp()
{
    cin>>n;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n;++i)
    {
        cin>>b[i];
        if(b[i]!=a[i]) isSub1=0;
    }
    BIT.t.resize(n+1);
}
ll sub1()
{
    ll res=0;
    for(int i=1;i<=n;++i)
    {
        BIT.Update(a[i],1);
        res+=BIT.Get(n)-BIT.Get(a[i]);
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("PERMEOW.inp","r",stdin);
    freopen("PERMEOW.out","w",stdout);
    inp();
    cout<<sub1();
    return 0;
}
