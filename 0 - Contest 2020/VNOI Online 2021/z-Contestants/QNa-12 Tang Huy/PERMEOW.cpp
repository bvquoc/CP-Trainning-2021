#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N],b[N],I[N],res=0;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("PERMEOW.INP","r",stdin);
    freopen("PERMEOW.OUT","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++)
        cin>>b[i];
   for (int i=1;i<=n;i++)
   {
       int tmp,minx=i;
       for (int j=i;j<=n;j++)
       {
           if (a[j]<a[minx]) minx=j;
       }
       if (minx!=i)
       {
           tmp=a[minx];
           a[minx]=a[i];
           a[i]=tmp;
           res++;
       }
   }
   cout<<res;
}
