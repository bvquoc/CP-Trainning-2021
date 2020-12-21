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

char fir[N] , sec[N] , thir[N];

char res_row[1005] , lame_row[1005]; int min_length = (int)1e9 , lame_length = 0;

int length_fir , length_sec , length_thir;

void lame_process( int one , int two , int three )
{
    if( lame_length >= min_length ) return;

    if( three == length_thir + 1 ) return;

    if( one == length_fir + 1 && two == length_sec + 1 ){

        min_length = lame_length;

        for(int i =1 ;i <= min_length; i++)

            res_row[i] = lame_row[i];

        return;
    }

    int nex_one = one , nex_two = two , nex_three = three;

    if( one <= length_fir ){

        lame_row[++lame_length] = fir[one];

        nex_one++ , nex_two += sec[two] == fir[one] , nex_three += ( thir[three] == fir[one] );

        lame_process( nex_one , nex_two , nex_three );

        lame_length--;
    }

    if( two <= length_sec ){

        lame_row[++lame_length] = sec[two];

        nex_one = one + ( fir[one] == sec[two] ) , nex_two = two +1 , nex_three = three + ( thir[three] == sec[two] );

        lame_process( nex_one , nex_two , nex_three );

        lame_length--;
    }
}

void lame_solve()
{
    lame_process( 1 , 1, 1 );

    if( min_length == (int)1e9 ) { printf("TRETRAU"); return;}

    printf("%d\n", min_length );

    for(int i =1 ;i <= min_length; i++)

        printf("%c", res_row[i] );
}

int mark[N][N][N] , res[N][N][N];

int cal( int one , int two, int three )
{
    if( three == length_thir + 1 ) return (int)1e9;

    if( one == length_fir + 1 && two == length_sec + 1 ) return 0;

    if( mark[one][two][three] ) return res[one][two][three];

    mark[one][two][three] = 1;

    res[one][two][three] = (int)1e9;

    int nex_one , nex_two , nex_three;

    if( one <= length_fir ){

        nex_one = one + 1 , nex_two = two + ( sec[two] == fir[one] ) , nex_three = three + ( thir[three] == fir[one] );

        res[one][two][three] = min( res[one][two][three] , cal( nex_one , nex_two , nex_three ) + 1 );
    }

    if( two <= length_sec ){

        nex_one = one + ( fir[one] == sec[two] ) , nex_two = two + 1 , nex_three = three + ( thir[three] == sec[two] );

        res[one][two][three] = min( res[one][two][three] , cal( nex_one , nex_two , nex_three ) + 1 );
    }

    return res[one][two][three];
}

void better_solve()
{
    cal( 1 , 1 , 1 );

    if( res[1][1][1] == (int)1e9 ){ printf("TRETRAU"); return;}

    printf("%d\n", res[1][1][1] );

    int one =1 , two = 1 , three = 1;

    for(int i = 1; i <= res[1][1][1]; i++){

        int nex_one , nex_two , nex_three;

        if( one <= length_fir ){

            nex_one = one + 1 , nex_two = two + ( sec[two] == fir[one] ) , nex_three = three + ( thir[three] == fir[one] );

            if( res[one][two][three] == res[nex_one][nex_two][nex_three] + 1 ){

                printf("%c", fir[one] );

                one = nex_one , two = nex_two , three = nex_three;

                continue;
            }
        }

        if( two <= length_sec ){

            nex_one = one + ( fir[one] == sec[two] ) , nex_two = two + 1 , nex_three = three + ( thir[three] == sec[two] );

            if( res[one][two][three] == res[nex_one][nex_two][nex_three] + 1 ){

                printf("%c", sec[two] );

                one = nex_one , two = nex_two , three = nex_three;

                continue;
            }
        }
    }
}

void solve()
{
    length_fir = strlen( fir + 1 ) , length_sec = strlen( sec + 1 ) , length_thir = strlen( thir + 1 );

    if( length_fir + length_sec <= 20 ) lame_solve();

    else better_solve();
}

int main()
{
    ///freopen("main.inp", "r", stdin );

    freopen("XCKLT.inp", "r", stdin );

    freopen("XCKLT.out", "w", stdout );

    scanf("%s %s %s", fir + 1 , sec + 1 , thir + 1 );

    solve();
}
