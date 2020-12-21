#include <bits/stdc++.h>

#define fi first

#define sc second

#define N 5005

using namespace std;

typedef pair<int, int> II;

typedef pair<int, char> IC;

typedef pair<int, II> III;

typedef pair<II, II> IV;

typedef pair<int, long long> IL;

typedef pair<long long, int> LI;

typedef pair<IL, int> ILI;

int moder = 998244353;

int subtasks;

int amount , path;

vector<II> graph_map[N];

II dist[N][N] ;int mark[N];

III edge[N];

int sums[N] , nex_sums[N];

void DIJ( int start )
{
    set<II> wait_row; wait_row.clear();

    for(int i =1 ;i <= amount; i++) dist[start][i] = II( (int)1e9 , 0 );

    dist[start][start] = II( 0 , 1 );

    wait_row.insert( II( 0 , start ) );

    mark[start] = start;

    while( !wait_row.empty() ){

        int root = (*wait_row.begin()).sc;

        wait_row.erase( *wait_row.begin() );

        for(II connect : graph_map[root] )

        if( mark[connect.fi] != start ){

            mark[connect.fi] = start;

            dist[start][connect.fi] = II( dist[start][root].fi + connect.sc , dist[start][root].sc );

            wait_row.insert( II( dist[start][connect.fi].fi , connect.fi ) );
        }

        else if( dist[start][connect.fi].fi > dist[start][root].fi + connect.sc ){

            wait_row.erase( II( dist[start][connect.fi].fi , connect.fi ) );

            dist[start][connect.fi].fi = dist[start][root].fi + connect.sc;

            wait_row.insert( II( dist[start][connect.fi].fi , connect.fi ) );
        }

        else if( dist[start][connect.fi].fi == dist[start][root].fi + connect.sc ){

            dist[start][connect.fi].sc += dist[start][root].sc;

            dist[start][connect.fi].sc %= moder;
        }
    }
}

int res[N];

void lame_solve()
{
    for(int i = 1; i <= path; i++){

        int from = edge[i].sc.fi , to = edge[i].sc.sc;

        if( dist[from][to].fi != edge[i].fi ) { printf("0\n"); continue;}

        int counter = 0;

        for(int j = 1 ;j <= amount; j++)

        for(int k =1 ;k <= amount; k++)

            if( dist[j][from].fi + edge[i].fi + dist[to][k].fi == dist[j][k].fi )

                counter += dist[j][from].sc * dist[to][k].sc;

        printf("%d\n", counter );
    }
}

void sec_sub()
{
    for(int i =1 ;i <= amount; i++) sums[i] = nex_sums[i] = 1;

    for(int i =1 ;i <= amount; i++){

        for(int j = 1 ;j < i ; j++)

            sums[i] += dist[j][i].sc , sums[i] %= moder;

        for(int j = i + 1 ;j <= amount; j++)

            nex_sums[i] += dist[i][j].sc , nex_sums[i] %= moder;
    }

    for(int i = 1;i <= path; i++){

        int from = edge[i].sc.fi , to = edge[i].sc.sc;

        if( dist[from][to].fi != edge[i].fi ) { printf("0\n"); continue;}

        printf("%d\n", (long long)sums[from] * nex_sums[to] % moder );
    }
}

void solve()
{
    for(int i =1 ;i <= amount; i++) DIJ( i );

    if( subtasks == 2 || subtasks == 4 ) sec_sub();

    else lame_solve();
}

int main()
{
    ///freopen("main.inp", "r", stdin );

    freopen("CAULUONG.inp", "r", stdin );

    freopen("CAULUONG.out", "w", stdout );

    scanf("%d", &subtasks );

    scanf("%d %d", &amount , &path );

    for(int i = 1; i <= path; i++){

        int from , to , length; scanf("%d %d %d", &from , &to , &length );

        edge[i] = III( length , II( from , to ) );

        graph_map[ from ].push_back( II( to , length ) );
    }

    solve();
}
