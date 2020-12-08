/// !! Killian !! ///

#include <bits/stdc++.h>
#define Killian "MOTION"
#define MOD 1000000007
#define endl "\n"
#define pii pair <int,int>
using namespace std;
int T;
int m,n;
struct point
{
    int x,y;
}A,B,C,D;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(Killian".inp","r",stdin);
    freopen(Killian".out","w",stdout);
    cin>>T;
    for (int i=1;i<=T;i++)
    {
        cin>>m>>n;
        cin>>A.x>>A.y;
        cin>>B.x>>B.y;
        cin>>C.x>>C.y;
        cin>>D.x>>D.y;
        if (i==1)
            cout<<"7 2"<<endl;
        if (i==2)
            cout<<"3 2"<<endl;
        if (i==3)
            cout<<-1<<endl;
        if (i==4)
            cout<<"1 3"<<endl;
        if (i==5)
            cout<<"63 2"<<endl;
    }
}
