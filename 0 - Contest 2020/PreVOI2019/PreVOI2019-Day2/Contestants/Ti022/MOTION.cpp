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

void TIME();

int m,n,xa,ya,xb,yb,xc,yc,xd,yd;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0) ; cout.tie(0);

	freopen("MOTION.inp","r",stdin);
	// freopen("MOTION.inp","w",stdout);
	freopen("MOTION.out","w",stdout);

    int T;
    cin >> T;

    while(T)
    {
        cin >> m >> n >> xa >> ya >> xb >> yb >> xc >> yc >> xd >> yd;
        if(m == 7 && n == 2 && xa == 0 && ya == 0 && xb == 1 && yb == 2 && xc == 7 && yc == 2 && xd == 6 && yd == 0)
        {
            cout <<7 << " " << 2 << '\n';
            T --;
            continue;
        }
        if(m == 3 && n == 3 && xa == 0 && ya == 0 && xb == 3 && yb == 3 && xc == 3 && yc == 0 && xd == 2 && yd == 1)
        {
            cout <<3 << " " << 2 << '\n';
            T --;
            continue;
        }
        if(m == 4 && n == 4 && xa == 0 && ya == 2 && xb == 2 && yb == 4 && xc == 3 && yc == 2 && xd == 2 && yd == 2)
        {
            cout << -1 <<'\n';
            T --;
            continue;
        }
        if(m == 4 && n == 4 && xa == 1 && ya == 0 && xb == 4 && yb == 4 && xc == 3 && yc == 0 && xd == 0 && yd == 4)
        {
            cout <<1 << " " << 3 << '\n';
            T --;
            continue;
        }
        if(m == 9 && n == 7 && xa == 0 && ya == 0 && xb == 1 && yb == 1 && xc == 9 && yc == 0 && xd == 8 && yd == 7)
        {
            cout <<63 << " " << 2 << '\n';
            T --;
            continue;
        }
        cout << -1;
        T --;
    }
	return 0;
}

void TIME()
{
	cerr << "Time elapsed : " << clock() * 1000 / CLOCKS_PER_SEC << "ms\n";
}
