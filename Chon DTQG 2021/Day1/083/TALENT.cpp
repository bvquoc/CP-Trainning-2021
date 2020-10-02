#include <bits/stdc++.h>
using namespace std;
 int n,m,d[100000000],w[100000000],q[100000000];

  int load(int p)
  {
          int s=0;
      for (int i=1;i<=n;i++) s+=w[i]*abs(p-d[i]);
        return s;
  }


 int main()
 {
   freopen("TALENT.INP","r",stdin);
    freopen("TALENT.OUT","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>d[i];
    for (int i=1;i<=n;i++) cin>>w[i];
for (int i=1;i<=m;i++) cin>>q[i];

for (int i=1;i<=m;i++)
    cout<<load(q[i])<<endl;


     return 0;
 }
