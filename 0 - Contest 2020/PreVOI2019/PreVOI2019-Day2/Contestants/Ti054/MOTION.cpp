#include<bits/stdc++.h>
using namespace std;
#define y1 A2Dalek
#define y0 Cyberman
#define yn RoseTyler
#define j1 JackHarkness
#define fs first
#define sd second
const int N=2e5;
const int oo=1e9+5;
int du[]={-1,0,0,1};
int dv[]={0,-1,1,0};
const long long mod=1e9+7;
const long double EXP=1e-5;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
long long sqr(long long x) {return x*x;}
int getbit(int state, int i) {return ((state>>i)&1);}

int gcd(int x, int y)
{
    while (y)
    {
        int r=x%y; x=y; y=r;
    }
    return x;
}
long double n,m,nowx1,nowy1,nowx2,nowy2,vx1,vx2,vy1,vy2;
long double xA,yA,xB,yB,xC,yC,xD,yD;
long double per=(long double) 1/(long double) 30030;
void chuyenhuong(long double &x, long double &y, long double &vx, long double &vy)
{
    if (0<x && x<n && 0<y && y<m) return;
    if (x==n && y==m)
    {
        vx=-vx; vy=-vy;
        return;
    }
    if (x==0 && y==m)
    {
        vx=-vx; vy=-vy;
        return;
    }
    if (x==0 && y==0)
    {
        vx=-vx; vy=-vy;
        return;
    }
    if (x==n && y==0)
    {
        vx=-vx; vy=-vy;
        return;
    }
    if (x==n || x==0) {vx=-vx; return;}
    if (y==m || y==0) {vy=-vy; return;}
}
int main()
{
	freopen("MOTION.inp","r",stdin);
	freopen("MOTION.out","w",stdout);
	ios_base::sync_with_stdio(false);
	int t;
    cin>>t;
    while (t--)
    {
        cin>>n>>m>>xA>>yA>>xB>>yB>>xC>>yC>>xD>>yD;
        nowx1=xA; nowy1=yA; nowx2=xC; nowy2=yC;
        vx1=xB-xA; vy1=yB-yA; vx2=xD-xC; vy2=yD-yC;
        int Time=0;
        while (1)
        {
            Time++;
            if (Time>3000000) break;
            nowx1+=vx1*per;
            nowx2+=vx2*per;
            nowy1+=vy1*per;
            nowy2+=vy2*per;
            if (abs(nowx1-nowx2)<=EXP && abs(nowy1-nowy2)<=EXP) break;
            chuyenhuong(nowx1,nowy1,vx1,vy1);
            chuyenhuong(nowx2,nowy2,vx2,vy2);
        }
        if (Time>3000000) cout<<-1<<endl; else
        {
            int tmp=gcd(Time,30030);
            cout<<Time/tmp<<" "<<30030/tmp<<endl;
        }
    }
	return 0;
}
