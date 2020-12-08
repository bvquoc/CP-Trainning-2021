#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
#define int long long

const string INP=".INP", OUT=".OUT";
const string FILENAME="STARS";
const int N=102;

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

struct TVector {
    int x, y;
    inline TVector operator -(const TVector& other) const {
        return {x - other.x, y - other.y};
    }
    inline int operator *(const TVector& other) const {
        return x * other.y - y * other.x;
    }
};
using TPoint=TVector;

inline int SqrLen(const TVector& u) {
    return u.x * u.x + u.y * u.y;
}

int q, d, n;
TVector p[N], A;
int res=0;

void FindA() {
    TPoint* ptr = min_element(p, p + n, [](const TPoint& p, const TPoint& q) {
        return p.y < q.y || (p.y == q.y && p.x < q.x);
    });
    A = *ptr;
    swap(*ptr, p[0]);
}

int GetArea() {
    int ans=0;
    p[n]=p[0];
    for (int i=0;i<n;i++)
        ans+=p[i]*p[i+1];
    return abs(ans/2);
}

int32_t main() {
    FastIO;
    freopen((FILENAME+INP).c_str(),"r",stdin);
    freopen((FILENAME+OUT).c_str(),"w",stdout);
    Read(q); Read(d);
    while (q--) {
        Read(n); Read(d);
        for (int i=0;i<n;i++) {
            Read(p[i].x);
            Read(p[i].y);
        }
        FindA();
        sort(p+1,p+n, [](const TPoint& B, const TPoint& C) {
            TVector u = B - A, v = C - A;
            int temp = u * v;
            return temp > 0 || temp == 0 && SqrLen(u) < SqrLen(v);
        });
        res+=GetArea();
    }
    Write(res);
    return 0;
}
