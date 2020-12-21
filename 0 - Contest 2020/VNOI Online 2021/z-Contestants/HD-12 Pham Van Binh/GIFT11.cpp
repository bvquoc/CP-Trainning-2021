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

int moder = 998244353;

int amount;

int numbers[N];

int row[N] , pow_ten[15];

int mask_tester;

void lame_solve()
{
    pow_ten[0] = 1 , pow_ten[1] = 10;

    int res = 0;

    for(int i =1 ;i <= amount; i++) row[i] = i;

    do{

        int remain = 0;

        for(int i =1 ; i <= amount; i++){

            int now = (int)log10( numbers[ row[i] ] ) + 1;

            remain = ( remain * pow_ten[ now % 2 ] + numbers[ row[i] ] ) % 11;
        }

        res += ( remain == 0 );
    }

    while( next_permutation( row +1 , row + amount + 1 ) );

    printf("%d\n", res );
}

void all_even()
{
    int par = 0;

    for(int i =1 ;i <= amount; i++)

        par = ( par + numbers[i] ) % 11;

    if( par == 0 ){

        int res = 1;

        for(int i = 1 ;i <= amount; i++)

            res = (long long)res * i % moder;

        printf("%d\n", res );

        return;
    }

    printf("0\n");
}

void better_solve()
{

}

void solve()
{
    scanf("%d", &amount );

    for(int i =1 ;i <= amount; i++)

        scanf("%d", &numbers[i] );

    if( mask_tester <= 8 && amount <= 10 ) lame_solve();

    else all_even();
}

int main()
{
    freopen("main.inp", "r", stdin );

    int tester; scanf("%d", &tester );

    mask_tester = tester;

    while( tester-- ) solve();
}

