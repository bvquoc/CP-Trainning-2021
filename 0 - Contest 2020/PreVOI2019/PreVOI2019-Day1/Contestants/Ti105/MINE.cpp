#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 4004
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define pii pair<int,int>
#define Bit(x,i) ((x>>i)&1)
#define debug4(i,j,k,l) cerr << i << ' ' << j << ' ' << k << ' ' << l << '\n';
#define debug3(i,j,k) cerr << i << ' ' << j << ' ' << k << '\n';
#define debug2(i,j) cerr << i << ' ' << j<< '\n';
#define debug1(i) cerr << i << '\n';
using namespace std;

const int mod = 1000003;
int n,m;
ll a[maxn];
ll t[25];

ll f[maxn][maxn][2];

ll ans = 0;

void Sub1()
{
    int ans = 0;
    for(int i = 0;i < (1<<(2*n));i++)
    {
        bool ok = true;
        stack<int> stk;
        For(j,0,2*n-1)
        {
            if(!Bit(i,j)) stk.push(a[j+1]);
            else
            {
                if(stk.empty())
                    ok = false;
                else
                {
                    if(a[j+1] - stk.top() > m) ok = false;
                    stk.pop();
                }
                if(!ok) break;
            }
        }
        if(!stk.empty() || !ok) continue;
        //For(j,0,2*n-1) cout << Bit(i,j) ; cout << endl;
        ans += ok;
    }
    cout << ans % mod << endl;
    exit(0);
}

ll dequy(int i,int open,int ok)
{
    //cout << i << ' ' << open << ' ' << ok << ' ' << f[i][open][ok] << endl;
    if(i == 2*n) return (open == 0 && ok == 1);
    if(f[i][open][ok] != -1) return f[i][open][ok] % mod;
    ll tmp = 0;
    if(open < n) tmp += dequy(i+1,open+1,0);
    if(open > 0) tmp += dequy(i+1,open-1,1);
    f[i][open][ok] = tmp % mod;
    //cout << " << " << i << ' ' << open << ' ' << ok << ' ' << f[i][open][ok] << endl;
    return tmp;
}

void Sub2()
{
    memset(f,-1,sizeof(f));
    cout << dequy(1,1,0) % mod << endl;
}

int main()
{
    fast_read;
    freopen("MINE.inp","r",stdin);
    freopen("MINE.out","w",stdout);
    cin >> n >> m;
    For(i,1,2*n) cin >> a[i];
    if(n <= 10) Sub1();
    else Sub2();
}
