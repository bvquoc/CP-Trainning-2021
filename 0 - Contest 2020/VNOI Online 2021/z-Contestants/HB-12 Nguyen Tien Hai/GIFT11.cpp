#include <bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;
const int nmax=2010;
string a[nmax];
int n, t, cnt_odd=0, cnt_even=0, res=0;
ll frac[nmax];
vector <int> v;
void prepare()
{
    frac[1]=1;
    for (int i=2; i<=nmax-5; ++i)
        frac[i] = frac[i-1] * i % mod;
}
bool check(string x)
{
    ll sum_odd=0, sum_even=0;
    for (int i=0; i<x.size(); ++i)
    {
        if (i & 1) sum_odd += (x[i] - '0');
        else sum_even += (x[i] - '0');
    }
    if (abs(sum_odd - sum_even) % 11 == 0) return 1;
    return 0;
}
void sub0()
{
    v.clear();
    string x;
    for (int i=1; i<=n; ++i) x += a[i];
    if (check(x)) res=1;
    else res=0;

    for (int i=1; i<=n; ++i) v.push_back(i);
    while (next_permutation(v.begin(),v.end()))
    {
        x = "";
        for (int i=0; i<v.size(); ++i)
        {
            int j = v[i];
            x += a[j];
        }
        if (check(x)) res = (res + 1) % mod;
    }
    cout<<res<<'\n';
}
void sub1()
{
    string x;
    for (int i=1; i<=n; ++i) x += a[i];
    if (check(x)) cout << frac[n] << '\n';
    else cout<<"0\n";
}
void sub2()
{
    cout<<"0\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("gift11.inp","r",stdin);
    freopen("gift11.out","w",stdout);
    cin>>t;
    prepare();
    while (t--)
    {
        cin>>n;
        for (int i=1; i<=n; ++i)
        {
            cin>>a[i];
            if (a[i].size() & 1) cnt_odd++;
            else cnt_even++;
        }
        if (n<=9)
        {
            sub0();
            continue;
        }
        if (cnt_even == n)
        {
            sub1();
            continue;
        }
        if (cnt_odd == n)
        {
            sub2();
            continue;
        }
    }
    return 0;
}
