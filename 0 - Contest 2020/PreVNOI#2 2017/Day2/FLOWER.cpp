#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
#define int long long
#define x first
#define y second

const string INP=".INP", OUT=".OUT";
const string FILENAME="FLOWER";
const int N=202;

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

typedef pair <int,int> ii;

int n; ii a[N], b[N];
int res=LLONG_MAX;
vector <ii> d;

int dist(const ii &A, const ii &B) {
	return (A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y);
}

int Solve() {
    int cur=INT_MIN;
    for (ii X:d) for (ii Y:d) {
        cur=max(cur,dist(X,Y));
    }
    return cur;
}

int32_t main() {
    FastIO;
    freopen((FILENAME+INP).c_str(),"r",stdin);
    freopen((FILENAME+OUT).c_str(),"w",stdout);
    Read(n);
    for (int i=1;i<=n;i++) {
    	Read(a[i].x);
    	Read(a[i].y);
    }
    sort(a+1,a+1+n);
    int ymax=LLONG_MIN, ymin=LLONG_MAX;
    for (int i=1;i<=n;i++) {
        ymax=max(ymax,a[i].y);
        ymin=min(ymin,a[i].y);
    }
    res=min(dist(ii(0,ymin),ii(0,ymax)),dist(ii(a[1].x,0),ii(a[n].x,0)));
    for (int xl=1;xl<=n;xl++)
    for (int xr=n;xr>=xl;xr--) {
        ymax=LLONG_MIN, ymin=LLONG_MAX;
        for (int i=1;i<xl;i++) {
            ymax=max(ymax,a[i].y);
            ymin=min(ymin,a[i].y);
        }
        for (int i=xr+1;i<=n;i++) {
            ymax=max(ymax,a[i].y);
            ymin=min(ymin,a[i].y);
        }
        if (ymax==LLONG_MIN || ymin==LLONG_MAX) continue;
        d.clear();
        d.push_back(ii(a[xl].x,0));
        d.push_back(ii(a[xr].x,0));
        d.push_back(ii(0,ymax));
        d.push_back(ii(0,ymin));
        res=min(res,Solve());
    }
    
    Write(res);
    return 0;
}