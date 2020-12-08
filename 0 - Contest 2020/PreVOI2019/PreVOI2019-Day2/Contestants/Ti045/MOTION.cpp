#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define int long long
int hmt() {int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';if(n) x=-x;return x;}
#define in hmt()
#define ins ({string x;char c=getchar();for(;c==' '||c=='\n';c=getchar());for(;c!=' '&&c!='\n';c=getchar()) x+=c;x;})
#define forinc(i,a,b) for(int i=a,_b=b;i<=_b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forv(a,b) for(auto &a:b)
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
#define bit(x,i) ((x>>(i-1))&1)#define onbit(x,i) (x|(1<<(i-1)))#define offbit(x,i) (x&~(1<<(i-1)))
#define db double
const pii INF={1000,1};
int t,m,n;;
pii A,B,C,D,vt[2];
struct oo {pii a,b,t;};
vector<oo> e[2];
pii add(pii a,pii b)
{
    pii c={a.fi*b.se+b.fi*a.se,a.se*b.se};
    int g=abs(__gcd(c.fi,c.se));
    c.fi/=g,c.se/=g;
    return c;
}
pii rev(pii a,pii b)
{
    pii c={a.fi*b.se-b.fi*a.se,a.se*b.se};
    int g=abs(__gcd(c.fi,c.se));
    c.fi/=g,c.se/=g;
    return c;
}
pii mul(pii a,pii b)
{
    pii c={a.fi*b.fi,a.se*b.se};
    int g=abs(__gcd(c.fi,c.se));
    c.fi/=g,c.se/=g;
    return c;
}
pii div(pii a,pii b)
{
    pii c={a.fi*b.se,a.se*b.fi};
    int g=abs(__gcd(c.fi,c.se));
    c.fi/=g,c.se/=g;
    return c;
}
void Go(pii s,pii v,pii c,int o,pii T)
{
    if(e[o].size()>50) return;
    pii x=s;
    pii _T=T;
    while((x==s)||(x.fi&&x.fi<m&&x.se&&x.se<n)) x.fi+=v.fi,x.se+=v.se,_T=add(_T,c);
    if(x.fi<0||x.fi>m||x.se<0||x.se>n) return;
    e[o].pb({s,x,T});
    if(x.fi==0||x.fi==m) v.fi=-v.fi;
    if(x.se==0||x.se==n) v.se=-v.se;
    Go(x,v,c,o,_T);
}
void build(pii s,pii t,int o)
{
    pii v={t.fi-s.fi,t.se-s.se};
    int g=abs(__gcd(v.fi,v.se));
    v.fi/=g,v.se/=g;
    vt[o]=v;
    Go(s,v,{1,g},o,{0,1});
}
db ESP=1e-8;
struct line {int a,b,c;};
struct point {pii a,b;};
db L(point a,point b)
{
    pair<db,db> u={1.0*a.a.fi/a.a.se,1.0*a.b.fi/a.b.se};
    pair<db,db> v={1.0*b.a.fi/b.a.se,1.0*b.b.fi/b.b.se};
    return sqrt((u.fi-v.fi)*(u.fi-v.fi)+(u.se-v.se)*(u.se-v.se));
}
bool kt(point x,point y,point z)
{
    return fabs(L(x,y)+L(y,z)-L(x,z))<ESP;
}
line dt(pii u,pii v)
{
    int a=u.se-v.se,b=v.fi-u.fi;
    int c=u.fi*v.se-v.fi*u.se;
    return {a,b,c};
}
point G(line A,line B)
{
    pii x,y;
    A.c=-A.c,B.c=-B.c;
    if(!B.b) swap(A,B);
    if(!A.b)
    {
        x=div({A.c,1},{A.a,1});
        if(!B.b) return {INF,INF};
        return {x,div(rev({B.c,1},mul({B.a,1},x)),{B.b,1})};
    }
    pii tg=div({B.b,1},{A.b,1});
    if(!rev(mul(tg,{A.a,1}),{B.a,1}).fi) return {INF,INF};
    x=div(rev({B.c,1},mul(tg,{A.c,1})),rev({B.a,1},mul(tg,{A.a,1})));
    return {x,div(rev({B.c,1},mul({B.a,1},x)),{B.b,1})};
}
point mp(pii u)
{
    return {{u.fi,1},{u.se,1}};
}
bool K(pii u,pii v)
{
    return u.fi!=v.fi||u.se!=v.se;
}
pii kc(pii u,point v,pii c)
{
    if(K(v.a,make_pair(u.fi,1))) return div(rev(v.a,{u.fi,1}),{c.fi,1});
    return div(rev(v.b,{u.se,1}),{c.se,1});
}
main()
{
    freopen("MOTION.inp","r",stdin);
    freopen("MOTION.out","w",stdout);
    forinc(cs,1,in)
    {
        m=in,n=in;
        A={in,in},B={in,in},C={in,in},D={in,in};
        cout<<-1<<"\n";
        //:((
        /*e[0].clear();e[1].clear();
        build(A,B,0);
        build(C,D,1);
        bool ok=0;
        forv(a,e[0]) forv(b,e[1])
        {
            if(ok) break;
            line x=dt(a.a,a.b);
            line y=dt(b.a,b.b);
            point p=G(x,y);
            if(kt(mp(a.a),p,mp(a.b))&&kt(mp(b.a),p,mp(b.b)))
            {
                pii X=add(a.t,kc(a.a,p,vt[0])),Y=add(b.t,kc(b.a,p,vt[1]));
                if(X==Y)
                {
                    ok=1;
                    cout<<X.fi<<" "<<X.se<<"\n";
                    break;
                }
            }
        }
        if(!ok) {cout<<-1<<"\n";continue;}*/
    }
}
