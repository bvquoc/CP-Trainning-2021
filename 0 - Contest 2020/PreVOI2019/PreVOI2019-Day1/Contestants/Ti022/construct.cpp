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
const int oo = 1e6+10;
void TIME();

int T;
int n , m;
int A[100010];
int B[100010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0) ; cout.tie(0);

	freopen("construct.inp","r",stdin);
	// freopen("construct.inp","w",stdout);
	freopen("construct.out","w",stdout);

    cin >> T;

    while(T)
    {
        cin >> n >> m ;
        for(int i = 1 ; i <= n ; i ++)
        {
            cin >> A[i];
        }
        int a, l, r, k;
        for(int i = 1 ; i <= m ; i ++)
        {
            cin >> a;
            if(a == 1)
            {
                cin >> l >> r >> k;
                for(int j = l; j <= r; j ++)
                {
                    A[j] += k;
                }
            }
            else
            {
                int Ans = 0;
                cin >> l >> r;
                for(int j = l ; j <= r ; j ++)
                {
                    B[j] = A[j];
                }
                while(1)
                {
                    //cout << ".";
                    bool tf = 0;
                    int minn = oo;
                    int ll = oo;
                    for(int j = l ; j <= r ; j ++)
                    {
                        if(B[j])
                        {
                            tf = 1;
                            ll = min(ll, j);
                            minn = min(minn, B[j]);
                        }
                        else
                        {
                            if(minn != oo)
                            {
                                for(int h = ll ; h <= j-1 ; h ++)
                                {
                                    B[h] -= minn;
                                }
                                Ans += minn;
                                ll = oo;
                                minn = oo;
                            }
                        }
                    }

                    if(minn != oo)
                    {
                        for(int h = ll ; h <= r ; h ++)
                        {
                            B[h] -= minn;
                        }
                        Ans += minn;
                    }
//                    for(int h = l ; h <= r ; h ++)
//                    {
//                        cout << B[h] <<" ";
//                    }
//                    cout << endl;
                    if(tf == 0)
                    {
                        break;
                    }
                    // break;
                }
                cout << Ans << '\n';
            }
        }
        T --;
    }



	return 0;
}

void TIME()
{
	cerr << "Time elapsed : " << clock() * 1000 / CLOCKS_PER_SEC << "ms\n";
}
