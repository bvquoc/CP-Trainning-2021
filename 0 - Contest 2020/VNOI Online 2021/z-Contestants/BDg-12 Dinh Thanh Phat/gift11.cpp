#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a),_b=(b);i<_b;++i)

using namespace std;
typedef long long ll;
const ll mod = 998244353;


const int maxn = 2001;
int a[maxn];
int n;
void enter()
{
    cin>>n;
    _for(i,1,n+1)
        cin>>a[i];
}

string tostring(int num)
{
    string res = "";
    while(num)
    {
        res += char(num%10 + '0');
        num /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}
string b[maxn];

bool check(vector<int> & id)
{
    string ans = "";
    for(auto i:id)
    {
        ans += b[i];
    }
    int sum0 = 0, sum1 = 0;
    _for(i,0,ans.size())
    {
        if (i%2 == 0) sum0 += (ans[i] - '0');
        else sum1 += (ans[i] - '0');
    }
    if (abs(sum0 - sum1) %11==0) return true;
    else return false;
}
void sub1()
{
    vector<int> id;
    _for(i,1,n+1)
    {
        id.push_back(i);
        b[i] = tostring(a[i]);
    }
    int ans = 0;
    do
    {
        if (check(id)) ans++;
    }
    while(next_permutation(id.begin(), id.end()));
    cout<<ans<<"\n";
}
typedef pair<int,int> pir;
#define fi first
#define se second
pir c[maxn];
bool d[maxn];
pir dem(string &A)
{
    int sum1 = 0,sum0 = 0;
    _for(i,0,A.size())
    {
        if (i%2==0) sum1 += (A[i] - '0');
        else sum0 += (A[i] - '0');
    }
    return pir(sum1, sum0);
}
void sub2()
{
    _for(i,1,n+1)
        b[i] = tostring(a[i]);
    int sum1 = 0,sum0 = 0;
    _for(i,1,n+1)
    {
        c[i] = dem(b[i]);
        sum1 += c[i].fi;
        sum0 += c[i].se;
    }
    if (abs(sum1 - sum0) %11 == 0)
    {
        ll ans = 1;
        _for(i,1,n+1)
        {
            ans = ans*i;
            ans = ans%mod;

        }
        cout<<ans<<"\n";
    }
    else cout<<"0\n";
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    freopen("gift11.inp","r",stdin);
    freopen("gift11.out","w",stdout);
    int t;
    cin>>t;
    _for(i,0,t)
    {
        enter();
        if (n<=9) sub1();
        else sub2();
    }
    return 0;
}
