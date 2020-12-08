#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

const string INP=".INP", OUT=".OUT";
const string FILENAME="RATING";
const int N=300005;
#define int long long

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

int n, q, a[N];
int l, r, x;
int psum[N];

int32_t main() {
    FastIO;
    freopen((FILENAME+INP).c_str(),"r",stdin);
    freopen((FILENAME+OUT).c_str(),"w",stdout);
    int T; Read(T);
    Read(n); Read(q);
    for (int i=1;i<=n;i++) {
        Read(a[i]);
        psum[i]=a[i]+psum[i-1];
    }
    if (T==1) { // Subtask 1
        while (q--) {
            Read(x); Read(l); Read(r);
            for (int i=l;i<=r;i++)
                x=abs(x-a[i]);
            Write(x);
            putchar('\n');
        }
        return 0;
    } else if (T==2) {
        while (q--) {
            Read(x); Read(l); Read(r);
            x-=(psum[r]-psum[l-1]);
            Write(x);
            putchar('\n');
        }
        return 0;
    } else if (T==3) {
        while (q--) {
            Read(x); Read(l); Read(r);
            int c=r-l+1;
            if (x<0) {
                x=abs(x-a[1]);
                c--;
            }
            if (a[1]==0) {
                Write(x);
                putchar('\n');
                continue;
            }
            int d=min(c,x/a[1]);
            x-=a[1]*d; c-=d;
            if (c%2) x=a[1]-x;
            Write(x);
            putchar('\n');
        }
        return 0;
    }
    return 0;
}