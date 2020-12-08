#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000004 ;
string s,luu[maxn];
int n,m;
bool kt;
int open,close;
int kq;
int dodai;
struct query
{
    char loai;
    int u;
    int v;
};
query que[maxn];
struct node
{
    int left;
    int right;
};
node st[maxn*4],rac;
node operator + ( node l , node r )
{
    node tg;
    tg.left = r.left ;
    tg.right = l.right;
    int sot = l.left - r.right;
    if( sot >= 0 ) tg.left += sot;
    else tg.right += abs(sot);
    return tg;
}
void build( int id , int l , int r )
{
    if( l > r ) return;
    if( l == r )
    {
        if( s[l] == '(' )
        {
            st[id].left = 1;
            st[id].right = 0;
        }
        else
        {
            st[id].right = 1;
            st[id].left = 0;
        }
        return;
    }
    int mid = (l+r)/2;
    build( 2 * id , l , mid );
    build( 2 * id + 1 , mid + 1 , r );
    st[id] = st[2 * id] + st[2 * id + 1];
}
void update( int id , int l , int r , int pos  )
{
   if( l > r || pos > r || pos < l ) return;
   if( pos == l && r == l )
   {
       if( s[l] == '(' )
       {
           st[id].left = 1;
           st[id].right = 0;
       }
       else
       {
           st[id].left = 0;
           st[id].right = 1;
       }
       return;
   }
   int mid = (l + r)/2;
   update( 2 * id , l , mid , pos  );
   update( 2 * id + 1 , mid + 1 , r , pos  );
   st[id] = st[2 * id] + st[2 * id + 1];
}
node get( int id , int l , int r , int L , int R )
{
    if( l > r || L > r || R < l ) return rac;
    if( L <= l && r <= R ) return st[id];
    int mid = (l + r)/2;
    return get( 2 * id , l , mid , L , R )
         + get( 2 * id + 1 , mid + 1 , r , L , R );
}
void subtask2()
{
    rac.left = 0;
    rac.right = 0;
   build(1,1,n);
   node wat;
   for( int i=1; i <= m ; i++ )
   {
       if( que[i].loai == 'C' )
       {
           if( s[ que[i].u ] == '(' ) s[ que[i].u ] = ')';
           else s[ que[i].u ] = '(';
           update(1,1,n,que[i].u);
       }
       else
       {
           wat = get(1,1,n,que[i].u,que[i].v);
           cout<<wat.left << " "<< wat.right<<endl;
       }
   }
}
void tinh( string x )
{
   dodai = x.size()-1;
   kq=0;
   open = 0 ;
   close = 0 ;
   for( int i=1 ; i <= dodai ; i++ )
   {
       if( x[i] == '(' ) open++;
       else close++;
       if( close > open ) {close=0;kq++;}
       else
       {
          open -= close;close = 0;
       }
   }
   kq+=open;
   cout<<kq<<endl;
}
void subtask1()
{
   luu[0] = s;
   string stg=s;
   string nani;
   for(int i=1;i<=m;i++)
   {
       stg=luu[i-1];
       if( que[i].loai == 'C' )
       {
          if( stg[ que[i].u ] == ')' ) stg[ que[i].u ] = '(' ;
          else stg[ que[i].u ] = ')' ;
       }
       if( que[i].loai == 'U' )
       {
           stg = luu[ que[i].u - 1 ];
       }
       if( que[i].loai == 'Q' )
       {
          nani = "";
          for( int j = que[i].u ; j <= que[i].v ; j++ )
          {
              nani = nani + stg[j];
          }
          nani = " " +nani;
          tinh(nani);
       }
       luu[i] = stg;
   }
}
void nhap()
{
   kt=false;
   cin>>s;
   n=s.size();
   s=" "+s;
   cin.ignore();
   cin>>m;
   for(int i=1;i<=m;i++)
   {
       cin.ignore();
       cin>>que[i].loai;
       if( que[i].loai == 'C' ) { cin>>que[i].u; }
       if( que[i].loai == 'U' ) { cin>>que[i].u; kt=true;}
       if( que[i].loai == 'Q' ) { cin>>que[i].u>>que[i].v;}
   }
}
int main()
{
    freopen("FIXSTR.INP","r",stdin);
    freopen("FIXSTR.OUT","w",stdout);
    nhap();
    if( n <= 1000 && m <= 1000 ) subtask1();
    else if( kt == false ) subtask2();
}
