#include <bits/stdc++.h>

using namespace std;
const int N=200005;
int n;
int a[N],b[N],f[N],dd[N],c[N];
struct bitree
{
    int bit[N];
    void reset()
    {
        for(int i=1;i<=n;i++) bit[i]=0;
    }
    void upt(int u)
    {
        while(u>0)
        {
            bit[u]++;
            u-=u&(-u);
        }
    }
    int get(int u)
    {
        int k=0;
        while(u<=n)
        {
            k+=bit[u];
            u+=u&(-u);
        }
        return k;
    }
} tree;
int demcach()
{
    int ans=0;
    tree.reset();
    for(int i=1; i<=n; i++)
    {
        cout<<c[i]<<" ";
        f[i]=tree.get(c[i]);
        tree.upt(c[i]-1);
        ans+=f[i];
    }
    return ans;
}
void sub1()
{
    int ans=0;
    tree.reset();
    for(int i=1; i<=n; i++)
    {
        f[i]=tree.get(a[i]);
        tree.upt(a[i]-1);
        ans+=f[i];
    }
    cout<<ans;
}
void hoanvi(int j)
{
    for(int i=1; i<=n; i++)
    {
        if(!dd[i])
        {
            c[j]=i;
            if(j<n)
            {
                dd[i]=1;
                hoanvi(j+1);
                dd[i]=0;
            }
            else cout<<demcach()<<'\n';
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("permeow.inp","r",stdin);
    freopen("permeow.out","w",stdout);
    cin>>n;
//    hoanvi(1);
    for(int i=1; i<=n; i++)
        cin>>a[i];
    for(int i=1; i<=n; i++)
        cin>>b[i];
    int ck=0;
    for(int i=1; i<=n; i++)
        if(a[i]!=b[i])
        {
            ck=1;
            break;
        }
    if(ck==0)
        sub1();
    return 0;
}
