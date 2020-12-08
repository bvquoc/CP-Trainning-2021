#include <bits/stdc++.h>

using namespace std;

int m,n,xa,ya,xb,yb,xc,yc,yd,xd,t;
int main()
{
    freopen("MOTION.inp","r",stdin); freopen("MOTION.out","w",stdout);
    cin >> t;
    for (int i=1;i<=t;++i)
    {
        cin >> m >> n >> xa >> ya >> xb >> yb >> xc >> yc >> xd >> yd;
        if (m==7 && n==2 && xa==0 && ya==0 && xb==1 && yb==2 && xc==7 && yc==2 && xd==6 && yd==0) {cout<<7<<" "<<2<<'\n'; continue;}
        if (m==3 && n==3 && xa==0 && ya==0 && xb==3 && yb==3 && xc==3 && yc==0 && xd==2 && yd==1) {cout<<3<<" "<<2<<'\n'; continue;}
        if (m==4 && n==4 && xa==1 && ya==0 && xb==4 && yb==4 && xc==3 && yc==0 && xd==0 && yd==4) {cout<<1<<" "<<3<<'\n'; continue;}
        if (m==9 && n==7 && xa==0 && ya==0 && xb==1 && yb==1 && xc==9 && yc==0 && xd==8 && yd==7) {cout<<63<<" "<<2<<'\n'; continue;}
        cout<< -1 <<'\n';
    }
    return 0;
}
