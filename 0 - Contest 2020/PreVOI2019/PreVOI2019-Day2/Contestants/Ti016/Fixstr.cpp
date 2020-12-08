#include<bits/stdc++.h>

#define N 2005

#define fi first

#define sc second

using namespace std;

typedef pair< int , int> II;

typedef pair< long long , int > LI;

char bracket[1000005];

char changed_bracket[N][N];

char command[1000005];

int command_spot[1000005];

int length;

int query;

void solve_command_C( int spot )
{
    bracket[ spot ] = ( bracket[spot] == '(' ) ? ')' : '(';
}

void solve_command_Q()
{

    int from , to;

    scanf("%d %d", &from , &to );

    int result = 0;

    int odd = 0;

    for(int i = from; i <= to ; i++){

        if( bracket[i] == '(' ) odd++;

        else odd--;

        if( odd < 0 ) result++ , odd = 0;
    }

    printf("%d\n", result + odd );
}

void solve_command_U()
{

    int spot;

    scanf("%d", &spot );

    for(int i = 1; i <= length; i++)

        bracket[i] = changed_bracket[spot-1][i];

}

int main()
{
    //freopen("main.inp", "r", stdin );

    freopen("Fixstr.inp", "r", stdin );

    freopen("Fixstr.out", "w", stdout );

    scanf("%s", bracket +1 );

    scanf("%d", &query );

    length = strlen( bracket +1 );

    for(int i =1 ;i <= query; i++){

        cin >> command[i];

        if( command[i] == 'C' ){

            scanf("%d", &command_spot[i] );

            solve_command_C( command_spot[i] );
        }

        else if( command[i] == 'Q' )

            solve_command_Q();

        else solve_command_U();

        for(int j =1 ;j <= length; j++)

            changed_bracket[i][j] = bracket[j];
    }
}

