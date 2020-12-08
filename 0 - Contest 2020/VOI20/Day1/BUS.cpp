#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
#define int long long

const string INP=".INP", OUT=".OUT";
const string FILENAME="BUS";
const int N=50004, INF=9000000000000000000;

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

struct data_ke {
    bool isA;
    int u, w;
};

int n, m, s, t;
vector <data_ke> ke[N];
int d[N];

struct data {
    int MaxA, MaxB, u;
};
bool operator < (const data &A, const data &B) {
    return A.MaxA+A.MaxB>B.MaxA+B.MaxB;
}

int32_t main() {
    FastIO;
    freopen((FILENAME+INP).c_str(),"r",stdin);
    freopen((FILENAME+OUT).c_str(),"w",stdout);
    Read(n); Read(m); Read(s); Read(t);
    for (int i=1;i<=m;i++) {
        int c, u, v, w;
        Read(c); Read(u); Read(v); Read(w);
        ke[u].push_back({c==1,v,w});
        ke[v].push_back({c==1,u,w});
    }
    for (int i=1;i<=n;i++)
        d[i]=INF;
    priority_queue <data> q;
    q.push({0,0,s}); d[s]=0;
    while (!q.empty()) {
        int u=q.top().u;
        int duA=q.top().MaxA, duB=q.top().MaxB;
        q.pop();
        if (duA+duB!=d[u]) continue;
        for (data_ke t:ke[u]) {
            int v=t.u, w=t.w;
            if (t.isA) {
                if (d[v]>max(duA,w)+duB) {
                    d[v]=max(duA,w)+duB;
                    q.push({max(duA,w),duB,v});
                }
            } else {
                if (d[v]>max(duB,w)+duA) {
                    d[v]=max(duB,w)+duA;
                    q.push({duA,max(duB,w),v});
                }
            }
        }
    }
    int res=d[t];
    Write(res);
    return 0;
}
