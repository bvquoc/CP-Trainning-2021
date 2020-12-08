#include <bits/stdc++.h>
using namespace std;
string s="";
int n;
int dodai;
void tao( char x , char y )
{
   dodai = s.size();
   for(int i=0;i<dodai;i++)
   {
       if( s[i] == x )
       {
           s[i] = y;
       }
   }
}
void subtask1()
{
    s="";
    char na,ni;
    int que;
    for(int i=1;i<=n;i++)
    {
       cin>>que;
       if( que == 1 )
       {
           cin>>na;
           s = s + na;
       }
       else
       {
           cin>>na>>ni;
           tao(na,ni);
       }
    }
    cout<<s;
}
void nhap()
{
   cin>>n;
}
int main()
{
    freopen("PAINT.INP","r",stdin);
    freopen("PAINT.OUT","w",stdout);
    nhap();
    subtask1();
}
