#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pob pop_back
const int maxn = 200000 ;
const int MOD = 1000003 ;
int n,m;
int a[2*maxn];
int ra[2*maxn];
int x[maxn];
int dem0,dem1;
int kq=0;
vector < int > q;
void tinh()
{
   q.clear();
   for( int i=1;i<=2*n;i++ )
   {
       if( x[i] == 1 ) q.pb(i);
       else
       {
           if( a[i] > ra[q.back()] ) return;
           else q.pob();
       }
   }
   kq = (kq+1)%MOD;
}
bool kiemtra( int dodai )
{
  dem0=0;
  dem1=0;
  for(int i=1;i<=dodai;i++)
  {
      if( x[i] == 0 ) dem0++;
      else dem1++;
      if( dem1 < dem0 ) return false;
  }
  return true;
}
bool kiemtra2()
{
    dem1=0;
    for(int i=1;i<=2*n;i++)
    {
        dem1 += x[i];
    }
    return dem1==n;
}
void try1( int i )
{
    for(int j=0;j<=1;j++)
    {
        x[i] = j;
        if( kiemtra(i) == false ) continue;
        if( i == 2*n )
        {
           if( kiemtra2() == true ) tinh();
           else continue;
        }
        else try1(i+1);
    }
}
void subtask1()
{
   for(int i=1;i<=2*n;i++) {ra[i] = a[i]+m; cout<<ra[i]<<" ";}
   cout<<endl;
   try1(1);
   cout<<kq<<endl;
}
void nhap()
{
   cin>>n>>m;
   for(int i=1;i<=2*n;i++) cin>>a[i];
}
int main()
{
    freopen("Mine.inp","r",stdin);
    freopen("Mine.out","w",stdout);
    nhap();
    subtask1();
}
