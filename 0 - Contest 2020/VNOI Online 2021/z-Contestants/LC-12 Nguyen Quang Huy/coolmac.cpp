#include <bits/stdc++.h>
#define x first
#define y second
#define ll long long
#define mod 1000000007
#define pii pair <int ,int>
#define reset(x) memset(x, 0,sizeof(x))
#define PB push_back
#define mp make_pair
#define maxn 100005
#define task "coolmac"

using namespace std;

int n,m,t[maxn],s[maxn],st[4*maxn],pos[4*maxn];
pii a[maxn];

void upd(int i,int l,int r,int vt,int val) {
    if(vt>r||vt<l)
        return ;
    if(l==r) {
        st[i]=max(st[i],val);
        pos[i]=l;
        return ;
    }
    int m=(l+r)/2;
    upd(2*i,l,m,vt,val);
    upd(2*i+1,m+1,r,vt,val);
    if(st[2*i]>=st[2*i+1])
        st[i]=st[2*i],pos[i]=pos[2*i];
    else
        st[i]=st[2*i+1],pos[i]=pos[2*i+1];
}

pii get(int i,int l,int r,int u,int v) {
    if(u>r||v<l)
        return mp(0,0);
    if(u<=l&&r<=v)
        return mp(st[i],pos[i]);
    int m=(l+r)/2;
    pii x=get(2*i,l,m,u,v);
    pii y=get(2*i+1,m+1,r,u,v);
    if(x.x>=y.x)
        return x;
    else
        return y;
}

void sub1() {
    int res=m+1;
    for(int i=1; i<(1<<m); i++) {
        int cnt=__builtin_popcount(i);
        vector <pii> xl;
        for(int j=0; j<m; j++)
            if(((i>>j)&1)==1)
                xl.PB(a[j+1]);
        int l=xl[0].x,r=xl[0].y,flag=1;
        for(int i=1; i<cnt; i++)
            if(xl[i].x>r) {
                flag=0;
                break;
            } else {
                l=min(l,xl[i].x);
                r=max(r,xl[i].y);
            }
        if(flag==0||l>t[1]||r<100000)
            continue;
        res=min(res,cnt);
    }
    if(res==m+1)
        cout<<-1;
    else
        cout<<res;
}

void sub() {
    for(int i=1; i<=m; i++)
        a[i].x=max(a[i].x,t[1]);
    for(int i=1; i<=m; i++)
        if(a[i].y>=t[1])
            upd(1,1,100000,a[i].x,a[i].y);
    int cnt=1,s=t[1],e=get(1,1,100000,t[1],t[1]).x;
    while(e<100000) {
        pii vt=get(1,1,100000,t[1],e);
        s=vt.y,e=vt.x;
        cnt++;
    }
    cout<<cnt;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>m;
    for(int i=1; i<=m; i++) {
        cin>>a[i].x>>a[i].y;
        s[a[i].x]++;
        s[a[i].y+1]--;
    }
    sort(a+1,a+1+m);
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>t[i];
    sort(t+1,t+1+n);
    for(int i=1; i<=100000; i++)
        s[i]+=s[i-1];
    for(int i=t[1]; i<=100000; i++)
        if(s[i]==0) {
            cout<<-1;
            return 0;
        }
    if(m<=16) {
        sub();
        return 0;
    } else {
        sub();
        return 0;
    }
}
