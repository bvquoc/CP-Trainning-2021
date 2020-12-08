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
struct BIT {
    int n; vector <int> fen1, fen2;
    void resize(int sz) {
        n=sz;
        fen1.assign(sz+1,0);
        fen2.assign(sz+1,0);
    }
    void update(int p, int val1, int val2) { // a1[p]+=val1; a2[p]+=val2;
        for(int i=p;i<=n;i+=i&-i) {
            fen1[i]+=val1;
            fen2[i]+=val2;
        }
    }
    int sum1(int p) { // sum of a1[1..p];
        int ans=0;
        for(int i=p;i;i-=i&-i) ans+=fen1[i];
        return ans;
    }
    int sum2(int p) { // sum of a2[1..p];
        int ans=0;
        for(int i=p;i;i-=i&-i) ans+=fen2[i];
        return ans;
    }
    int sumsegment2(int l, int r) { // sum of a2[l..r];
        int ans=0;
        while (l<=r)
            if (r-(r&-r)>=l) {
                ans+=fen2[r];
                r=r-(r&-r);
            } else {
                ans+=max(0LL,a[r]);
                r--;
            }
        return ans;
    }
} tree;
void Update(int i, int val) {
    // int ai=tree.sum2(i)-tree.sum2(i-1);
    int ai=tree.sumsegment2(i,i);
    int val2;
    if (a[i]+val>=0) val2=a[i]+val-ai;
    else val2=-ai;
    tree.update(i,val,val2);
    a[i]+=val;
}
// BruteForce: Ans(l,r)=a[l]+sum(max(0,a[i]-a[i-1])) (l<i<=r)
int32_t main() {
    FastIO;
    freopen("CONSTRUCT.INP","r",stdin);
    freopen("CONSTRUCT.OUT","w",stdout);
    int nTests; Read(nTests);
    while (nTests--) {
        Read(n); Read(m);
        tree.resize(n);
        for (int i=0;i<=n+1;i++) a[i]=0;
        for (int i=1;i<=n;i++) {
            int x; Read(x);
            Update(i,x);
            Update(i+1,-x);
        }
        while (m--) {
            int type; Read(type);
            if (type==1) {
                int l, r, val;
                Read(l); Read(r); Read(val);
                if (l>r) swap(l,r);
                Update(l,val);
                Update(r+1,-val);
            } else {
                int l, r;
                Read(l); Read(r);
                if (l>r) swap(l,r);
                int res=tree.sum1(l);
                // res+=tree.sum2(r)-tree.sum2(l);
                res+=tree.sumsegment2(l+1,r);
                Write(res); putchar('\n');
            }
        }
    }
    return 0;
}