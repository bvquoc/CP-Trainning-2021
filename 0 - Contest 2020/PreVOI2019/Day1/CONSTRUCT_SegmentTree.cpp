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

const int N=1000005;
#define int long long
int n, m, a[N];
struct SegmentTree {
    vector <int> st1, st2;
    SegmentTree() { st1.clear(); st2.clear(); }
    SegmentTree(int n) {
        st1.assign(4*n,0);
        st2.assign(4*n,0);
    }
    void assign(int n) {
        st1.assign(4*n,0);
        st2.assign(4*n,0);
    }
    void update(int id, int l, int r, int i, int v1, int v2) {
        if (i<l || r<i) return;
        if (l==r) {
            st1[id]+=v1;
            st2[id]=max(0LL,v2);
            return;
        }
        int mid=(l+r)>>1, id1=id<<1, id2=id1+1;
        update(id1,l,mid,i,v1,v2);
        update(id2,mid+1,r,i,v1,v2);
        st1[id]=st1[id1]+st1[id2];
        st2[id]=st2[id1]+st2[id2];
    }
    int getsum1(int id, int l, int r, int u, int v) {
        if (v<l || r<u) return 0;
        if (u<=l && r<=v) return st1[id];
        int mid=(l+r)>>1, id1=id<<1, id2=id1+1;
        return getsum1(id1,l,mid,u,v)+getsum1(id2,mid+1,r,u,v);
    }
    int getsum2(int id, int l, int r, int u, int v) {
        if (v<l || r<u) return 0;
        if (u<=l && r<=v) return st2[id];
        int mid=(l+r)>>1, id1=id<<1, id2=id1+1;
        return getsum2(id1,l,mid,u,v)+getsum2(id2,mid+1,r,u,v);
    }
    int GetAns(int l, int r) {
        int ans=getsum1(1,1,n,1,l);
        ans+=getsum2(1,1,n,l+1,r);
        return ans;
    }
} ST;
// BruteForce: Ans(l,r)=a[l]+sum(max(0,a[i]-a[i-1])) (l<i<=r)
int32_t main() {
    FastIO;
    freopen("CONSTRUCT.INP","r",stdin);
    freopen("CONSTRUCT.OUT","w",stdout);
    int nTests; Read(nTests);
    while (nTests--) {
        Read(n); Read(m);
        ST.assign(n);
        for (int i=0;i<=n+1;i++) a[i]=0;
        for (int i=1;i<=n;i++) {
            int x; Read(x);
            a[i]+=x; a[i+1]-=x;
            ST.update(1,1,n,i,x,a[i]);
            ST.update(1,1,n,i+1,-x,a[i+1]);
        }
        while (m--) {
            int type; Read(type);
            if (type==1) {
                int l, r, val;
                Read(l); Read(r); Read(val);
                if (l>r) swap(l,r);
                a[l]+=val; a[r+1]-=val;
                ST.update(1,1,n,l,val,a[l]);
                ST.update(1,1,n,r+1,-val,a[r+1]);
            } else {
                int l, r;
                Read(l); Read(r);
                if (l>r) swap(l,r);
                int res=ST.GetAns(l,r);
                Write(res); putchar('\n');
            }
        }
    }
    return 0;
}