#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
using namespace std;

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

#define int long long
#define oo LLONG_MAX
const int n=15, N=1000000;
const int a[]={0,1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000};
int x, t, T;
int f[N+1];
int res, cur;

int32_t main(void) {
    FastIO;
    freopen("ODDCOIN.INP","r",stdin);
    freopen("ODDCOIN.OUT","w",stdout);
    for (int i=1;i<=a[n];i++) {
        f[i]=oo;
		for (int j=1;j<=n;j++)
		if (a[j]<=i) f[i]=min(f[i],1+f[i-a[j]]);
		else break;
	}
    int q; Read(q);
    while (q--) {
        Read(x); Read(t);
        res=oo;
        for (int cnt=0;cnt<=50000;cnt++) {
            if (cnt*x>t) break;
            T=t-cnt*x;
            cur=cnt+T/a[n]+f[T%a[n]];
            res=min(res,cur);
        }
        Write(res); putchar('\n');
    }
    return 0;
}