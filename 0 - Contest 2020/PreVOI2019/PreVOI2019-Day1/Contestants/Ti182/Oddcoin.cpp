#include <bits/stdc++.h>
using namespace std;
#define pii pair<ll,ll>
#define F first
#define S second
typedef long long ll;


vector<ll> a;
unordered_map<int,int> m;
ll kq;

ll pw(ll a,ll b)
{
    ll kq=1;
    for(ll i=1;i<=b;++i)
    {
        kq*=a;
    }
    return kq;
}
void khoitao()
{
    for(int i=0;i<15;++i)
    {
        if(i%3==0) a.push_back(ll(pw(10,i/3)));
        else if(i%3==1) a.push_back(ll(pw(10,i/3))*3);
        else a.push_back(ll(pw(10,i/3))*5);
    }
}
void solve(ll t,ll d)
{
    if(d>kq) return; m[t]=d;
    for(int i=15;i>=0;--i)
    {
        ll b=t-a[i];if(b<0) continue;
        if(b==0) {kq=min(kq,d+1);return;}
        if(m[b]==0||(d+1)<m[b]) solve(b,d+1);
    }
}
int main()
{
    freopen("Oddcoin.inp","r",stdin);
    freopen("Oddcoin.out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);
    khoitao();
    int q;
    cin>>q;
    while(q--)
    {
        ll x,t;
        int vt;
        cin>>x>>t;
        if(x>50000) {a.push_back(x);vt=15;}
        else for(int i=0;i<15;++i)
        {
            if(x<a[i]) {a.insert(a.begin()+i,x);vt=i;break;}
        }
        kq=15+t/100000;
        solve(t,0);
        cout<<kq<<endl;
        a.erase(a.begin()+vt);
    }
    return 0;
}
