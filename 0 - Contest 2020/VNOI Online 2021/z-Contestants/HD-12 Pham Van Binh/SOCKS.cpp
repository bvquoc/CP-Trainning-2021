#include <bits/stdc++.h>

#define fi first

#define sc second

#define N 500005

#define inf 1000000000000000001

using namespace std;

typedef pair<int, int> II;

typedef pair<int, char> IC;

typedef pair<int, II> III;

typedef pair<II, II> IV;

typedef pair<int, long long> IL;

typedef pair<long long, int> LI;

typedef pair<long long , long long> LL;

typedef pair<IL, int> ILI;

int amount , query;

int col_led[N] , is_odd[N];

vector<int> graph_map[N];

int res = 0;

void DFS( int root , int pre )
{
    int cur = 0;

    for(int connect : graph_map[root] )

    if( connect != pre ){

        DFS( connect , root );

        cur += is_odd[connect];
    }

    res += cur / 2;

    if( cur == 0 ) is_odd[root] = col_led[root];

    else{

        if( cur % 2 ) is_odd[root] = 1;

        else is_odd[root] = 0;
    }
}

void sub3()
{
    res = 0 , DFS( 1 , 0 );

    printf("%d\n", res + is_odd[1] );

    for(int i = 1; i <= query; i++){

        int pos; scanf("%d", &pos );

        col_led[pos] = 1 - col_led[pos];

        res = 0 , DFS( 1 , 0 );

        printf("%d\n", res + is_odd[1] );
    }
}

int mark[N] , counter[N];

void sub2_DFS( int root , int pre )
{
    for(int connect : graph_map[root] )

    if( connect != pre ){

        mark[connect] = mark[root];

        sub2_DFS( connect , root );
    }
}

void sub2()
{
    int pos = 0;

    for(int i =1 ;i <= amount; i++)

        if( graph_map[i].size() == 3 ) pos = i;

    int run = 0;

    for(int connect : graph_map[pos] )

        run++ , mark[connect] = run , DFS( connect , pos );

    for(int i = 1; i <= amount; i++)

        if( i != pos ) counter[ mark[i] ] += col_led[i];

    int cur = 0;

    for(int i =1 ;i <= 3; i++)

        cur += ( counter[i] > 0 );

    if( cur == 0 ) cur += col_led[pos];

    printf("%d\n", ( cur + 1 ) / 2 );

    for(int i =1 ;i <= query; i++){

        int change_pos; scanf("%d", &change_pos );

        if( change_pos == pos ) col_led[pos] = 1 - col_led[pos];

        else{

            counter[ mark[change_pos] ] -= col_led[ change_pos ];

            col_led[ change_pos ] = 1 - col_led[ change_pos ];

            counter[ mark[change_pos] ] += col_led[ change_pos ];
        }

        cur = 0;

        for(int j =1 ;j <= 3; j++)

            cur += ( counter[j] > 0 );

        if( cur == 0 ) cur += col_led[pos];

        printf("%d\n", ( cur + 1 ) / 2 );
    }
}

void sub1()
{
    int cur = 0;

    for(int i =1 ;i <= amount; i++)

        cur += col_led[i];

    printf("%d\n", cur > 0 );

    for(int i =1 ;i <= query; i++){

        int pos ; scanf("%d", &pos );

        cur -= col_led[pos] , col_led[pos] = 1 - col_led[pos];

        cur += col_led[pos];

        printf("%d\n", cur > 0 );
    }
}

void solve()
{
    int max_siz = 0;

    int three = 0;

    for(int i = 1;i <= amount; i++){

        max_siz = max( max_siz , (int)graph_map[i].size() );

        three += ( graph_map[i].size() == 3 );
    }

    if( max_siz == 2 ) sub1();

    else if( max_siz == 3 && three == 1 ) sub2();

    else sub3();
}

int main()
{
    ///freopen("main.inp", "r", stdin );

    freopen("SOCKS.inp", "r", stdin );

    freopen("SOCKS.out", "w", stdout );

    scanf("%d %d", &amount , &query );

    for(int i =1 ;i <= amount; i++)

        scanf("%d", &col_led[i] );

    for(int i =1 ;i < amount; i++){

        int from , to; scanf("%d %d", &from , &to );

        graph_map[ from ].push_back( to );

        graph_map[ to ].push_back( from );
    }

    solve();
}

