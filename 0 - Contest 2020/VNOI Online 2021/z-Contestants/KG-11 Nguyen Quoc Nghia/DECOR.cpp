#include <bits/stdc++.h>
#define TASK "DECOR"
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
int f[maxn],b[maxn];
char a[maxn];
int n,m,k,dq;
void sol(){
    int vt,maxx=0;
    For(i,1,n) {
        if (a[i]=='1'){
            f[i]=f[i-1]+1;
            if (f[i]>maxx){
                maxx=f[i];
                vt=i;
            }
        }else f[i]=0;
    }
    cout << vt-maxx+1 << ' ' << vt;
}
void solk(){
    int vt,maxx=0;
    int d=1;
    b[1]=-1;
    bool kt=false;
    if (a[1]=='1') {
        b[1]=1;
        kt=true;
    }
    For(i,2,n) {
        if (a[i]=='1'){
            if (!kt){
                d++;
                b[d]=1;
                f[d-1]=i-1;
                kt=true;
            }else b[d]++;
        }else
            if(kt){
                d++;
                b[d]=-1;
                f[d-1]=i-1;
                kt=false;
            }else b[d]--;
    }
    f[d]=n;
    f[d+1]=n;
    For(i,1,d){
        if (b[i]>0){
            int j=i+1;
            int du=k,res=b[i],vtt=0;
            bool kt=true;
            do{
                if (b[j]>0){
                    res+=b[j];
                    vtt=f[j];
                }
                else
                    if (abs(b[j])<=du){
                        res-=b[j];
                        du+=b[j];
                    }
                    else kt=false;
                j++;
            }
            while ((kt) && (j<=d));
            if (res>maxx){
                maxx=res;
                vt=vtt;
                dq=du;
            }
        }
    }
    int vtt=vt-maxx+1;
    while ((dq>0) && (vtt>1)){
        vtt--;
        if (a[vtt]=='0') dq--;
    }
    while ((dq>0) && (vt<n)){
        vt++;
        if (a[vt]=='0') dq--;
    }
    cout << vtt << ' ' << vt;
}
signed main()
{
  FAST;
  #ifndef ONLINE_JUDGE
    READFILE;
    WRITEFILE;
  #endif
  cin >> n >> m >> k;
  For(i,1,n) cin >> a[i];
  if (m==0){
    if (k==0) sol();
    else solk();
  }
  return 0;
}
