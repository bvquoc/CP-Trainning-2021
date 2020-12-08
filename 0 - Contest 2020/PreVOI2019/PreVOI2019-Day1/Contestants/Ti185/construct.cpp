///Bankai: Getsuga Tenshou
#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
using namespace std;
const ll khong=0;
ll m,n,x,y,v,a[100005],kq=0,t,h[100005];
int kt;
void xuli()
{
    for(int i=1;i<=t;i++)
    {
        cin>>n>>m;
        for(int j=1;j<=n;j++) cin>>a[j];
        for(int j=1;j<=m;j++)
        {
            cin>>kt;
            if(kt==1)
            {
                cin>>x>>y>>v;
                for(int k=x;k<=y;k++) a[k]+=v;
            }
            else
            {
                kq=0;
                cin>>x>>y;
                for(int k=1;k<=n;k++) h[k]=0;
                for(int k=x;k<=y;k++) h[k]=a[k];
                for(int k=1;k<=n;k++) kq+=max(khong,h[k]-h[k-1]);
                cout<<kq<<'\n';
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("construct.inp","r",stdin);
    freopen("construct.out","w",stdout);
    cin>>t;
    xuli();
    return 0;
}
