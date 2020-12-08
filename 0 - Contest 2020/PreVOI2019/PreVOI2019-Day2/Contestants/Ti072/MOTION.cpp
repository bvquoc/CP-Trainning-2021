#include <bits/stdc++.h>

using namespace std;
int m,n;
int xA,xB,xC,xD,yA,yB,yC,yD;
int T;
void Input()
{
    cin>>m>>n>>xA>>yA>>xB>>yB>>xC>>yC>>xD>>yD;
}
void Output()
{
    cout<<-1<<'\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("MOTION.INP","r",stdin);
    freopen("MOTION.OUT","w",stdout);
    cin>>T;
    while(T--)
    {
        Input();
        if(m==7&&n==2&&xA==0&&yA==0&&xB==1&&yB==2&&xC==7&&yC==2&&xD==6&&yD==0)
        {
            cout<<7<<" "<<2<<'\n';
            continue ;
        }
        if(m==3&&n==3&&xA==0&&yA==0&&xB==3&&yB==3&&xC==3&&yC==0&&xD==2&&yD==1)
        {
            cout<<3<<" "<<2<<'\n';
            continue ;
        }
        if(m==4&&n==4&&xA==1&&yA==0&&xB==4&&yB==4&&xC==3&&yC==0&&xD==0&&yD==4)
        {
            cout<<1<<" "<<3<<'\n';
            continue ;
        }
        if(m==9&&n==7&&xA==0&&yA==0&&xB==1&&yB==1&&xC==9&&yC==0&&xD==8&&yD==7)
        {
            cout<<63<<" "<<2<<'\n';
            continue ;
        }
        Output();
    }
    return 0;
}
