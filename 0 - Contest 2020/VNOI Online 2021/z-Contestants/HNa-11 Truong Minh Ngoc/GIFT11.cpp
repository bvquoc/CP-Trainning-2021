#include <bits/stdc++.h>

const int N = 1e5 + 5, mod = 998244353;
#define X first
#define Y second
#define fo(i,j,k) for(int i = j; i <= k; ++i)
#define of(i,j,k) for(int i = j; i >= k; --i)
#define PB push_back
#define all(a) (a).begin(),(a).end()
#define reset(a,val) fill(a+1,a+sizeof(a),val)
#define task "GIFT11"

using namespace std;

typedef pair <int,int> ii;
typedef long long ll;

int t,n,ans = 0;
string a[N];
int id[N];
int even[N],odd[N];

void solve1()
{
    ans = 0;
    do
    {
        int cur = 0;
        string res = "";
        fo(i,1,n)
        {
            /// cout << res.size() << ' ';
            if(res.size() % 2 == 1)
            {
                cur += odd[id[i]];
                cur -= even[id[i]];
            }
            else
            {
                cur += even[id[i]];
                cur -= odd[id[i]];
            }
            res = res + a[id[i]];
            /// cout << cur << endl;
        }

        if(cur % 11 == 0)
        {
            ans++;
            if(ans >= mod) ans -= mod;
        }
    }while(prev_permutation(id+1,id+n+1,greater<int>()));

    cout << ans << '\n';
}

void init()
{
    fo(i,1,n) even[i] = odd[i] = 0;
    fo(i,1,n)
    {
        fo(j,0,a[i].size()-1)
        {
            if(j % 2 == 0) odd[i] += (a[i][j] - '0');
            else even[i] += (a[i][j] - '0');
        }
    }

    /// fo(i,1,n) cout << even[i] << ' ' << odd[i] << endl;
}

ll gt[N];

void init2()
{
    gt[1] = 1;
    fo(i,2,N)
    {
        gt[i] = gt[i-1] * i;
        gt[i] %= mod;
    }
}

void solve2()
{
    ll cur = 0;
    fo(i,1,n) cur += even[i] - odd[i];
    /// cout << cur << endl;
    if(cur % 11 == 0) cout << gt[n] << '\n';
}

void read()
{
    init2();
    cin >> t;
    while(t--)
    {
        bool ok = true;
        cin >> n; fo(i,1,n) id[i] = i;
        fo(i,1,n)
        {
            cin >> a[i];
            if(a[i].size() % 2 == 1) ok = false;
        }
        init();
        if(ok == false) solve1();
        else solve2();

    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    read();

    return 0;
}
