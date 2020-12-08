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
const int mod = 1e6 + 3;
void TIME();

int n, m;
int A[200010];
int B[200010];
int C[200010];
int memo[2005][2005][2];
stack <ii> CK;
int Ans;

int solve(int i , int c, bool ok)
{
    if(i == 2 * n + 1)
    {
        return ((c == n) & (ok == 0));
    }
    if(memo[i][c][ok] != -1)
    {
        return memo[i][c][ok];
    }
    int Cur = 0;
    Cur = (Cur + solve(i+1,c + 1, ok)) % mod;
    Cur = (Cur + solve(i+1,c, ok | (i - c >  c))) % mod;
    return memo[i][c][ok] = Cur % mod;
}
void SNP(int j)
{
    if(j == 2 * n + 1)
    {
        while(!CK.empty())
        {
            CK.pop();
        }
        int Res = 0;
        int id = 1;
        for(int i = 1 ; i <= 2 * n ; i ++)
        {
            if(B[i])
            {
                if(CK.empty())
                {
                    return;
                }
                else
                {
                    if(A[i] - CK.top().s > m )
                    {
                        return;
                    }
                    CK.pop();
                }
            }
            else
            {
                if(id == n + 1)
                {
                    return;
                }
                else
                {
                    CK.push(ii(id,A[i]));
                    id ++;
                }
            }

        }
        if(!CK.empty()) return;
        Ans ++;
        Ans %= mod;
        return;
    }
    else
    {
        for(int i = 0 ; i < 2; i ++)
        {
            B[j] = i;
            SNP(j+1);
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0) ; cout.tie(0);

	freopen("mine.inp","r",stdin);
	// freopen("mine.inp","w",stdout);
	freopen("mine.out","w",stdout);

    cin >> n >> m;
    for(int i = 1 ; i <= 2 * n; i ++)
    {
        cin >> A[i];
    }
    if(m == 10000000)
    {
        memset(memo, -1, sizeof(memo));
        cout << solve(1,0,0) % mod;
        exit(0);
    }
    if(n <= 20)
    {
        SNP(1);
        cout << Ans % mod;
        exit(0);
    }
	return 0;
}

void TIME()
{
	cerr << "Time elapsed : " << clock() * 1000 / CLOCKS_PER_SEC << "ms\n";
}
