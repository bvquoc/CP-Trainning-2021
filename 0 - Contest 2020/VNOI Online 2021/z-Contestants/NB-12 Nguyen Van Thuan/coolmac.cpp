#include <bits/stdc++.h>
#define maxn 100005
using namespace std;
int  t[maxn],l[maxn],r[maxn],m,n,a1,a2,a4,vt,d[maxn];
int main()
{
   freopen("coolmac.inp","r",stdin);
   freopen("coolmac.out","w",stdout);
   scanf("%d",&m);
   a1=1e5+1;
   int cs=0;
   for(int i=1; i<=m; i++)
   {scanf("%d%d",&l[i],&r[i]);
   if(r[i]==100000) { a1=min(a1,l[i]); d[i]=1;++cs;}
   }
  if(cs==0) {printf("-1"); return 0;}
   scanf("%d",&n);
    a4=1e5+1;
   for(int i=1; i<=n; i++){ scanf("%d",&t[i]);
     a4=min(a4,t[i]);}
  int sl=1;
  while(true)
  {
   int min1=0;
  int vt=0;
for(int i=1;i<=m; i++)
    {
    if(r[i]>=a1&&d[i]==0)
    if(min1<(r[i]-l[i])){vt=i; min1=(r[i]-l[i]);}

    }
++sl;
if(vt==0) {printf("-1"); return 0;}
d[vt]=1;
a1=l[vt];
if(a1<a4) break;
  }
printf("%d",sl);
}

