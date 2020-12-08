#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
#define int long long

const string INP=".INP", OUT=".OUT";
const string FILENAME="BONUS";
const int N=302;

template <typename T>
inline void Read(T& x) {
    bool Neg=false;
    char c;
    for (c=getchar();c<'0' || c>'9';c=getchar()) if (c=='-') Neg=!Neg;
    x=c-'0';
    for (c=getchar();c>='0' && c<='9';c=getchar()) x=x*10+c-'0';
    if (Neg) x=-x;
}
template <typename T>
inline void Write(T x) {
    if (x<0) { putchar('-'); x=-x; }
    T p=1;
    for (T temp=x/10;temp>0;temp/=10) p*=10;
    for (;p>0;x%=p,p/=10) putchar(x/p+'0');
}

int n, k, a[N];
int f[N][N][N];
int res;

int dp(int l, int r, int p) {
    if (p<=0 || l>=r) return 0;
    if (f[l][r][p]!=-1) return f[l][r][p];
    if (p==1 && r-l==1) return abs(a[l]-a[r]);
    int cur=max(dp(l+1,r,p),dp(l,r-1,p));
    if (p>=1) {
        cur=max(cur,dp(l+1,r-1,p-1)+abs(a[l]-a[r]));
        cur=max(cur,dp(l+2,r,p-1)+abs(a[l]-a[l+1]));
        cur=max(cur,dp(l,r-2,p-1)+abs(a[r]-a[r-1]));
    }
    return f[l][r][p]=cur;
}
int32_t main() {
    FastIO;
    freopen((FILENAME+INP).c_str(),"r",stdin);
    freopen((FILENAME+OUT).c_str(),"w",stdout);
    Read(n); Read(k);
    for (int i=1;i<=n;i++)
        Read(a[i]);
    for (int i=0;i<=n;i++)
        for (int j=0;j<=n;j++)
            for (int l=1;l<=k;l++)
                f[i][j][l]=-1;
    res=dp(1,n,k);
    Write(res);
    return 0;
}
