#include <bits/stdc++.h>

using namespace std;
long long t,n,m,a[1000001],ne[1000001];
long long tinh(long long lef,long long rig)
{
 //   cout<<"lef="<<lef<<" rig="<<rig<<"\n";
    if (lef==rig) return ne[lef];
   long long mi=ne[lef];
    for (int p=lef;p<=rig;p++)mi=min(mi,ne[p]);
    long long ans=0;
    ans+=mi;
    for (int p=lef;p<=rig;p++) ne[p]-=mi;
   long long tr=lef;long long sau;

    while (true)
    {
        while (ne[tr]==0 && tr<=rig) tr++;
        if (tr>rig) break;
        sau=tr;while (ne[sau]!=0 && sau<=rig) sau++;
       // cout<<"\n";
       // cout<<"tr="<<tr<<" sau="<<sau<<" "<<tinh(tr,sau-1)<<"\n";
       // cout<<"\n";
        ans+=tinh(tr,sau-1);
        if (sau>rig) break;
        tr=sau;
    }
  // cout<<"ans="<<ans<<"\n";
    return ans;
}
int main()
{
    freopen("construct.inp","r",stdin);
    freopen("construct.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
    cin>>t;
    while (t--)
    {

        cin>>n>>m;
        for (int i=1;i<=n;i++) cin>>a[i];
        for (int i=1;i<=m;i++)
        {
            long long tt;
            cin>>tt;
                if (tt==1)
            {
                long long l,r,k;
                cin>>l>>r>>k;
                for (int j=l;j<=r;j++) a[j]+=k;
            }
            else
            {
                long long l,r;
                cin>>l>>r;
                for(int ij=l;ij<=r;ij++) ne[ij]=a[ij];
                cout<<tinh(l,r)<<"\n";

            }
        }
    }
}
