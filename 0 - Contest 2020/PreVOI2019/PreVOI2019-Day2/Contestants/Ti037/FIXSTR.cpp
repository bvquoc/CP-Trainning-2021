#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fio(s) freopen(s".inp","r",stdin)
#define foo(s) freopen(s".out","w",stdout)
#define pb push_back
#define task "fixstr"
using namespace std;
const int N=1000009;
int n,m;
string s,data[N];
struct node{
    int L,R;
};
node T[N*4];
void Sub1()
{
    char t;
    int l,r,p;
    For(z,1,m)
    {
        data[z]=s;
        for(t=getchar();t!='Q'&&t!='C'&&t!='U';t=getchar());
        if(t=='C'){
            scanf("%d",&p); if(s[p]=='(') s[p]=')'; else s[p]='(';
        }else
        if(t=='U'){
            scanf("%d",&p); s=data[p];
        }else{
            scanf("%d%d",&l,&r);
            int rs=0,cnt=0;
            For(i,l,r){
                if(s[i]==')') --cnt;
                else ++cnt;
                if(cnt<0) ++rs,cnt=0;
            }
            rs+=cnt;
            printf("%d\n",rs);
        }
    }
}
node join(node u,node v)
{
    node c=(node){0,0};
    if(u.R==0){
        c.L=u.L+v.L; c.R=v.R;
    }else
    if(v.L==0){
        c.R=u.R+v.R; c.L=u.L;
    }else{
        c.L=u.L; c.R=v.R;
        if(u.R>v.L) c.R+=(u.R-v.L);
        if(u.R<v.L) c.L+=(v.L-u.R);
    }
    return c;
}
void upd(int id,int l,int r,int i)
{
    if(l>i||r<i) return;
    if(l==r){
            T[id].L=T[id].R=0;
            if(s[i]=='(') T[id].R=1;
            else T[id].L=1;
            return;
    }
    upd(id*2,l,(l+r)/2,i);
    upd(id*2+1,(l+r)/2+1,r,i);
    T[id]=join(T[id*2],T[id*2+1]);
}
node get(int id,int l,int r,int u,int v)
{
    if(l>v||r<u) return (node) {0,0};
    if(l>=u&&r<=v) return T[id];
    return join( get(id*2,l,(l+r)/2,u,v) , get(id*2+1,(l+r)/2+1,r,u,v) );
}
void Sub2()
{
    int p,l,r;
    char t;
    For(i,1,n)
        upd(1,1,n,i);
    while(m--)
    {
        for(t=getchar();t!='Q'&&t!='C'&&t!='U';t=getchar());
        if(t=='C'){
            scanf("%d",&p);
            if(s[p]=='(') s[p]=')';
            else s[p]='(';
            upd(1,1,n,p);
        }else{
            scanf("%d%d",&l,&r);
            node tmp=get(1,1,n,l,r);
            printf("%d\n",tmp.L+tmp.R);
        }
    }
}
int main()
{
    fio(task); foo(task);
   // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   char c;
    for(c=getchar();c!='('&&c!=')';c=getchar());
    s.pb(c); for(c=getchar();c=='('||c==')'; c=getchar()) s.pb(c);
    n=s.size(); s='#'+s;
    scanf("%d",&m);
    if(m<=1000)
            Sub1();
    else
            Sub2();
    return 0;
}
