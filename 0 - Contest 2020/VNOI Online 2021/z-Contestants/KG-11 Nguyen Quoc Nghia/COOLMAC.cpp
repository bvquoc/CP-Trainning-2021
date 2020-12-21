#include <bits/stdc++.h>
#define TASK "COOLMAC"
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define READFILE freopen(TASK".INP","r",stdin)
#define WRITEFILE freopen(TASK".OUT","w",stdout)
#define For(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define mp make_pair
#define ENDL '\n'
#define fi first
#define se second
#define ii pair <int,int>

using namespace std;
const int maxn = 100100, oo=10000000;
const int li=100000;
ii a[maxn];
int f[maxn],d[maxn];
int n,m,ans=oo,minn=oo;;
bool cmp(ii x, ii y){
    if (x.se != y.se) return x.se>y.se;
    else return x.fi>y.fi;
}
void dp(){
    f[1]=1;
    d[1]=a[1].fi;
    For(i,2,m){
        int res=oo;
        For(j,1,i-1)
            if (a[i].se>=d[j]-1) {
                    res=min(res,f[j]+1);
                    d[i]=min(a[i].fi,d[j]);
            }
        if (res==oo) {
            cout << -1;
            exit(0);
        }else f[i]=res;
        if (d[i]<=minn) ans=min(ans,f[i]);

    }
}
signed main()
{
  FAST;
  #ifndef ONLINE_JUDGE
    READFILE;
    WRITEFILE;
  #endif
  cin >> m;
  For(i,1,m) cin >> a[i].fi >> a[i].se;
  cin >> n;
  For(i,1,n){
    int u;
    cin >> u;
    if (minn>u) minn=u;
  }
  sort(a+1,a+1+m);
  if (a[1].fi>minn){
    cout << -1;
    exit(0);
  }
  sort(a+1,a+m+1,cmp);
  if (a[1].se<li){
    cout << -1;
    exit(0);
  }
  dp();
  cout << ans;
  return 0;
}

