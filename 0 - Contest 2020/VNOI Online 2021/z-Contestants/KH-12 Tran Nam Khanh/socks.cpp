#include <iostream>
#include <fstream>
using namespace std;
const int nax=5e5+5;
int n,q,a[nax],cnt=0;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("socks.inp","r",stdin);
    freopen("socks.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cnt+=a[i];
    }
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
    }
    for(int i=1;i<=q;i++)
    {
        int x;
        cin>>x;
        if(a[x])
        {
            a[x]=0;
            cnt--;
        }else
        {
            a[x]=1;
            cnt++;
        }
        if(cnt)cout<<1<<endl;else cout<<0<<endl;
    }
    return 0;
}
