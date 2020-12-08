#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100005 ;
int n,m;
int a[maxn];
int l,r,k,que;
ll kq=0;
void cong()
{
    for(int i=l;i<=r;i++)
    {
        a[i]+=k;
    }
}
void tinh()
{
    kq=0;
    kq+=a[l];
    for(int i=l;i<=r-1;i++)
    {
        if( a[i+1] > a[i] ) kq+=a[i+1]-a[i];
    }
    cout<<kq<<endl;
}
void subtask1()
{
   for(int i=1;i<=m;i++)
   {
     cin>>que;
     if( que == 1 )
     {
         cin>>l>>r>>k;
         cong();
     }
     else
     {
         cin>>l>>r;
         tinh();
     }
   }
}
void nhap()
{
   cin>>n>>m;
   for(int i=1;i<=n;i++) cin>>a[i];
}
int main()
{
    freopen("Construct.inp","r",stdin);
    freopen("Construct.out","w",stdout);
    int t;
    cin>>t;
    while( t-- )
    {
        nhap();
        subtask1();
    }
}
