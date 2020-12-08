#include<bits/stdc++.h>

#define N 1000005

#define fi first

#define sc second

using namespace std;

typedef pair< int , int > II;

typedef pair< II, int > III;

int amount , query;

int start_high[N];

void solve_command_one()
{

    int from , to , value;

    scanf("%d %d %d", &from , &to , &value );

    for(int i = from ;i <= to; i++)

        start_high[i] += value;

}

int find_result( int from , int to , int before_high )
{

    if( from == to ) return start_high[from] - before_high;

    int smallest = (int)1e9 ;

    for(int i = from ;i <= to; i++)

        smallest = min( smallest , start_high[i] );

    int total = 0;

    int spot = from-1;

    for(int i = from ; i <= to; i++){

        if( start_high[i] == smallest ){

            if( i > spot +1 ){

                total += find_result( spot +1 , i-1, smallest );
            }

            spot = i;
        }
    }

    if( to > spot +1 ) total += find_result( spot +1 , to , smallest );

    return total + smallest;
}

void solve_command_two()
{

    int from , to;

    scanf("%d %d", &from , &to );

    printf("%d\n", find_result( from , to , 0 ) );

}

int main()
{
    //freopen("main.inp", "r", stdin );

    freopen("Construct.inp", "r", stdin );

    freopen("Construct.out", "w", stdout );

    scanf("%d %d", &amount , &query );

    for(int i =1 ;i <= amount; i ++)

        scanf("%d", &start_high[i] );

    int command;

    for(int i =1 ;i <= query; i++){

        scanf("%d", &command );

        if( command == 1 ) solve_command_one();

        else solve_command_two();
    }
}

