#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
#define int long long

const string INP=".INP", OUT=".OUT";
const string FILENAME="NASA";
const int N=100005;
typedef pair <int,int> ii;

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

int n, m, a[N];
int res=LLONG_MAX;
int f[N];

int32_t main() {
    FastIO;
    freopen((FILENAME+INP).c_str(),"r",stdin);
    freopen((FILENAME+OUT).c_str(),"w",stdout);
    Read(n); Read(m);
    for (int i=1;i<=n;i++) {
        Read(a[i]);
    }

    for (int i=1;i<=n;i++) f[i]=LLONG_MAX;
    f[1]=a[1];
    for (int i=2;i<=n;i++) {
        for (int step=1;step<=m && i-step>0;step++)
            f[i]=min(f[i-step]+a[i],f[i]);
    }
    for (int i=max(1LL,n-m+1LL);i<=n;i++) 
        res=min(res,f[i]);
    Write(res);

    return 0;
}