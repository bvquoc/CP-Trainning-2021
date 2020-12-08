#include<bits/stdc++.h>

#define N 2005

#define fi first

#define sc second

using namespace std;

typedef pair< int , int > II;

typedef pair< II, int > III;

int moder = (int)1e6 + 3;

int amount , limit;

int date[N];

int schedule[N][N];

void solve()
{
    schedule[0][0] = 1;

    for(int date_now =1 , run_to = amount*2 ; date_now <= run_to ; date_now++){

        schedule[date_now][0] = schedule[date_now-1][1];

        for(int inside = 1; inside <= amount ; inside++){

            schedule[date_now][inside] = schedule[date_now-1][inside+1];

            schedule[date_now][inside] += schedule[date_now-1][inside-1];

            schedule[date_now][inside] %= moder;
        }
    }

    printf("%d", schedule[amount*2][0] );

}

int main()
{
    //freopen("main.inp", "r", stdin );

    freopen("Mine.inp", "r", stdin );

    freopen("Mine.out", "w", stdout );

    scanf("%d %d", &amount , &limit );

    for(int i =1 , run_to = 2*amount ;i <= run_to; i++)

        scanf("%d", &date[i] );

    solve();
}

