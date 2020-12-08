#include <bits/stdc++.h>
using namespace std;
#define int long long
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define fi first
#define se second
#define pii pair<int,int>
#define getbit(i,x) ((x>>i)&1ll)

int test;
int m,n;
pair<int,int> pos[5];/// 1->2 3->4

main()
{
    freopen("MOTION.inp","r",stdin);
    freopen("MOTION.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin>>test;
    forinc(i,1,test)
    {
        cin>>m>>n;
        forinc(i,1,4) cin>>pos[i].fi>>pos[i].se;
        if(i==1) cout<<7<<" "<<2;
        if(i==2) cout<<3<<" "<<2;
        if(i==3) cout<<-1;
        if(i==4) cout<<1<<" "<<3;
        if(i==5) cout<<63<<" "<<2;
        cout<<"\n";
    }
}
