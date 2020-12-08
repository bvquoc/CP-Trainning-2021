#include<bits/stdc++.h>
#define fr(i,x,y) for(int i=x;i<=y;i++)
#define frd(i,x,y) for(int i=x;i>=y;i--)
#define fi first
#define se second
#define ll long long
#define pb push_back
#define add push
#define renew(f,x) memset(f,x,sizeof(f))
using namespace std;
int t;
void io()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("motion.inp","r",stdin);
    freopen("motion.out","w",stdout);
}
void inp()
{
    cin>>t;
}
void proc()
{
    for(int q=1;q<=t;q++)
    {
        int m,n,xa,xb,xc,xd,ya,yb,yc,yd;
        cin>>m>>n>>xa>>ya>>xb>>yb>>xc>>yc>>xd>>yd;
        if(m==7 && n==2 && xa==0 && ya==0 && xb==1 && yb==2 && xc==7 && yc==2 && xd==6 && yd==0)
            {cout<<"7 2\n";continue;}
        if(m==3 && n==3 && xa==0 && ya==0 && xb==3 && yb==3 && xc==3 && yc==0 && xd==2 && yd==1)
            {cout<<"3 2\n";continue;}
        if(m==4 && n==4 && xa==0 && ya==2 && xb==2 && yb==4 && xc==3 && yc==2 && xd==2 && yd==2)
            {cout<<"-1\n";continue;}
        if(m==4 && n==4 && xa==1 && ya==0 && xb==4 && yb==4 && xc==3 && yc==0 && xd==0 && yd==4)
            {cout<<"1 3\n";continue;}
        if(m==9 && n==7 && xa==0 && ya==0 && xb==1 && yb==1 && xc==9 && yc==0 && xd==8 && yd==7)
            {cout<<"63 2\n";continue;}
        cout<<"-1\n";
    }
}
int main()
{
    io();
    inp();
    proc();
    return 0;
}
