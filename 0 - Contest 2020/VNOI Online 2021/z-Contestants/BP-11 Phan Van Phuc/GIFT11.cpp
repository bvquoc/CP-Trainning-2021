#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define se second

const ll INF=1e18;
const ll nmax=1e5+1;
const ll mod=1e9+7;

typedef pair<ll, ll> pa;
typedef vector<ll> ve;
typedef vector<ve> vve;
typedef vector<pa> vpa;

ifstream fi("GIFT11.INP");
ofstream fo("GIFT11.OUT");

ll t, n;
ll a[201];
ll mem[201];
bool kt(string s)
{
    ll pre=0;
    ll chan=0, le=0;
    for(ll i=0; i<s.size(); ++i)
    {
        if(pre) chan+=(s[i]-'0');
        else
            le+=(s[i]-'0');
        pre=(pre+1)%2;
    }
    if(chan==le)
        return true;
    return false;
}
string get_str(ll x)
{
    string res="";
    while(x!=0)
    {
        res=(char)(x%10+'0')+res;
        x/=10;
    }
    return res;
}
ll trau(ll i, string s)
{
    if(i>n)
    {
        if(kt(s))
            return 1;
        return 0;
    }
    ll res=0;
    for(ll j=1; j<=n; ++j)
        if(!mem[j])
        {
            mem[j]=1;
            res+=trau(i+1, s+get_str(a[j]));
            mem[j]=0;
        }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0), fi.tie(0), fo.tie(0);
    fi>>t;
    memset(mem, 0, sizeof(mem));
    while(t--)
    {
        fi>>n;
        for(ll i=1; i<=n; ++i)
            fi>>a[i];
        fo<<trau(1, "")<<'\n';
    }
}
