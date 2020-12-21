#include <bits/stdc++.h>
#define Task "PERMEOW"
#define pii pair<int,int>
#define F first
#define S second
#define ll long long
#define FOR(i, a, b) for(int i = a; i <=b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define pb push_back
#define pii pair<int, int>
#define MOD 1000000007
using namespace std;
const int maxn = 100005;
int n, a[maxn], b[maxn];
int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL), cout.tie(NULL);
    if(fopen(Task".inp", "r"))
    {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
	cin >> n;
	FOR(i, 1, n) cin >> a[i];
	FOR(i, 1, n) cin >> b[i];
	int chiasub1 = 0, chiasub2 = 0;
	FOR(i, 1, n)
	{
	    if ( a[i] == b[i]) chiasub1++;
	    else if ( a[i] == i && b[i] == n - i + 1) chiasub2++;
	}
	if ( n <= 2000)
    {

            ll dem = 0;
            FORD(i, n, 1)
            {
                FOR(j, 1, i - 1)
                if ( a[j] == i )
                {
                    swap(a[j], a[j + 1]);
                    dem++;
                }
            }
            cout << dem % MOD;

    }
    else cout << -1;
//      int tr = 1;
//      int ans = 0;
//      do
//      {
//            int dem = 0;
//            FOR(i, 1, n) b[i] = a[i];
//            ///FOR(i, 1, n) cout << b[i] <<" ";
//            //cout <<" ";
//            if ( b[1] != tr)
//            {
//                tr++;
//                cout << ans <<"\n";
//                cout <<"\n";
//            }
//            FORD(i, n, 1)
//            {
//                FOR(j, 1, i - 1)
//                if ( b[j] == i )
//                {
//                    swap(b[j], b[j + 1]);
//                    dem++;
//                }
//            }
//            ans += dem;
//            //cout << dem <<" ";
//            //cout <<"\n";
//      }
//      while(next_permutation(a + 1, a + n + 1));
//      cout <<ans;

	return 0;
}
