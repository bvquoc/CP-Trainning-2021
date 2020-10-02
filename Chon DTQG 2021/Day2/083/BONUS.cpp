#include <bits/stdc++.h>
using namespace std;
 int64_t n,r,k,x[100000],y[100000], a[10000][10000],own[10000][10000],
 xx[10000],yy[10000],final_square=0;
 int square2(int pos_x, int pos_y, int temp_x , int temp_y)
 {    int s=0;
     for (int i=min(pos_x,temp_x);i<=max(pos_x,temp_x);i++ )
      for (int j=min(pos_y,temp_y);j<=max(pos_y,temp_y);j++ )
      if (i>=1 && j>=1 && i<=n && j<=n && !own[i][j])
     {
       s+=a[i][j];
     }
     return s;
 }
  int max_square(int64_t pos_x , int64_t pos_y)
  {
      int64_t s=0,pivot_x,pivot_y,
      temp_x=pos_x -(r-1), temp_y =pos_y-(r-1);
// th1
     if (square2(pos_x,pos_y,temp_x,temp_y) >s)
        { s=square2(pos_x,pos_y,temp_x,temp_y) ; pivot_x = temp_x; pivot_y =temp_y ; }
//th2
       temp_x = pos_x - (r-1) , temp_y = pos_y + (r-1);
            if (square2(pos_x,pos_y,temp_x,temp_y) >s)
        { s=square2(pos_x,pos_y,temp_x,temp_y) ; pivot_x = temp_x; pivot_y =temp_y ; }
//th3
        temp_x = pos_x + (r-1) , temp_y = pos_y - (r-1);
             if (square2(pos_x,pos_y,temp_x,temp_y) >s)
        { s=square2(pos_x,pos_y,temp_x,temp_y) ; pivot_x = temp_x; pivot_y =temp_y ; }
//th4
        temp_x = pos_x + (r-1) , temp_y = pos_y + (r-1);
             if (square2(pos_x,pos_y,temp_x,temp_y) >s)
        { s=square2(pos_x,pos_y,temp_x,temp_y) ; pivot_x = temp_x; pivot_y =temp_y ; }
//danh dau max_square duoc chon
      for (int i=min(pos_x,pivot_x);i<=max(pos_x,pivot_x);i++ )
      for (int j=min(pos_y,pivot_y);j<=max(pos_y,pivot_y);j++ )
      own[i][j]=1;

      return s;
  }
 int main()
 {
    freopen("BONUS.INP","r",stdin);
    freopen("BONUS.OUT","w",stdout);
    cin>>n>>r>>k;
    for (int i=1;i<=n;i++)
         for (int j=1;j<=n;j++)
          cin>>a[i][j];
          for (int i=1;i<=k;i++)
               cin>>x[i]>>y[i];
               for (int i=1;i<=k;i++)
                final_square+=max_square(x[i],y[i]);
  cout<<final_square;
     return 0;
 }
