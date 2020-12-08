#include<bits/stdc++.h>

#define N 1000005

#define fi first

#define sc second

using namespace std;

typedef pair< int , int > II;

typedef pair< II, int > III;

int coin_row[20] , mem = 0;

void prepare()
{

    int one = 1 , three = 3 , five = 5;

    for(int i =1 ;i<= 5; i++){

        coin_row[++mem] = one;

        coin_row[++mem] = three;

        coin_row[++mem] = five;

        one *= 10 , three *= 10 , five *= 10;
    }

}

int find_result( int value )
{

    int start = mem;

    int coin_used = 0;

    while( value ){

        while( value < coin_row[start] ) start--;

        int now = value / coin_row[start];

        coin_used += now;

        value -= coin_row[start]*now;
    }

    return coin_used;

}

void solve()
{

    int extra , need;

    scanf("%d %d", &extra , &need );

    int result = (int)1e9;

    for(int i = 0, run_to = min( need / extra , (int)10e6 / tester ); i <= run_to ; i++){

        int need_now = need - extra*i;

        result = min( result, i + find_result( need_now ) );
    }

    printf("%d\n", result );

}

int main()
{
    //freopen("main.inp", "r", stdin );

    freopen("Oddcoin.inp", "r", stdin );

    freopen("Oddcoin.out", "w", stdout );

    prepare();

    int tester;

    scanf("%d", &tester );

    while( tester-- ) solve();
}

