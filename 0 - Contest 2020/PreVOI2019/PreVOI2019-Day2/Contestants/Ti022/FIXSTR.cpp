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
struct Tnode
{
    char a;
    int b, k, l , r;
};
void TIME();

string x[1000010];
int n, m;
Tnode TV[1000010];
int id ;
int main()
{
	ios_base::sync_with_stdio(false);
	// cin.tie(0) ; cout.tie(0);

	freopen("FIXSTR.inp","r",stdin);
	// freopen("FIXSTR.inp","w",stdout);
	freopen("FIXSTR.out","w",stdout);

    cin >> x[0];
    n = x[0].size();
    cin >> m;
    bool tf = 0;
    for(int i = 1 ; i <= m ; i ++)
    {
        cin >> TV[i].a ;
        if(TV[i].a == 'C')
        {
            cin >> TV[i].b;
        }
        if(TV[i].a == 'Q')
        {
            cin >> TV[i].l >> TV[i].r ;
        }
        if(TV[i].a == 'U')
        {
            tf = 1;
            cin >> TV[i].k;
        }
    }
    if(tf == 1)
    {
        for(int i = 1 ; i <= m ; i ++)
        {
            // cout << i <<'\n';
            if(TV[i].a == 'C')
            {
                // cout <<".";
                int b = TV[i].b;
                id ++;
                x[id] = x[id-1];
                if(x[id][b-1] == ')')
                {
                    x[id][b-1] = char(40);
                }
                else
                {
                    x[id][b-1] = char(41);
                }
                // cout << id <<" " << x[id] <<'\n';
            }
            if(TV[i].a == 'Q')
            {
                id ++;
                x[id] = x[id-1];
                int l, r;
                l = TV[i].l;
                r = TV[i].r;
                // cout <<id <<" " << x[id] << '\n';
                int c = 0, add = 0;
                int st = l - 1;
                int ed = r - 1;
                int len = ed - st + 1;
                int Ans = 0;
                // cout << st <<" " << ed <<" " << len << endl;
                for(int j = st ; j <= ed ; j ++)
                {
                    if(x[id][j] == ')')
                    {
                        if(j - st - c + 1> c)
                        {
                            Ans ++;
                            c ++;
                            add ++;
                        }
                    }
                    else
                    {
                        c ++;
                    }
                    // cout << j <<"_" << c <<" " << Ans << endl;
                }
                Ans += c - (len - c + add);
                cout << Ans << '\n';
            }
            if(TV[i].a == 'U')
            {
                int k = TV[i].k;
                id ++;
                x[id] = x[k - 1];
                // cout << id <<" "<< x[id] << endl;
            }
        }
    }
    else
    {
        string y = x[0];
        for(int i = 1 ; i <= m ; i ++)
        {
            if(TV[i].a == 'C')
            {
                int b = TV[i].b;
                if(y[b-1] == ')')
                {
                    y[b-1] = char(40);
                }
                else
                {
                    y[b-1] = char(41);
                }
            }
            else
            {
                int l, r;
                l = TV[i].l;
                r = TV[i].r;
                int c = 0, add = 0;
                int st = l - 1;
                int ed = r - 1;
                int len = ed - st + 1;
                int Ans = 0;
                // cout << st <<" " << ed <<" " << len << endl;
                for(int j = st ; j <= ed ; j ++)
                {
                    if(y[j] == ')')
                    {
                        if(j - st - c + 1> c)
                        {
                            Ans ++;
                            c ++;
                            add ++;
                        }
                    }
                    else
                    {
                        c ++;
                    }
                    // cout << j <<"_" << c <<" " << Ans << endl;
                }
                Ans += c - (len - c + add);
                cout << Ans << '\n';
            }
            if(TV[i].a == 'U')
            {
                int k = TV[i].k;
                id ++;
                x[id] = x[k - 1];
                // cout << id <<" "<< x[id] << endl;
            }

        }
    }

	return 0;
}

void TIME()
{
	cerr << "Time elapsed : " << clock() * 1000 / CLOCKS_PER_SEC << "ms\n";
}
