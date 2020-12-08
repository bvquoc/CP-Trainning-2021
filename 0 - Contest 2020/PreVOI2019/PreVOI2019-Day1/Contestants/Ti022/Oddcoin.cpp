/*
 ──────────────────────────────────────
 ─▄▄▄───────────▄▄▄▄▄▄▄────────────────
 █▀░▀█──────▄▀▀▀░░░░░░░▀▀▄▄────────────
 █░░░░█───▄▀░░░░░░░░░░░░░░░▀▄───────▄▄▄
 █▄░░░▀▄▄▀░░██░░░░░░░░░░░░░░▀█────█▀▀░█
 ─█░░░░█▀░░░▀░░░░░░░░██░░░░░░▀█─▄█░░░░█
 ─▀█░░▄█░░░░░░░▄▄▄░░░░▀░░░░░░░███░░░░█▀
 ──█▄░█░░░░░▄███████▄░░░░░░░░░█▀░░░░▄▀─
 ──▀█░█░░░░▄██████████░░░░░░░▄█░░░░▄▀──
 ───███░░░░███████████░░░░░░▄█░░░░█▀───
 ────█░░░░░██████████▀░░░░░░█░░░░█▀────
 ────█░░░░░░▀███████▀░░░░░░░█▄▄▄▀──────
 ────█░░░░░░░░▀▀▀▀░░░░░░░░░░░▀█────────
 ────█░░░░░░░░░░░░░░░░░░░░░░░░█────────
 ────█░░░░░░░░░░░░░░░░░░░░░░░░█────────
 ────█░░░░░░░░░░░░░░░░░░░░░░░░█────────
 ──────────────────────────────────────
 */
#include <bits/stdc++.h>
#define LL long long
#define ii pair<int, int>
#define jj pair<int, pair< int , int > >
#define f first
#define s second
using namespace std ;
const int oo = 2 * 1e9 + 10;
void TIME();

int Q;
int A[] = {0,1,3,5,10,30,50,100,300,500,1000,3000,5000,10000,30000,50000};
int B[18];
int memo[5000005];

int solve(int i, int tt)
{
    if(i > tt)
    {
        return oo;
    }
    if(i == tt)
    {
        return 0;
    }
    if(memo[i] != -1)
    {
        return memo[i];
    }
    int Cur = oo;
    for(int j = 1 ; j <= 16 ; j ++)
    {
        Cur = min(Cur, solve(i+B[j], tt) + 1);
    }
    return memo[i] = Cur;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0) ; cout.tie(0);

	freopen("Oddcoin.inp","r",stdin);
	// freopen("Oddcoin.inp","w",stdout);
    freopen("Oddcoin.out","w",stdout);

    cin >> Q;

    while(Q)
    {
        int x, t;
        cin >> x >> t;
        if(t % x == 0)
        {
            cout << t / x << '\n';
            Q --;
            continue;
        }
        if(t % 500000 == 0)
        {
            cout << t / x << '\n';
            Q --;
            continue;
        }
        for(int i = 1 ;  i <= 15 ; i ++)
        {
            B[i] = A[i];
        }
        B[16] = x;
        memset(memo, -1, sizeof(memo));
        cout << solve(0,t) << '\n';
        Q --;
    }

    // TIME();
	return 0;
}

void TIME()
{
	cerr << "Time elapsed : " << clock() * 1000 / CLOCKS_PER_SEC << "ms\n";
}
