#include <bits/stdc++.h>
#define sz(x) int(x.size())
#define all(x) x.begin(),x.end()
#define reset(x) memset(x, 0,sizeof(x))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define N 2005
#define remain(x) if (x > MOD) x -= MOD
#define ii pair<int, int>
#define vi vector<int>
#define vii vector< ii >
#define bit(x, i) (((x) >> (i)) & 1)
#define Task "gift11"
#define int long long

using namespace std;
const int Mod = 998244353;

typedef long double ld;

int giaithua(int a)
{
    if (a==2) return a;
    return (a*giaithua(a-1))%Mod;
}

int t,n,a[N];
string b[N];
bool all_even = true;

int sol()
{
    int cur = 1;
    int ans = 0;
    for(int i=1; i<=n; i++)
    {
        string s = b[a[i]];
        for(int j=0; j<s.size(); j++)
        {
            if (cur%2==0) ans -= s[j]-'0';
            else ans += s[j]-'0';
            cur++;
        }
    }
    if (ans%11==0) return 1;
    else return 0;
}

void proc()
{
    if (all_even)
    {
        int ans_even=0;
        int ans_odd=0;
        for(int i=1; i<=n; i++)
        {
            string s = " " + b[i];
            for(int j=1; j<=b[i].size(); j++)
            {
                if (j%2==0) ans_even += s[j]-'0';
                else ans_odd += s[j]-'0';
            }
        }
        if ((-ans_even + ans_odd)%11 == 0) cout << giaithua(n) << '\n';
        else cout << 0 << '\n';
        return;
    }
    else if (n <= 8)
    {
        int res = 0;
        res += sol();
        while (next_permutation(a+1,a+1+n)) res+=sol();
        cout << res%Mod << '\n';
        return;
    }
}

void readfile()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    if (fopen(Task".inp","r"))
    {
        freopen(Task".inp","r",stdin);
        freopen(Task".out","w",stdout);
    }
    cin >> t;
    while (t--)
    {
        cin >> n;
        for(int i=1; i<=n; i++){
            a[i] = i;
            cin >> b[i];
            if (b[i].size()%2!=0) all_even = false;
        }
        proc();
    }
}

signed main()
{
    readfile();
    return 0;
}
