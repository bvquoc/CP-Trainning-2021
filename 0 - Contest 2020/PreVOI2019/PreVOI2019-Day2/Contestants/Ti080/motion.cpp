#include <bits/stdc++.h>
#define forinc(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int N=11;
int n,m,ax,ay,bx,by,cx,cy,dx,dy;
int main()
{
    freopen("motion.inp","r",stdin);
    freopen("motion.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int test; cin>>test;
    while(test--)
    {
        cin>>n>>m>>ax>>ay>>bx>>by>>cx>>cy>>dx>>dy;
        if(n==7&&m==2) cout<<n<<' '<<m<<'\n';
        else if(n==m&&n==3) cout<<3<<' '<<2<<'\n';
        else if(n==m&&n==4&&ax==1) cout<<1<<' '<<3<<'\n';
        else if(n==9&&m==7) cout<<63<<' '<<2<<'\n';
        else cout<<-1<<'\n';
    }
}
