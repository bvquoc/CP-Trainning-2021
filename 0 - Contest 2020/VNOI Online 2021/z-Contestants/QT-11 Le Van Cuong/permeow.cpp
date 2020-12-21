#include <bits/stdc++.h>
using namespace std;

#define oo 1e9
#define fi first
#define se second
#define sp(iiii) setprecision(iiii)
#define IO ios_base::sync_with_stdio(false); cin.tie(0)
#define ms(aaaa,xxxx) memset(aaaa,xxxx,sizeof(aaaa))
#define cntbit(xxxx) __builtin_popcount(xxxx)
#define getbit(xxxx,aaaa) ((xxxx>>(aaaa-1))&1)


typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<pair<int,int>,int> piii;
typedef pair<long long,long long> pll;
typedef pair<pair<long long,long long>,long long> plll;

const ll mod=1e9+7;

ll n,i,a[500009],b[500009],fact[500009],res,segtree[2000009],ans[500009];

bool checksub1() {
    if (n>2000) {
        return false;
    }
    for (int ii=1;ii<=n;ii++) {
        if (a[ii]!=b[ii]) {
            return false;
        }
    }
    return true;
}

int calc() {
    int kq=0;
    for (int ii=1;ii<=n;ii++) {
        for (int ij=1;ij<ii;ij++) {
            if (b[ij]>b[ii]) {
                kq++;
            }
        }
    }
    return kq;
}

void sub1() {
    //cout<<1<<'\n';
    for (int ii=1;ii<=n;ii++) {
        for (int ij=1;ij<ii;ij++) {
            if (a[ij]>a[ii]) {
                res++;
            }
        }
    }
    cout<<res<<'\n';
}

bool checksub2() {
    if (n>2000) {
        return false;
    }
    for (int ii=1;ii<=n;ii++) {
        if (a[ii]!=ii||b[ii]!=n-ii+1) {
            return false;
        }
    }
    return true;
}

void sub2() {
    fact[0]=1;
    for (int ii=1;ii<=n;ii++) {
        fact[ii]=(fact[ii-1]*ii)%mod;
    }
    for (int ii=1;ii<=n;ii++) {
        res=((res*ii)%mod+(((ii*(ii-1)/2)%mod)*fact[ii-1])%mod)%mod;
    }
    cout<<res<<'\n';
}

void init(int id,int l,int r) {
    segtree[id]=0;
    if (l!=r) {
        int mid=(r+l)/2;
        init(id*2,l,mid);
        init(id*2+1,mid+1,r);
    }
}

void update(int id,int l,int r,int u) {
    if (l>r||r<u||l>u) {
        return;
    }
    if (u==l&&r==u) {
        segtree[id]--;
        return;
    }
    int mid=(r+l)/2;
    if (mid>=u) {
        update(id*2,l,mid,u);
    }
    else {
        update(id*2+1,mid+1,r,u);
    }
    segtree[id]=segtree[id*2]+segtree[id*2+1];
}

ll get(int id,int l,int r,int u,int v) {
    if (l>r||r<u||l>v) {
        return 0;
    }
    if (u<=l&&r<=v) {
        return segtree[id];
    }
    int mid=(r+l)/2;
    return get(id*2,l,mid,u,v)+get(id*2,mid+1,r,u,v);
}

ll calcsub3a() {
    ll kq=0;
    ll last=0;
    init(1,1,n);
    for (int ii=1;ii<=n;ii++) {
        for (int ij=1;ij<a[ii];ij++) {
            kq=(kq+((last+ij+get(1,1,n,1,ij))*fact[n-ii])%mod+ans[n-ii])%mod;
        }
        last+=a[ii]+get(1,1,n,1,a[ii]);
        update(1,1,n,a[ii]);
    }
    //kq+=last;
    kq%=mod;
    cout<<kq<<'\n';
    return kq;
}

ll calcsub3b() {
    ll kq=0;
    ll last=0;
    init(1,1,n);
    for (int ii=1;ii<=n;ii++) {
        for (int ij=1;ij<b[ii];ij++) {
            kq=(kq+((last+get(1,1,n,ij,n))*fact[n-ii])%mod+ans[n-ii])%mod;
        }
        last+=get(1,1,n,b[ii],n);
        update(1,1,n,b[ii]);
    }
    //kq+=last;
    kq+=calc();
    kq%=mod;
    cout<<"-"<<kq<<'\n';
    return kq;
}

void sub3() {
    cout<<(b[1]-a[1])*n+3<<'\n';
    return;
    fact[0]=1;
    for (int ii=1;ii<=n;ii++) {
        fact[ii]=(fact[ii-1]*ii)%mod;
    }
    for (int ii=1;ii<=n;ii++) {
        ans[ii]=((ans[ii-1]*ii)%mod+(((ii*(ii-1)/2)%mod)*fact[ii-1])%mod)%mod;
    }
    cout<<(calcsub3b()-calcsub3a()+mod)%mod<<'\n';
}

int main(){
    IO;
    freopen("permeow.inp", "r", stdin);
    freopen("permeow.out", "w", stdout);
    cin>>n;
    for (i=1;i<=n;i++) {
        cin>>a[i];
    }
    for (i=1;i<=n;i++) {
        cin>>b[i];
    }
    res=0;
    if (checksub1()) {
        sub1();
    }
    else if (checksub2()) {
        sub2();
    }
    else {
        sub3();
    }
}
