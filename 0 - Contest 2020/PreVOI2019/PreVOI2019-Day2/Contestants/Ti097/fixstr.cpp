#include <bits/stdc++.h>
using namespace std;
string s;
int m,n;

void sub_1()
{
    string s2[1001];
    char form;
    int  x , sl , res , y;
    for (int i=1;i<=m;i++)
    {
        s2[i] = s;
        cin>>form ;
        if (form == 'C')
        {
            cin>>x;
            x--;
            if (s[x]==')') s[x] ='(';else s[x]=')';
        }

        if (form == 'Q')
        {
            cin>>x>>y;
            x--;
            y--;
            res = 0;
            sl = 0;
            for (int j=x;j<=y;j++)
                if (s[j]==')')
                {
                    sl--;
                    if (sl<0) {res++;sl = 0;}
                }else sl++;
            res += sl ;
            cout<<res<<"\n";
        }
        if (form == 'U')
        {
            cin>>x;
            s = s2[x];
        }
    }
    exit(0);
}

vector < int > lk[1000001];
pair <int , int> tr[4000001];

struct data
{
    char form ;
    int x , y , stt ;
};
data a[1000001];
int ans[1000001];
void build(int id,int l,int r)
{
    if (l>r) return;
    if (l==r)
    {
        if ( s[l] == ')' ) tr[id].first=1;else tr[id].second=1;
        return ;
    }
    int m=(l+r)/2;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    int du = tr[id*2].second - tr[id*2+1].first ;

    tr[id].first = tr[id*2].first ;
    tr[id].second = tr[id*2+1].second ;
    if(du>0) tr[id].second += du ;else tr[id].first += (-1)*du ;

}

void update (int id, int l ,int r ,int u )
{
    if (u<l||r<u) return ;
    if (l==r)
    {
        swap( tr[id].first , tr[id].second );
        return ;
    }
    int m=(l+r)/2;
    update(id*2,l,m,u);
    update(id*2+1,m+1,r,u);
    int du = tr[id*2].second - tr[id*2+1].first ;
    tr[id].first = tr[id*2].first ;
    tr[id].second = tr[id*2+1].second ;
    if(du>0) tr[id].second += du ;else tr[id].first += (-1)*du ;

}

pair < int , int > get(int id,int l ,int r ,int u ,int v)
{
    if (v<l || r<u ) return make_pair(0,0);
    if (u<=l && r<=v) return tr[id];
    int m=(l+r)/2;
    pair < int , int > X = get(id*2,l,m,u,v);
    pair < int , int > Y = get(id*2+1,m+1,r,u,v);
    pair < int , int > Z ;
    Z.first = X.first;
    Z.second = Y.second ;
    int du = X.second - Y.first ;
    if (du>0) Z.second += du; else Z.first += (-1)*du;
    return Z;
}

void dequy(int u)
{
    if (u>m) return ;

    if (u==0)
    {
        for (int i=0;i<lk[u].size();i++) dequy( lk[u][i] );
        if (a[u+1].form != 'U' ) dequy(u+1);
        return ;
    }

    if ( a[u].form == 'U' )
    {
        for (int i=0;i<lk[u].size();i++) if (lk[u][i] !=u) dequy( lk[u][i] );
        if (a[u+1].form != 'U' ) dequy(u+1);
        return  ;
    }

    if ( a[u].form == 'C' )
    {
        update( 1 ,0 , n-1 , a[u].x-1 );
        for (int i=0;i<lk[u].size();i++) if (lk[u][i] !=u) dequy( lk[u][i] );
        if (a[u+1].form != 'U' ) dequy(u+1);
        update( 1 ,0 , n-1 , a[u].x-1 );
        return ;
    }
    if (a[u].form == 'Q' )
    {
        pair < int , int > Res = get(1,0,n-1, a[u].x-1, a[u].y-1 ) ;
        ans[u] = Res.first + Res.second ;
        for (int i=0;i<lk[u].size();i++) if (lk[u][i] !=u) dequy( lk[u][i] );
        if (a[u+1].form != 'U' ) dequy(u+1);
        return ;
    }
}
int main()
{
    freopen("fixstr.inp","r",stdin);
    freopen("fixstr.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie();cout.tie();
    cin>>s;
    cin>>m;
    n = s.size();
    build(1,0,n-1);
    if (n <= 1000 && m<= 1000 ) sub_1();
    for (int i=1;i<=m;i++)
    {
        cin>>a[i].form ;
        if ( a[i].form == 'C' ) cin>>a[i].x;
        if ( a[i].form == 'Q' ) cin>>a[i].x>>a[i].y;
        if ( a[i].form == 'U')
        {
            cin>>a[i].x;
            lk[a[i].x-1].push_back(i);
        }
    }

    dequy(0);

    for (int i=1;i<=m;i++) if ( a[i].form == 'Q' ) cout<<ans[i]<<"\n";
    return 0;
}
