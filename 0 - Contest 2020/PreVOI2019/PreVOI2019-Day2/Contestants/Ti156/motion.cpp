#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long double ld;
int T,m,n,ok,times;
struct point
{
    ld x,y;
} A,B,C,D;
int len(point a,point b)
{
    return (a.x-b.x)*(a.y-b.y);
}
pair<ld,ld> Find(ld x,ld y,ld a,ld b)
{
    ld len=(x-a)*(x*a)+(y-b)*(y-b);
    if(b==n||b==0)
    {
        ld px=(x-a)*(x-a);
        return {sqrt(len-px),y};
    }
    return {a,b};

}
int main()
{
    freopen("motion.inp","r",stdin);
    freopen("motion.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>m>>n>>A.x>>A.y>>B.x>>B.y>>C.x>>C.y>>D.x>>D.y;
        times=0;
        if(A.x>C.x)
        {
            swap(A,C);
            swap(B,D);
        }
        while(true)
        {
            point na,nc;
            na={B.x,B.y};
            nc={D.x,D.y};
            times++;
          //  cout<<na.x<<" "<<na.y<<" "<<nc.x<<" "<<nc.y<<'\n';
            if(na.x==nc.x&&na.y==nc.y)
            {
                cout<<times<<" "<<1;
                break;
            }
            else
            {
                if(na.x<nc.x)
                {
                    if((na.x<A.x&&nc.x>C.x)||(na.y!=0&&na.y!=n&&nc.y!=0&&nc.y!=n))
                    {
                        cout<<-1;
                        break;
                    }
                    B={2*B.x-A.x,A.y};
                    D={2*D.x-C.x,C.y};
                    A={na.x,na.y};
                    C={nc.x,nc.y};
                }
               else
               {
                   if(A.x==C.x)
                   {
                       if(len(A,B)!=len(C,D))
                           cout<<-1;
                       else
                       {
                           int p=len(A,C),q=len(B,D),py;
                           p=sqrt(p);
                           q=sqrt(q);
                           q+=p;
                           times=times*q+p;
                           int g=__gcd(times,q);
                           times/=g;
                           q/=g;
                           cout<<times<<" "<<q<<'\n';
                       }
                       break;
                   }
                   else
                   {
                        times=(times-1)*2+1;
                        cout<<times<<" "<<2<<'\n';
                       break;
                   }
               }
            }
        }
    }
}
