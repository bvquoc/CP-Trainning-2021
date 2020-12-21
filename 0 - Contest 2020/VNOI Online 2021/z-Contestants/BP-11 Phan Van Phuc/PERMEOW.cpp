#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define se second

const ll mod=1e9+7;
const ll INF=1e18;
const ll nmax=1e5+1;

typedef vector<ll> ve;
typedef vector<ve> vve;
typedef pair<ll, ll> pa;
typedef vector<pa> vpa;

ifstream fi("PERMEOW.INP");
ofstream fo("PERMEOW.OUT");

ll n;
ll a[2*nmax];
ll b[2*nmax];
ll local[2*nmax];
void sub1() {
     ll res=0;
     for(ll i=1; i<=n; ++i)
          local[a[i]]=i;
     for(ll i=1; i<=n; ++i) {
          ll x=local[i];
          if(x==i)
               continue;
          for(; x>i; --x) {
               res++;
               a[x]=a[x-1];
               local[a[x]]++;
          }
     }
     fo<<res;
}
int main() {
     ios_base::sync_with_stdio(0), fi.tie(0), fo.tie(0);
     fi>>n;
     for(ll i=1; i<=n; ++i)
          fi>>a[i];
     for(ll i=1; i<=n; ++i)
          fi>>b[i];
     bool ok=true;
     for(ll i=1; i<=n; ++i)
          if(a[i]!=b[i])
               ok=false;
     if(ok) {
          sub1();
          return 0;
     }
}
