#include <bits/stdc++.h>

using namespace std;
const int nmax= 5e5+9;

int n, Q; int a[ nmax ];
vector< int > adj[ nmax ];


bool checkthang()
{
    for( int i= 1; i<= n; ++i ) if( adj[i].size() > 2 ) return false;
    return true;
}
int root;
bool checkchut()
{
    int dem= 0, dem2= 0;
    for( int i= 1; i<= n; ++i )
    {
        if( adj[i].size() == 3 ) { dem++; root= i; }
        if( adj[i].size() <= 2 ) dem2++;
    }

    if( dem == 1 && dem2 == n-1 ) return true;
    else return false;
}


void solvethang()
{
    int dem= 0;
    for( int i= 1; i<= n; ++i ) if( a[i] == 1 ) dem++;
    if( dem > 1 ) cout << 1 <<'\n'; else cout << 0 <<'\n';

    for( int q= 1; q<= Q; ++q )
    {
        int x; cin >> x;
        if( a[x] == 0 ) { a[x]= 1; dem++; }
        else { a[x]= 0; dem--; }

        if( dem > 1 ) cout << 1 <<'\n'; else cout << 0 <<'\n';
    }
}


int nhom[ nmax ];
void dfs( int u, int p, int id )
{
    for( int v: adj[u] ) if( v != p )
    {
        nhom[v]= id;
        dfs( v, u, id );
    }
}
void solvechut()
{
    int r= root;
    nhom[ adj[r][0] ]= 0; dfs( adj[r][0], r, 0 );
    nhom[ adj[r][1] ]= 1; dfs( adj[r][0], r, 1 );
    nhom[ adj[r][2] ]= 2; dfs( adj[r][0], r, 2 );

    int dem[3];
    for( int i= 1; i<= n; ++i ) dem[ nhom[i] ]++;
    if( dem[0] + dem[1] + dem[2] <= 1 ) cout << 0 <<'\n';
    else if( dem[0] == 0 || dem[1] == 0 || dem[2] == 0 ) cout << 1 <<'\n';
    else cout << 2 <<'\n';

    for( int q= 1; q<= Q; ++q )
    {
        int x; cin >> x;
        if( a[x] == 0 ) { a[x]= 1; dem[ nhom[a[x]] ]++; }
        else { a[x]= 0; dem[ nhom[a[x]] ]--; }

        for( int i= 1; i<= n; ++i ) dem[ nhom[i] ]++;
        if( dem[0] + dem[1] + dem[2] <= 1 ) cout << 0 <<'\n';
        else if( dem[0] == 0 || dem[1] == 0 || dem[2] == 0 ) cout << 1 <<'\n';
        else cout << 2 <<'\n';
    }
}


int main()
{
    ios_base::sync_with_stdio( 0 );
    cin.tie( 0 ); cout.tie( 0 );
    freopen("SOCKS.INP","r",stdin);
    freopen("SOCKS.OUT","w",stdout);

    cin >> n >> Q;
    for( int i= 1; i<= n; ++i ) cin >> a[i];
    for( int i= 1; i<= n-1; ++i )
    {
        int x, y; cin >> x >> y;
        adj[x].push_back( y );
        adj[y].push_back( x );
    }


    if( checkthang() == true ) solvethang();
    else if( checkchut() == true ) solvechut();
    else solvethang();

    return 0;
}
