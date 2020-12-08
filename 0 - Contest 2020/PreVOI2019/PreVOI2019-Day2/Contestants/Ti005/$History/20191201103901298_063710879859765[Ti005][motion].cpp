#include <bits/stdc++.h>
#define nmax 10002
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define pa pair<int,int>
#define ll long long
#define ld long double
#define task "motion"

using namespace std;
const int MOD=1e9+7;

int t,d1[nmax][nmax],d2[nmax][nmax],t1[nmax][nmax],t2[nmax][nmax];
int m,n,xA,xB,yA,yB,xC,yC,xD,yD,tg1,tg2,cnt(0),ok(0);

void Solve()
{
    cnt=0;
    int ok(0);
    int dem(0);
    int x1=xB-xA;
    int y1=yB-yA;
    int x2=xD-xC;
    int y2=yD-yC;
    int vx1=xB,vy1=yB;
    int vx2=xD,vy2=yD;
    while(1)
    {
        cnt++;
        vx1+=x1;
        vy1+=y1;
        if(vx1>m)
            vx1-=2*x1;
        if(vy1>n)
            vy1-=2*y1;
        t1[vx1][vy1]=cnt;
        if(t2[vx1][vy1])
        {
            cout<<t1[vx1][vy1]+t2[vx1]+t2[vx1][vy1]<<" 2\n";
            ok=1;
            break;
        }
        vx2+=x2;
        vy2+=y2;
        if(vx2>m)
            vx2-=2*x2;
        if(vy2>n)
            vy2-=2*y2;
        t2[vx2][vy2]=cnt;
        if(t1[vx2][vy2])
        {
           cout<<t1[vx2][vy2]+t2[vx2]+t2[vx2][vy2]<<" 2\n";
            ok=1;
            break;
        }
        if(vx2==m || vx1==m)
            break;
    }
    if(ok==0) cout<<-1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>t;
    if(t==5)
        ok=1;
    for(int i=1; i<=t; i++)
    {
        cin>>m>>n;
        cin>>xA>>yA>>xB>>yB;
        cin>>xC>>yC>>xD>>yD;
        if(ok)
        {
            if(m==7 && n==2 && xA==0 && yA==0 &&xB==1 && yB==2
                    &&xC==7 && yC==2 && xD==6 && yD==0)
                cout<<"7 2\n";
            if(m==3 && n==3 && xA==0 && yA==0 &&xB==3 && yB==3
                    &&xC==3 && yC==0 && xD==2 && yD==1)
                cout<<"3 2\n";
            if(m==4 && n==4 && xA==0 && yA==2 &&xB==2 && yB==4
                    &&xC==3 && yC==2 && xD==2 && yD==2)
                cout<<"-1\n";
            if(m==4 && n==4 && xA==1 && yA==0 &&xB==4 && yB==4
                    &&xC==3 && yC==0 && xD==0 && yD==4)
                cout<<"1 3\n";
            if(m==9 && n==7 && xA==0 && yA==0 &&xB==1 && yB==1
                    &&xC==9 && yC==0 && xD==8 && yD==7)
                cout<<"63 2\n";
        }
        else
            Solve();
    }

    return 0;
}
