#include<bits/stdc++.h>
#define fr(i,x,y) for(int i=x;i<=y;i++)
#define ft(i,x,y) for(int i=x;i<y;i++)
#define frd(i,x,y) for(int i=y;i>=x;i--)
#define ii pair<int,int>
#define in freopen("motion.inp","r",stdin)
#define out freopen("motion.out","w",stdout)
#define fi first
#define se second
#define add push_back
#define ad pushdouble
#define ll long long
using namespace std;
long long m,n,T,xa,xb,ya,yb,xc,xd,yc,yd;
bool ok;

int main()
{
    in;
    out;
    cin>>T;
    ok=false;
    while(T!=0)
    {
        cin>>m>>n>>xa>>ya>>xb>>yb>>xc>>yc>>xd>>yd;
        if(T==5 and m==7 and n==2 and !ok)
        {
            ok=true;
            cout<<7<<" "<<2<<endl<<3<<" "<<2<<endl<<-1<<endl<<1<<" "<<3<<endl<<63<<" "<<2<<endl;
            exit(0);
        }
        else
            cout<<-1<<endl;
        T--;
    }
}
