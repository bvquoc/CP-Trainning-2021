#include <bits/stdc++.h>
#define nmax1 3000
#define mmax1 3000
#define mmax 1000000
#define nmax 1000000
#define candosub3
using namespace std;
struct query
{
    char t;
    int p,k,l,r;
}qr[mmax+10];
string s;
char sv[nmax1+10][mmax1+10];
int n,m,nou,cl,cr;
struct node
{
    int ob,cb;
    node(){}
    node(int _o,int _c)
    {
        ob=_o;
        cb=_c;
    }
    int count()
    {
        return ob+cb;
    }
    node operator | (const node _t) const
    {
        return (ob<_t.cb)?
        node(_t.ob,cb+_t.cb-ob):node(ob-_t.cb+_t.ob,cb);
    }
}smt[nmax*4+10];
int cntc=1;
#ifdef candosub3
    vector<vector<int> > adj,qrs;
    int dad[mmax+10],ans[mmax+10],org[mmax+10];
#endif // candosub3
void in()
{
    cin>>s;
    n=s.size();
    s=" "+s;
    nou=1;
    cin>>m;
    for(int i=0;i<m;i++){
      cin>>qr[i].t;
      if(qr[i].t=='C') {cin>>qr[i].p;cntc++;}
      else if(qr[i].t=='Q') cin>>qr[i].l>>qr[i].r;
      else {
        nou=0;
        cin>>qr[i].k;
        qr[i].k--;
      }
    }
}
void save(int k)
{
    for(int i=1;i<=n;i++)
      sv[k][i]=s[i];
}
int get(int l,int r)
{
    int cntb=0,res=0;
    for(int i=l;i<=r;i++){
      if(s[i]=='(') cntb++;
      else{
        cntb--;
        if(cntb<0){
          cntb=0;
          res++;
        }
      }
    }
    return (res+cntb);
}
void sub1()
{
    for(int i=0;i<m;i++){
      save(i);
      if(qr[i].t=='C'){
        int p=qr[i].p;
        if(s[p]=='(') s[p]=')';
        else s[p]='(';
      }
      else if(qr[i].t=='Q') cout<<get(qr[i].l,qr[i].r)<<'\n';
      else {
        int k=qr[i].k;
        for(int j=1;j<=n;j++)
          s[j]=sv[k][j];
      }
    }
}
inline int mid(int l,int r)
{
    return (l+r)>>1;
}
void build(int id,int l,int r)
{
    if(l==r){
      if(s[l]=='('){
        smt[id].cb=0;
        smt[id].ob=1;
      }
      else{
        smt[id].cb=1;
        smt[id].ob=0;
      }
      return;
    }
    build(id<<1,l,mid(l,r));
    build(id<<1|1,mid(l,r)+1,r);
    smt[id]=smt[id<<1] | smt[id<<1|1];
}
void upd(int p)
{
    int id,l,r;
    for(id=1,l=1,r=n;l<r;){
      if(p>mid(l,r)){
        id=id<<1|1;
        l=mid(l,r)+1;
      }
      else{
        id<<=1;
        r=mid(l,r);
      }
    }
    swap(smt[id].cb,smt[id].ob);
    for(id>>=1;id>0;id>>=1)
      smt[id]=smt[id<<1] | smt[id<<1|1];
}
node get(int id,int l,int r)
{
    if(cl<=l&&r<=cr) return smt[id];
    node vl,vr;
    int st=0;
    if(cr>mid(l,r)) { vr=get(id<<1|1,mid(l,r)+1,r); st+=1; }
    if(cl<=mid(l,r)) { vl=get(id<<1,l,mid(l,r)); st+=2; }
    if(st==1) return vr;
    else if(st==2) return vl;
    else return (vl | vr);
}
void sub2()
{
    build(1,1,n);
    for(int i=0;i<m;i++){
      if(qr[i].t=='C')
        upd(qr[i].p);
      else{
        cl=qr[i].l;
        cr=qr[i].r;
        node g=get(1,1,n);
        cout<<g.ob+g.cb<<'\n';
      }
    }
}
#ifdef candosub3
void buildgraph()
{
    int cn=0;
    int cnt=0;
    for(int i=0;i<m;i++){
      org[i]=cn;
      if(qr[i].t=='C'){
        cnt++;
        adj[cn].push_back(cnt);
        dad[cnt]=qr[i].p;
        cn=cnt;
      }
      else if(qr[i].t=='Q')
        qrs[cn].push_back(i);
      else cn=org[qr[i].k];
    }
}
void dfs(int u)
{
    if(u!=0) upd(dad[u]);
    for(int i=0;i<qrs[u].size();i++){
      cl=qr[qrs[u][i]].l;
      cr=qr[qrs[u][i]].r;
      node g=get(1,1,n);
      ans[qrs[u][i]]=g.ob+g.cb;
    }
    for(int i=0;i<adj[u].size();i++)
      dfs(adj[u][i]);
    if(u!=0) upd(dad[u]);
}
void sub3()
{
    adj.resize(cntc);
    qrs.resize(cntc);
    buildgraph();
    build(1,1,n);
    dfs(0);
    for(int i=0;i<m;i++)
      if(qr[i].t=='Q') cout<<ans[i]<<'\n';
}
#endif // candosub3
void run()
{
    in();
    if(n<=1000&&m<=1000) sub1(); else
    if(nou==1) sub2();
#ifdef candosub3
    else
      sub3();
#endif // candosub3
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("FIXSTR.inp","r",stdin);
    freopen("FIXSTR.out","w",stdout);
    run();
    return 0;
}
