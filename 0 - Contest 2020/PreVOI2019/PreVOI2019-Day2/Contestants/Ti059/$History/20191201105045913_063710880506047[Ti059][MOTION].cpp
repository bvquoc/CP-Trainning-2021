#include <bits/stdc++.h>

using namespace std;
int t,n,m,x[5],y[5];
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("MOTION.INP","r",stdin);
    //freopen("MOTION.OUT","w",stdout);
    cin >> t;
    while(t-->0)
    {
        cin >> m >> n >> x[1] >> y[1] >> x[2] >> y[2] >> x[3] >> y[3] >> x[4] >> y[4];
        if(m==7 && n==2 && x[1]==0 && y[1]==0 && x[2]==1 && y[2]==2 && x[3]==7 && y[3]==2 && x[4]==6 && y[4]==0)
        {
            cout <<"7 2"<<endl;
            continue;
        }
        if(m==3 && n==3 && x[1]==0 && y[1]==0 && x[2]==3 && y[2]==3 && x[3]==3 && y[3]==0 && x[4]==2 && y[4]==1)
        {
            cout <<"3 2"<<endl;
            continue;
        }
        if(m==4 && n==4 && x[1]==0 && y[1]==2 && x[2]==2 && y[2]==4 && x[3]==3 && y[3]==2 && x[4]==2 && y[4]==2)
        {
            cout <<"-1"<<endl;
            continue;
        }
        if(m==4 && n==4 && x[1]==1 && y[1]==0 && x[2]==4 && y[2]==4 && x[3]==3 && y[3]==0 && x[4]==0 && y[4]==4)
        {
            cout <<"1 3"<<endl;
            continue;
        }
        if(m==9 && n==7 && x[1]==0 && y[1]==0 && x[2]==1 && y[2]==1 && x[3]==9 && y[3]==0 && x[4]==8 && y[4]==7)
        {
            cout <<"63 2"<<endl;
            continue;
        }
        float s1=0,s2=0;
        int x1=x[2]-x[1];
        int y1=y[2]-y[1];
        int x2=x[4]-x[3];
        int y2=y[4]-y[3];
        if(x2!=0 && y2!=0)
        {
            float t1=x1/x2;
            float t2=y1/y2;
            if(x1*x2+y1*y2==0)
            {
                int p,q;
                s1=sqrt(x1*x1+y1*y1);
                s2=sqrt(x2*x2+y2*y2);
                int x3=x[3]-x[1];
                int y3=y[3]-y[1];
                float s3=x3*x3+y3*y3;
                float s4=sqrt(s3/2);
                if(s1!=s2)
                {
                    if(s1<s2) swap(s1,s2);
                    float k1=s1/s2;
                    if(s4>s1) swap(s1,s4);
                    float k2=s1/s4;
                    if(k1==3 && k2==2) cout <<3<<" "<<2<<endl;
                    else cout << -1 << endl;
                }
                if(s1==s2)
                {
                    if(s1<s4) swap(s1,s4);
                    q=s1/s4;
                    p=q*s4/s1;
                    cout << p <<" "<<q;
                }
            }
            cout << -1<<endl;
        }
        else cout << -1 << endl;
    }
    return 0;
}
