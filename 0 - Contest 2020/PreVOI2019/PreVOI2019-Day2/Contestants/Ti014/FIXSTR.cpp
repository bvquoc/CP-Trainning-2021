#include <bits/stdc++.h>
using namespace std;
#define in ({int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';n?-x:x;})
void out(int x){
    if(x>9) out(x/10);
    putchar(x%10+'0');
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r){return l+rng()%(r-l+1);}
#define fasty ios_base::sync_with_stdio(false),cin.tie(nullptr);
#define task "FIXSTR"
#define forinc(a,b,c) for(int a=b,_c=c;a<=_c;++a)
#define fordec(a,b,c) for(int a=b,_c=c;a>=_c;--a)
#define forv(a,b) for(auto&a:b)
#define fi first
#define se second
#define pb push_back
#define ii pair<int,int>
#define mt make_tuple
#define all(a) a.begin(),a.end()
#define reset(f, x) memset(f, x, sizeof(f))
#define bit(x,i) ((x>>(i-1))&1)
#define on(x,i) (x|(1ll<<(i-1)))
#define off(x,i) (x&~(1<<(i-1)))

const int N=1000010;

int n,m;
int sum[N],mask[N],dd[N],ans[N];
int T[N*4],B[N*4];
struct pack{
    int v,i,x;
};
vector<pack> ad[N],qry[N];

inline void push(int s){
    if(!B[s]) return;
    T[2*s]+=B[s];  T[2*s+1]+=B[s];
    B[2*s]+=B[s];  B[2*s+1]+=B[s];
    B[s]=0;
}

inline void upd(int s,int l,int r,int u,int v,int x){
    if(l>v||u>r) return;
    if(u<=l&&r<=v){
        T[s]+=x;
        B[s]+=x;
        return;
    }
    push(s);
    int m=(l+r)/2;
    upd(2*s,l,m,u,v,x); upd(2*s+1,m+1,r,u,v,x);
    T[s]=min(T[2*s],T[2*s+1]);
}

inline int que(int s,int l,int r,int u,int v){
    if(l>v||u>r) return n;
    if(u<=l&&r<=v) return T[s];
    push(s);
    int m=(l+r)/2;
    return min(que(2*s,l,m,u,v),que(2*s+1,m+1,r,u,v));
}

inline void build(int s,int l,int r){
    if(l==r){
        T[s]=sum[l];
        return;
    }
    int m=(l+r)/2;
    build(2*s,l,m); build(2*s+1,m+1,r);
    T[s]=min(T[2*s],T[2*s+1]);
}

inline void dfs(int u){
    if(dd[u]) return;
    dd[u]=1;
    forv(i,qry[u]){
        int l=i.v,r=i.i,j=i.x;
        int mx=que(1,1,n,l,r);
        int tot=que(1,1,n,r,r);
        int pr=l>1?que(1,1,n,l-1,l-1):0;
        mx-=pr, tot-=pr;
        ans[j]=mx>=0?tot:-mx+tot-mx;
    }
    forv(i,ad[u]){
        int sign=que(1,1,n,i.i,i.i);
        if(i.i>1) sign-=que(1,1,n,i.i-1,i.i-1);
        upd(1,1,n,i.i,n,-sign*2);
        dfs(i.v);
        upd(1,1,n,i.i,n,sign*2);
    }
}

main(){
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    string s; cin>>s>>m; n=s.size(); s=" "+s;
    forinc(i,1,n) sum[i]=sum[i-1]+(s[i]=='('?1:-1);
    int fo=1,to,it=1;
    forinc(i,1,m){
        mask[i]=fo;
        char ch; while(!isupper(ch=getchar()));
        if(ch=='C'){
            int j=in;
            to=++it;
            ad[fo].pb({to,j});
            fo=to;
        }
        if(ch=='Q'){
            int l=in,r=in;
            qry[fo].pb({l,r,i});
        }
        if(ch=='U'){
            int j=in;
            fo=mask[j];
        }
    }
    build(1,1,n);
    reset(ans,-1);
    dfs(1);
    forinc(i,1,m) if(ans[i]>-1) out(ans[i]),putchar('\n');
}

