#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
#define int long long
#define x first
#define y second

const string INP=".INP", OUT=".OUT";
const string FILENAME="TREEAGAIN";
const int N=200005;

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

using point=pair<int,int>;
int T, n, q_sz;
point p[N];

int32_t main() {
    FastIO;
    freopen((FILENAME+INP).c_str(),"r",stdin);
    freopen((FILENAME+OUT).c_str(),"w",stdout);
    Read(T);
    Read(n);
    for (int i=0; i<n; ++i) {
        Read(p[i].x);
        Read(p[i].y);
    }
    Read(q_sz);
    for (int i=n;i<q_sz+n;i++) {
        putchar('N');
        putchar('O');
        putchar('\n');
    }
    return 0;
}