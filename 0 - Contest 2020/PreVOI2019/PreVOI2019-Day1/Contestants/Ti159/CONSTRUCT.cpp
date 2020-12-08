#include <bits/stdc++.h>
#define nmax 100000
#define mmax 100000
using namespace std;
struct node
{
    long long lm,rm,v;
    node(){}
    node(long long a)
    {
        v=lm=rm=a;
    }
    node(long long _v,long long _l,long long _r)
    {
        v=_v;
        lm=_l;
        rm=_r;
    }
    void operator += (long long a){
        v+=a;
        lm+=a;
        rm+=a;
    }
    node operator & (const node &_t) const
    {
        return node(v+_t.v-min(rm,_t.lm),lm,_t.rm);
    }
}smt[nmax*4+10];
int n,m,a[nmax+10],cl,cr,qr[mmax+10][4];
long long lazy[nmax*4+10],cv;
void in()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
      cin>>a[i];
    for(int i=0;i<m;i++){
      cin>>qr[i][0];
      if(qr[i][0]==2) cin>>qr[i][1]>>qr[i][2];
      else cin>>qr[i][1]>>qr[i][2]>>qr[i][3];
    }
}
void build(int id,int l,int r)
{
    if(l==r){
      smt[id]=a[l];
      return;
    }
    build(id<<1,l,(l+r)>>1);
    build(id<<1|1,((l+r)>>1)+1,r);
    smt[id]=smt[id<<1]&smt[id<<1|1];
}
void propg(int id,int no)
{
    if(!no){
      smt[id<<1]+=lazy[id];
      lazy[id<<1]+=lazy[id];
      smt[id<<1|1]+=lazy[id];
      lazy[id<<1|1]+=lazy[id];
    }
    lazy[id]=0;
}
inline int mid(int l,int r)
{
    return (l+r)>>1;
}
void upd(int id,int l,int r)
{
    if(cl<=l&&r<=cr){
      smt[id]+=cv;
      lazy[id]+=cv;
      propg(id,l==r);
      return;
    }
    propg(id,0);
    if(cl<=mid(l,r)) upd(id<<1,l,mid(l,r));
    if(cr>mid(l,r)) upd(id<<1|1,mid(l,r)+1,r);
    smt[id]=smt[id<<1]&smt[id<<1|1];
}
node get(int id,int l,int r)
{
    propg(id,l==r);
    if(cl<=l&&r<=cr) return smt[id];
    node vl,vr;
    int st=0;
    if(cl<=mid(l,r)) {vl=get(id<<1,l,mid(l,r));st+=1;}
    if(cr>mid(l,r)) {vr=get(id<<1|1,mid(l,r)+1,r);st+=2;}
    if(st==1) return vl;
    else if(st==2) return vr;
    else return vl&vr;
}
void quer()
{
    for(int i=1;i<(n<<2)+10;i++)
      lazy[i]=0;
    build(1,1,n);
    for(int i=0;i<m;i++){
      if(qr[i][0]==1) {
          cl=qr[i][1];
          cr=qr[i][2];
          cv=qr[i][3];
          upd(1,1,n);
      }
      else {
        cl=qr[i][1];
        cr=qr[i][2];
        cout<<get(1,1,n).v<<'\n';
      }
    }
}
void st()
{
    srand(time(NULL));
    freopen("Construct.inp","w",stdout);
    int _t=rand()%3+1;
    cout<<_t<<'\n';
    for(int z=0;z<_t;z++){
        int _n=rand()%6+1,_m=rand()%5+1;
        cout<<_n<<' '<<_m<<'\n';
        for(int i=1;i<=_n;i++)
          cout<<rand()%10+1<<' ';
          cout<<'\n';
        for(int i=0;i<_m;i++){
          int p=rand()%2+1;
          int l=rand()%_n+1,r=rand()%_n+1;
          if(l>r) swap(l,r);
          cout<<p<<' '<<l<<' '<<r;
          if(p==1) cout<<' '<<rand()%10+1;
          cout<<'\n';
        }
    }
}
void run()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
      in();
      quer();
    }
}
//#define test
int main()
{
  #ifdef test
  st();
  #else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  #endif // test
    freopen("Construct.inp","r",stdin);
    freopen("Construct.out","w",stdout);
    run();
    return 0;
}
