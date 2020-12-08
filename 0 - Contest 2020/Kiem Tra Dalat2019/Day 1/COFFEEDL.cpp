#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
#define int long long
#define fi first
#define se second

typedef pair <int,int> ii;

const string INP=".INP", OUT=".OUT";
const string FILENAME="COFFEEDL";
const int N=100005;

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

int n, q, m;
ii a[N];

inline int dist(const ii &A, const ii &B) { return abs(A.fi-B.fi)+abs(A.se-B.se); }

int cur, _x, _y;
void solve() {
    cur=0;
    if (_x<1) _x=1;
    if (_y<1) _y=1;
    if (_x>a[0].fi) _x=a[0].fi;
    if (_y>a[0].se) _y=a[0].se;
    for (int i=1;i<=n;i++)
        if (dist(a[i],ii(_x,_y))<=m) cur++;
}

int32_t main() {
    FastIO;
    freopen((FILENAME+INP).c_str(),"r",stdin);
    freopen((FILENAME+OUT).c_str(),"w",stdout);
    Read(a[0].fi); Read(a[0].se);
    Read(n); Read(q);
    for (int i=1;i<=n;i++) {
        Read(a[i].fi);
        Read(a[i].se);
    }
    while (q--) {
        Read(m); 
        int cnt=0, x=LLONG_MAX, y=LLONG_MAX;
        for (int i=1;i<=n;i++) {

            _x=a[i].fi; _y=m-a[i].se;
            solve();
            if (cnt<cur || (cnt==cur && (y>_y || (y==_y && x<_x)))) {
                cnt=cur;
                x=_x;
                y=_y;
            }

            _x=a[i].fi; _y=a[i].se-m;
            solve();
            if (cnt<cur || (cnt==cur && (y>_y || (y==_y && x<_x)))) {
                cnt=cur;
                x=_x;
                y=_y;
            }

            _x=m-a[i].fi; _y=a[i].se;
            solve();
            if (cnt<cur || (cnt==cur && (y>_y || (y==_y && x<_x)))) {
                cnt=cur;
                x=_x;
                y=_y;
            }

            _x=a[i].fi-m; _y=a[i].se;
            solve();
            if (cnt<cur || (cnt==cur && (y>_y || (y==_y && x<_x)))) {
                cnt=cur;
                x=_x;
                y=_y;
            }
            
        }
        Write(cnt); putchar('\n');
        Write(x);
        putchar(' ');
        Write(y);
        putchar('\n');
    }
    return 0;
}