#include <bits/stdc++.h>

#define fi first

#define sc second

#define N 1000005

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

int amount , forecast ;

int from[N] , to[N] , min_temp = (int)1e9;

int nest[N] , mem = 0;

int max_nex[N];

void prepare()
{
    for(int i = 1; i <= amount; i++){

        nest[++mem] = from[i];

        nest[++mem] = to[i];

        nest[++mem] = to[i] + 1;
    }

    nest[++mem] = min_temp;

    sort( nest + 1 , nest + mem + 1 );

    for(int i =1 ;i <= amount; i++){

        from[i] = lower_bound( nest + 1 , nest + mem + 1, from[i] ) - nest;

        to[i] = lower_bound( nest +1 , nest + mem + 1 , to[i] ) - nest;

        max_nex[ from[i] ] = max( max_nex[ from[i] ] , to[i] );
    }
}

void solve()
{
    prepare();

    int fir = lower_bound( nest + 1, nest + mem + 1 , min_temp ) - nest;

    int cur = 1 , res = 0;

    while( nest[fir] <= (int)1e5 ){

        int max_now = 0;

        for(int j = cur ; j <= fir; j++)

            max_now = max( max_now , max_nex[j] );

        if( max_now < fir ) { printf("-1"); return;}

        cur = fir;

        res++ , fir = lower_bound( nest + 1 , nest + mem + 1 , nest[ max_now ] + 1 ) - nest;
    }

    printf("%d", res );
}

int main()
{
    ///freopen("main.inp", "r", stdin );

    freopen("COOLMAC.inp", "r", stdin );

    freopen("COOLMAC.out", "w", stdout );

    scanf("%d", &amount );

    for(int i =1 ;i <= amount; i++)

        scanf("%d %d", &from[i] , &to[i] );

    scanf("%d", &forecast );

    for(int i =1 ;i <= forecast; i++){

        int temp; scanf("%d", &temp );

        min_temp = min( min_temp , temp );
    }

    solve();
}
