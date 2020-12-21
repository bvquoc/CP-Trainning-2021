#include <bits/stdc++.h>
#define TASK "PERMEOW"
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define READFILE freopen(TASK".INP","r",stdin)
#define WRITEFILE freopen(TASK".OUT","w",stdout)
#define For(i,a,b) for(int i=a;i<=b;i++)
#define Rep(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define oo 1e18
#define ENDL '\n'
#define debug(x) cout<<#x<<" = "<<x<<ENDL
#define fi first
#define se second
#define ever (;true;)
#define all(x) x.begin(),x.end()
#define sz(a) ((int)(a).size())
#define ms(a,x) memset(a,x,sizeof(a))
#define odd(a) (a&1)
#define lamtron(a) (floorf((float)a+0.6f))
#define chusothapphan(a) setprecision(a+1)
#define hoanvi(a,start,stop) next_permutation(a+start,a+stop)
#define vi vector <int>
#define vvi vector <vi>
#define ii pair <int,int>
#define vii vector <ii>
#define vvii vector <vii>
#define iii pair <int,ii>
 
using namespace std;
 
const int MaxN = 200100;
const int modulo = 1e9+7;
int a[MaxN],b[MaxN],c[MaxN];
int n,step; 
int check(int *x,int *y,int n)
{
  For(i,1,n)
  {
    if (x[i]<y[i]) return -1;
    if (x[i]>y[i]) return 1;
  }  
  return 0;  
}
int BubbleSort(int *arr, int n)  
{  
  int step=0;
  For(i,1,n)      
    For(j,1,n-i)  
      if (arr[j]>arr[j+1])  
      {  
        swap(arr[j],arr[j+1]);  
        step++;
        step+=modulo;
        step%=modulo;
      }
  return step;    
}   
signed main()
{
  FAST;
  //#ifndef ONLINE_JUDGE
    READFILE;
    WRITEFILE;
  //#endif
  cin>>n;
  For(i,1,n)
    cin>>a[i];
  For(i,1,n)  
    cin>>b[i];
  int m=check(a,b,n); 
  if (m==1)
  {
    cout<<0;
    return 0;
  }
  if (!m)
  {
    cout<<BubbleSort(a,n);
    return 0;
  }  
  step=0;
  do
  {
    For(i,1,n) c[i]=a[i];
    step+=BubbleSort(c,n);
    step%=modulo;
  }
  while (hoanvi(a,1,n+1) && check(a,b,n)!=1);
  cout<<step;
  return 0;
}