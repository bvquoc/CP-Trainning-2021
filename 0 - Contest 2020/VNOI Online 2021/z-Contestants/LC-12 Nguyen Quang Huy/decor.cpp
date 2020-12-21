#include <bits/stdc++.h>
#define x first
#define y second
#define ll long long
#define mod 1000000007
#define pii pair <int ,int>
#define reset(x) memset(x, 0,sizeof(x))
#define PB push_back
#define mp make_pair
#define maxn 500005
#define task "decor"

using namespace std;

int n,m,k,pos[maxn],ans,anl,anr,st[4*maxn];
string s;

void upd(int i,int l,int r,int vt,int val) {
    if(vt>r||vt<l)
        return ;
    if(l==r) {
        st[i]=val;
        return ;
    }
    int m=(l+r)/2;
    upd(2*i,l,m,vt,val);
    upd(2*i+1,m+1,r,vt,val);
    st[i]=st[2*i]+st[2*i+1];
}

int get(int i,int l,int r,int k) {
    if(l==r)
        return l;
    int m=(l+r)/2;
    if(st[2*i]<k)
        return get(2*i+1,m+1,r,k-st[2*i]);
    return get(2*i,l,m,k);
}

void sub1() {
    pos[0]=1e9;
    for(int i=1; i<=n; i++)
        if(s[i]=='1') {
            pos[i]=min(pos[i-1],i);
            if(i-pos[i]+1>ans) {
                ans=i-pos[i]+1;
                anl=pos[i];
                anr=i;
            }
        } else
            pos[i]=1e9;
    cout<<anl<<" "<<anr;
}

void sub2() {
    for(int i=1; i<=n; i++)
        if(s[i]=='0')
            upd(1,1,n,i,1);
    for(int i=1; i<=n; i++) {
        int vt=get(1,1,n,k+1);
        if(st[1]<=k)
            vt=n+1;
        if(vt-i>ans) {
            ans=vt-i;
            anl=i,anr=vt-1;
        }
        if(s[i]=='0')
            upd(1,1,n,i,0);
    }
    cout<<anl<<" "<<anr;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n>>m>>k;
    cin>>s;
    s='2'+s;
    if(m==0) {
        if(k==0)
            sub1();
        else
            sub2();
        return 0;
    }
    sub2();
}
