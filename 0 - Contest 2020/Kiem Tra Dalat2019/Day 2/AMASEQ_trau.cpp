#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

const string INP=".INP", OUT=".ANS";
const string FILENAME="AMASEQ";
const int N=1000006;

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

struct SegmentTree{
    int n;
    vector <int> st_mi, st_ma;
    SegmentTree() {}
    SegmentTree(int sz) {
        n=sz;
        st_mi.resize((4*(n+5)));
        st_ma.resize((4*(n+5)));
    }
    void assign(int sz) {
        n=sz;
        st_mi.resize((4*(n+5)));
        st_ma.resize((4*(n+5)));
    }
    void update(int id, int l, int r, int i, int v) {
        if (i<l || r<i) return;
        if (l==r) {
            st_mi[id]=v;
            st_ma[id]=v;
            return;
        }
        int mid=(l+r)>>1, id1=id<<1, id2=id1+1;
        update(id1,l,mid,i,v);
        update(id2,mid+1,r,i,v);
        st_mi[id]=min(st_mi[id1],st_mi[id2]);
        st_ma[id]=max(st_ma[id1],st_ma[id2]);
    }
    int getmax(int id, int l, int r, int u, int v) {
        if (v<l || r<u) return INT_MIN;
        if (u<=l && r<=v) return st_ma[id];
        int mid=(l+r)>>1, id1=id<<1, id2=id1+1;
        return max(getmax(id1,l,mid,u,v), getmax(id2, mid+1, r, u, v));
    }
    int getmin(int id, int l, int r, int u, int v) {
        if (v<l || r<u) return INT_MAX;
        if (u<=l && r<=v) return st_mi[id];
        int mid=(l+r)>>1, id1=id<<1, id2=id1+1;
        return min(getmin(id1,l,mid,u,v), getmin(id2, mid+1, r, u, v));
    }
} ST;

int n, T, a[N];
int res=1;

int32_t main() {
    FastIO;
    freopen((FILENAME+INP).c_str(),"r",stdin);
    freopen((FILENAME+OUT).c_str(),"w",stdout);
    Read(n); Read(T);
    ST.assign(n);
    for (int i=1;i<=n;i++) {
        Read(a[i]);
        ST.update(1,1,n,i,a[i]);
    }

    for (int l=1;l<=n;l++)
        for (int r=l;r<=n;r++) {
            int Min=ST.getmin(1,1,n,l,r);
            int Max=ST.getmax(1,1,n,l,r);
            if (Max-Min<=T) {
                res=max(res,r-l+1);
            }
        }
    
    Write(res);
    return 0;
}