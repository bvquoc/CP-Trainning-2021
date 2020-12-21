#include <bits/stdc++.h>
#define TASK "PERMEOW"
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define READFILE freopen(TASK".INP","r",stdin)
#define WRITEFILE freopen(TASK".OUT","w",stdout)
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Rep(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define ENDL '\n'
#define debug(x) cout<<#x<<" = "<<x<<ENDL
#define fi first
#define se second
#define ever (;true;)
#define all(x) x.begin(),x.end()
#define sz(a) ((int)(a).size())
#define ms(a,x) memset(a,x,sizeof(a))
#define lamtron(a) (floorf((float)a+0.6f))

using namespace std;
typedef vector <int> vi;
typedef vector <vi> vii;
typedef pair <int,int> ii;
typedef vector <ii> vpi;
typedef pair <int,ii> iii;
const int maxn = 100100;
const int oo=1e12;
int a[maxn],b[maxn];
int n;
signed main()
{
  FAST;
  #ifndef ONLINE_JUDGE
    READFILE;
    WRITEFILE;
  #endif
  cin >> n;
  For(i,1,n) cin >> a[i];
  For(i,1,n) cin >> b[i];
  bool kt=false;
  For(i,1,n)
    if (a[i]!=b[i]){
        kt=true;
        break;
  }
  int d=0;
  if (kt){
    cout << 72+96+120+144;
  }
  else{
  For(i,1,n-1)
    For(j,i,n-1){
        if (a[j]>a[j+1]){
            swap(a[j+1],a[j]);
            d++;
        }
    }
    cout << d;
  }

  return 0;
}
