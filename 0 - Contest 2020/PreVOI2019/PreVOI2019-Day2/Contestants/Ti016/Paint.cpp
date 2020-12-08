#include<bits/stdc++.h>

#define N 1000005

#define fi first

#define sc second

using namespace std;

typedef pair< int , int> II;

typedef pair< long long , int > LI;

char result_row[N];

int root[N];

int amount;

int head[N];

int main()
{
    //freopen("main.inp", "r", stdin );

    freopen("Paint.inp", "r", stdin );

    freopen("Paint.out", "w", stdout );

    scanf("%d", &amount );

    int command , spot = 0;

    for(int i =1 ;i <= amount; i++){

        scanf("%d", &command );

        if( command == 1 ){

            char color;

            cin >> color;

            spot++;

            if( head[ color - 'a' ] == 0 ){

                head[ color - 'a' ] = spot;

                root[ spot ] = spot;
            }

            else

                root[spot] = root[ head[ color - 'a' ] ];
        }

        else{

            char old_color , new_color;

            cin >> old_color >> new_color;

            if( head[ old_color - 'a' ] != 0 ){

                if( head[ new_color - 'a' ] == 0 ){

                    head[ new_color - 'a' ] = head[ old_color - 'a' ];

                    head[ old_color - 'a' ] = 0;
                }

                else{

                    root[ head[ old_color - 'a' ] ] = head[ new_color - 'a' ];

                    head[ old_color - 'a' ] = 0;
                }
            }
        }
    }

    for(int i = 0 ; i < 26 ; i++){

        if( head[ i ] != 0 )

            result_row[ head[i] ] = i + 'a';
    }

    for(int i =1 ;i <= spot; i++)

        result_row[ i ] = result_row[ root[i] ];

    printf("%s", result_row +1 );
}

