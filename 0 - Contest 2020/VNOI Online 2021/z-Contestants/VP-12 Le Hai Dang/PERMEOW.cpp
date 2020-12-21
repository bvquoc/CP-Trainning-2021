#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long LL;
const int MAXN=100+2e3;
const int inf=1+1e9;
const LL mod=1e9+7;
int n,a[MAXN],b[MAXN];
int fen[MAXN];
LL ans;
vector<int> v;
void update(int p, int val){
    for(int i = p; i <= n; i += i & -i)
        fen[i] += val;
}
int sum(int p) {
    int ans = 0;
    for(int i = p; i; i -= i & -i)
        ans += fen[i];
    return ans;
}
void sol1(){
    do{
        fill(fen+1,fen+n+1,0);
        int kt=1;
        for(int i=0;i<v.size();++i){
            if(v[i]!=b[i+1]) kt=0;
            int x=v[i];
            ans+=i-sum(v[i]);
            update(v[i],1);
            ans%=mod;
        }
        if(kt==1) break;
    }while(next_permutation(v.begin(),v.end()));
    cout<<ans;
}

namespace sub2 {

LL Pow (int n, int k) {
	if (k == 0) return 1;
  LL v = Pow(n, k / 2);
  if (k % 2) return v * v % mod * n % mod;
  return v * v % mod;
}

LL gt[MAXN];

void run() {
	gt[0] = 1;
  for (int i = 1; i <= n; ++i) {
		gt[i] = gt[i - 1] * i;
		gt[i] %= mod;
  }

  LL ans;
  ans = 1ll * n * (n - 1) * gt[n] % mod * Pow(4, mod - 2) % mod;

	cout << ans << '\n';
}

}
int main()
{
#define TASK "PERMEOW"
  if(fopen(TASK ".inp","r")){
    freopen(TASK ".inp","r",stdin);
    freopen(TASK ".out","w",stdout);
  }
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    int ck=0;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        v.push_back(a[i]);
    }
    for(int i=1;i<=n;++i){
        cin>>b[i];
        if(a[i]!=b[i]) ck=1;
    }
    if(ck==0){
        sol1();
        return 0;
    }
    sub2::run();
    return 0;
}
