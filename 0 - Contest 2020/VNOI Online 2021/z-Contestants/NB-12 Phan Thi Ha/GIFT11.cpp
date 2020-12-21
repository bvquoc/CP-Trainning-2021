#include <bits/stdc++.h>
using namespace std;
int m,n[2000],kq[2000],dem,sl,chan,le,mod,t,s,kt1,res;
string a[10][2000];
bool kt[2000];
int tinh(int x, int y, int j)
{
    for (int i=1; i<=x; i++)
          if (kt[i])
               {
                   kq[j]=i;
                   if (j==x)
                        {
                                chan=0;
                                le=0;
                                sl=0;
                                for (int k=1; k<=x; k++)
                                   for (int k1=0; k1<a[y][kq[k]].length(); k1++ )
                                     {
                                           ++sl;
                                           if (sl%2==0) le=le+a[y][kq[k]][k1]-'0';
                                           else chan=chan+a[y][kq[k]][k1]-'0';
                                     }
                                if ((le-chan)%11==0) ++dem;
                                if (dem>mod) dem=dem-mod;
                         }
                else
                      {
                        kt[i]=false;
                        tinh(x,y,j+1);
                        kt[i]=true;
                       }
               }
}
int main()
{
    freopen("GIFT11.inp","r",stdin);
    freopen("GIFT11.out","w",stdout);
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();
    cin>>t;
    s=0;
    mod=998244353;
    for (int h=1; h<=t; h++)
    {
         cin>>n[h];
         s=n[h];
          kt1=1;
         for (int i=1; i<=n[h]; i++)
          {
             cin >> a[h][i];
             if (a[h][i].length() % 2 ==0) kt1=0;
          }
          if (s<=15)
             {
                   {
                       dem=0;
                       m=n[h];
                       for (int i=1; i<=m; i++) kt[i]=true;
                       tinh(m,h,1);
                       cout<<dem<<endl;
                    }
               }
          else
                if  (kt1==1)
                   {
                       chan=0;
                       le=0;
                       res=1;
                       for (int i=1; i<=n[h]; i++)
                          {
                               res=res*i;
                               if (res>mod) res=res-mod;
                               for (int j=0; j<a[h][i].length(); j++)
                                  if (j%2==0) le=le+a[h][i][j]-'0';
                                  else chan=chan+a[h][i][j]-'0';
                             }
                      if ((le-chan)%11==0) cout<<res<<endl;
                      else cout<<'0'<<endl;
                   }
         else   cout<<'0'<<endl;


    }

}
