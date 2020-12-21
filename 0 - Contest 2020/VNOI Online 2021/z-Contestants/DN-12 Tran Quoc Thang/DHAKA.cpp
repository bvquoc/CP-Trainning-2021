#include<bits/stdc++.h>
using namespace std;

int n ,m ,k ,l;
int de[100005];
long long f[100005][35];
int x ,y ,z;

struct ii
{
    int x ;
    int y ;
    long long z;
};
vector<ii> a[100005];

struct ss
{
    bool operator() ( ii a, ii b )
    {
        return a.z > b.z;
    }
};

priority_queue<ii ,vector<ii> ,ss> q;

bool kt( int x )
{
    int res = 0;
    while(x)
    {
        if( 1&x ) res++;
        x>>=1;
    }
    return res >= l;
}

void dj( int s )
{
    f[s][de[s]] = 0;
    q.push({s ,de[s] ,0});
    while( q.size() )
    {
        ii u = q.top();
        q.pop();
        if( f[u.x][u.y] < u.z ) continue;
        if( u.x == n && kt(u.y) )
        {
            cout<<u.z;
            return;
        }
        for( ii v : a[u.x] )
        {
            int te = (u.y|de[v.x]);
            if( f[v.x][te] <= u.z+v.z ) continue;
            f[v.x][te] = u.z+v.z;
            q.push({v.x ,te ,u.z+v.z});
        }
    }
    cout<<-1;
}

main()
{
    freopen("DHAKA.inp" ,"r" ,stdin);
    freopen("DHAKA.out" ,"w" ,stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> k >> l;
    for( int i = 1 ; i <= n ;i++ )
    {

        cin >> x;
        for( int j = 1 ;j <= x ;j++ )
        {
            cin >> y;
            de[i] |= (1<<(y-1));
        }
    }
    for( int i = 1 ; i <= m ;i++ )
    {
        cin >> x >> y >> z;
        a[x].push_back({y ,0 ,z});
        a[y].push_back({x ,0 ,z});
    }
    for( int i = 1 ; i <= n ;i++ )
    {
        for( int j = 0 ; j < (1<<k) ;j++ )
        {
            f[i][j] = 1000000000000000000;
        }
    }
    dj(1);
}
