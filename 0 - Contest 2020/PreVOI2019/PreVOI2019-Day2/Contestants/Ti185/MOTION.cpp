///Bankai: Getsuga Tenshou
#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
using namespace std;
const ll Eps=1e-14;
ll kq,n,m,t,minx=1e9,maxx=0;
struct diem
{
	double x,y;
}a,b,c,d;
struct duong
{
	diem p1,p2;
};
void laydiem(diem p1, diem p2, double &a, double &b, double &c)
{
    a=p2.y-p1.y;
    b=p1.x-p2.x;
    c=-p1.x*(p2.y-p1.y)+p1.y*(p2.x-p1.x);
}
bool ktra(duong l1, duong l2)
{
	double a1,b1,c1,a2,b2,c2,t1,t2;
    laydiem(l1.p1,l1.p2,a1,b1,c1);
    laydiem(l2.p1,l2.p2,a2,b2,c2);
    t1=(l1.p1.x*a2+l1.p1.y*b2+c2)*(l1.p2.x*a2+l1.p2.y*b2+c2);
    t2=(l2.p1.x*a1+l2.p1.y*b1+c1)*(l2.p2.x*a1+l2.p2.y*b1+c1);
    return (t1<Eps) && (t2<Eps);
}
double kc(diem p1, diem p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
void xuli()
{
    duong ab,cd;
    ab.p1=a;ab.p2=b;cd.p1=c;cd.p2=d;
    if(ktra(ab,cd)==true) kq=-1;
    else
    {
        diem diemmax,diemmin;
        minx=min(a.x,min(b.x,min(c.x,d.x)));
        maxx=max(a.x,max(b.x,max(c.x,d.x)));
        if(a.x==minx) diemmin=a;
        if(a.x==maxx) diemmax=a;
        if(b.x==minx) diemmin=b;
        if(b.x==maxx) diemmax=b;
        if(c.x==minx) diemmin=c;
        if(c.x==maxx) diemmax=c;
        if(d.x==minx) diemmin=d;
        if(d.x==maxx) diemmax=d;
        kq=kc(diemmin,diemmax)*(diemmax.x-diemmin.x);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("MOTION.inp","r",stdin);
    freopen("MOTION.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>m>>n>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y>>d.x>>d.y;
        kq=0;
        xuli();
        if(kq==-1) cout<<kq<<'\n';
        else cout<<kq<<" "<<abs(a.x-b.x)<<'\n';
    }
    return 0;
}
