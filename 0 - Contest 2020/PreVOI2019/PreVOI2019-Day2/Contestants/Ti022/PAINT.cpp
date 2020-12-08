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

int n;
int A[1000010];
int ID[30];
vector <int> B[30];
int maxx;

//void sub1()
//{
//    int a;
//    char x, y;
//    for(int i = 1 ; i <= n ; i ++)
//    {
//        cin >> a;
//        if(a == 1)
//        {
//            cin >> x;
//            for(int j = 1 ; j <= n ; j ++)
//            {
//                if(!A[j])
//                {
//                    maxx = max(maxx, j);
//                    A[j] = x -'a' + 1;
//                    break;
//                }
//            }
//        }
//        else
//        {
//            cin >> x >> y;
//            if(x == y) continue;
//            int res = x - 'a' + 1;
//            int cur = y - 'a' + 1;
//            for(int j = 1 ; j <= maxx ; j ++)
//            {
//                if(A[j] == res)
//                {
//                    A[j] = cur;
//                }
//            }
//        }
//    }
//    for(int i = 1 ; i <= maxx ; i ++)
//    {
//        if(A[i])
//        {
//            cout << char(A[i] + 'a' -1);
//        }
//    }
//}
int subfull()
{
    // cout << ".";
    maxx = 0;
    int a;
    char x, y;
    for(int i = 1 ; i <= n ; i ++)
    {
        cin >> a;
        // cout << a << endl;
        if(a == 1)
        {
            cin >> x;
            maxx ++;
            //A[maxx] = x - 'a' + 1;
            int res = x - 'a' + 1;
            res = ID[res];
            B[res].push_back(maxx);
        }
        else
        {
            cin >> x >> y;
            int res = x - 'a' + 1;
            int cur = y - 'a' + 1;
            if(res == cur) continue ;
            int res1 = ID[res];
            int cur1 = ID[cur];
            if(B[cur1].size() >= B[res1].size())
            {
                for(int j = 0 ; j < B[res1].size() ; j ++)
                {
                    B[cur1].push_back(B[res1][j]);
                }
                B[res1].clear();
            }
            else
            {
                for(int j = 0 ; j < B[cur1].size() ; j ++)
                {
                    B[res1].push_back(B[cur1][j]);
                }
                B[cur1].clear();
                // cout <<".";
                // cout << res1 <<" " << cur1 << endl;
                // cout << ID[res]<<" " << ID[cur] << endl;
                swap(ID[res],ID[cur]);
                // cout << ID[res]<<" " << ID[cur] << endl;

            }
        }
        // cout <<"." << endl;
    }
    // cout <<"." << endl;
    for(int i = 1 ; i <= 26 ; i ++)
    {
        for(int j = 0 ; j < B[ID[i]].size() ; j ++)
        {
            A[B[ID[i]][j]] = i;
        }
    }
    for(int i = 1 ;i <= maxx ; i ++)
    {
        cout << char(A[i] + 'a' - 1);
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0) ; cout.tie(0);

	freopen("PAINT.inp","r",stdin);
	// freopen("PAINT.inp","w",stdout);
	freopen("PAINT.out","w",stdout);

    cin >> n ;
    // sub1();
    for(int i = 1 ; i <= 26 ; i ++)
    {
        ID[i] = i;
    }
    // cout << endl;
    subfull();
	return 0;
}

void TIME()
{
	cerr << "Time elapsed : " << clock() * 1000 / CLOCKS_PER_SEC << "ms\n";
}
