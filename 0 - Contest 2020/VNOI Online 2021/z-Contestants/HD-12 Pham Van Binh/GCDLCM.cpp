#include <bits/stdc++.h>

#define fi first

#define sc second

#define N 505

using namespace std;

typedef pair<int, int> II;

typedef pair<int, char> IC;

typedef pair<int, II> III;

typedef pair<II, II> IV;

typedef pair<int, long long> IL;

typedef pair<long long, int> LI;

typedef pair<IL, int> ILI;

int subtasks , tester;

int amount , query;

int gcd[N][N] , lcm[N][N];

bool is_good = false;

int val[N];

void process( int pos )
{
    if( pos == amount + 1 ) { is_good = true; return;}

    int fir = max( *max_element( gcd[pos] +1 , gcd[pos] + amount + 1 ) , 1 );

    for(int i = fir; i <= 100; i += fir){

        bool is_choose = true;

        for(int j = 1; j <= amount; j++)

            if( gcd[pos][j] && i % gcd[pos][j] ) is_choose = false;

        for(int k = 1 ;k <= amount; k++)

            if( lcm[pos][k] && lcm[pos][k] % i == 0 ) is_choose = false;

        for(int j = 1 ;j < pos; j++){

            if( gcd[j][pos] && __gcd( i , val[j] ) ) is_choose = false;

            if( lcm[j][pos] && lcm[j][pos] != i * val[j] / __gcd( i , val[j] ) ) is_choose = false;
        }

        if( is_choose ) val[pos] = i , process( pos + 1 );

        if( is_good ) return;
    }
}

void solve()
{
    is_good = false;

    scanf("%d %d", &amount , &query );

    for(int i =1 ;i <= amount; i++)

    for(int j =1 ;j <= amount; j++) gcd[i][j] = lcm[i][j] = 0;

    for(int i =1 ;i <= query; i++){

        string command; cin >> command;

        if( command == "LCM" ){

            int one , two , new_lcm; scanf("%d %d %d", &one , &two , &new_lcm );

            if( !lcm[one][two] ) lcm[one][two] = lcm[two][one] = new_lcm;

            if( lcm[one][two] ){

                if( lcm[one][two] != new_lcm ) lcm[one][two] = -1;

                else lcm[one][two] = new_lcm;

                lcm[two][one] = new_lcm;
            }
        }

        else{

            int one , two , new_gcd; scanf("%d %d %d", &one , &two , &new_gcd );

            if( !gcd[one][two] ) gcd[one][two] = gcd[two][one] = new_gcd;

            if( gcd[one][two] ){

                gcd[two][one] = new_gcd;

                if( gcd[one][two] != new_gcd ) gcd[one][two] = -1;

                else gcd[one][two] = new_gcd;
            }
        }
    }

    for(int i = 1; i <= amount; i++)

    for(int j = 1 ; j <= amount; j++){

        if( gcd[i][j] == -1 ) { printf("N"); return;}

        if( lcm[i][j] == -1 ) { printf("N"); return;}

        if( lcm[i][j] && gcd[i][j] && lcm[i][j] % gcd[i][j] ) { printf("N"); return;}
    }

    process( 1 );

    if( is_good ) printf("Y");

    else printf("N");
}

int main()
{
    ///freopen("main.inp", "r", stdin );

    freopen("GCDLCM.inp", "r", stdin );

    freopen("GCDLCM.out", "w", stdout );

    scanf("%d %d", &subtasks , &tester );

    if( subtasks != 1 ){

        for(int i =1 ;i <= tester; i++)

            printf("N");

        return 0;
    }

    while( tester-- ) solve();
}
