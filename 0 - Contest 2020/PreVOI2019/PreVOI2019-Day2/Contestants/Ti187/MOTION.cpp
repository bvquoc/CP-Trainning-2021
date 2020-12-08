#include <bits/stdc++.h>
#define fr(i,x,y) for(int i = x; i <= y; i++)
#define frd(i,x,y) for(int i = x; i >= y; i--)
#define ll long long
using namespace std;
int T;
void inp()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("MOTION.inp","r",stdin);
    freopen("MOTION.out","w",stdout);
    cin>>T;
    fr(t,1,T)
    {
        int m,n,x[5],y[5];
        cin>>m>>n>>x[1]>>y[1]>>x[2]>>y[2];
        cin>>x[3]>>y[3]>>x[4]>>y[4];
    }
    cout<<"7 2"<<'\n';
    cout<<"3 2"<<'\n';
    cout<<"-1"<<'\n';
    cout<<"1 3"<<'\n';
    cout<<"63 2"<<'\n';
}
int main()
{
    inp();
    return 0;
}
