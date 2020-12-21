#include<bits/stdc++.h>
#define mino "gift11"

#define ll long long
#define pb push_back
#define fi first
#define se second
#define mp make_pair

#define INC(i,a,b) for(int i=a; i<=b; i++)
#define DEC(i,a,b) for(int i=a; i>=b; i--)
#define REP(i,a,b) for(int i=a; i<b; i++)

#define turbo ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define oo 1e9

const int N = 1e5 + 5;
const ll MOD = 998244353;

using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;


int T, n, sc, sl;
int a[N];
//int dp1[2002][1002][12], dp2[2002][2002][12][2];
vi odd, even;

void solve()
{
    even.clear(); odd.clear();
    odd.pb(-1); even.pb(-1);
    sc = sl = 0;

    cin >> n;

    ll tong = 0;

    INC(i,1,n)
    {
        int x; cin >> x;
        a[i] = 0;
        vi st;
        while( x )
        {
            st.pb(x%10);
            x /= 10;
        }
        int cc = 0;
        DEC(j,(int)st.size()-1,0)
        {
            if( !cc ) a[i] += st[j];
            else a[i] -= st[j];
            cc = 1 - cc;
        }

        if( int(st.size()) % 2 == 0 ) even.pb(a[i]), sc++;
        else odd.pb(a[i]), sl++;

        tong += a[i];
    }

    if( tong % 11 != 0 ) cout << "0\n";
    else
    {
        ll pp = 1;
        INC(i,1,n) pp = (pp * i) % MOD;
        cout << pp << '\n';
    }
    return;

//    INC(i,0,10) pre[i] = 0;
//
//    dp1[0][0][0] = 1;
//    INC(i,1,sl)
//    {
//        INC(j,0,(sl+1)/2)
//        {
//            INC(k,0,10)
//            {
//                if( j > 0 )
//                {
//                    dp1[i][j][(k+odd[i])%11] += dp1[i-1][j-1][k];
//                    dp1[i][j][(k+odd[i])%11] %= MOD;
//                }
//
//                dp1[i][j][(k-odd[i]+11)%11] += dp1[i-1][j][k];
//                dp1[i][j][(k-odd[i]+11)%11] %= MOD;
//            }
//        }
//    }
//
//
//    cout << dp1[sl][5][0] << endl;
//    return;
//    dp2[0][0][0][0] = 1;
//    INC(i,0,sc)
//    {
//        INC(j,0,sl)
//        {
//            INC(k,0,10)
//            {
//                /// Add
//                if( j )
//                {
//                    dp2[i][j][k][0] = (dp2[i][j][k][0] + dp2[i][j-1][k][1]) % MOD;
//                    dp2[i][j][k][1] = (dp2[i][j][k][1] + dp2[i][j-1][k][0]) % MOD;
//                }
//
//                /// Not add
//                if( i )
//                {
//                    dp2[i][j][k+even[i]%11][0] = (dp2[i][j][k+even[i]%11][0] + dp2[i-1][j][k][0]) % MOD;
//                    dp2[i][j][(k-even[i]+11)%11][1] = (dp2[i][j][(k-even[i]+11)%11][1] + dp2[i-1][j][k][1]) % MOD;
//                }
//            }
//        }
//    }
//
//    cout << dp1[sl][(sl+1)/2][0] << endl;
//    ll res = 0;
//    INC(i,0,10)
//    {
//        res = res + 1ll * (dp2[sc][sl][i][0] + dp2[sc][sl][i][1]) * dp1[sl][(sl+1)/2][(11-i)%11] % MOD;
//        cout << i << ' ' << res << endl;
//        res %= MOD;
//    }
//    cout << res << '\n';
}

int main()
{
    freopen(mino".inp","r",stdin);
    freopen(mino".out","w",stdout);

    turbo

    cin >> T;

    while( T-- )
    {
        solve();
    }

}
