#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define FORU(i , a , b) for (int i = (a) ; i <= (b) ; i++)
#define FORD(i , a , b) for (int i = (a) ; i >= (b) ; i--)
#define pii pair <int , int>
#define fi first
#define se second
#define task "GIFT11"
#define oo (int)1e9
using namespace std;
const int maxn = 2001 , MOD = 998244353;
int n , a[maxn] , d[11] , x[11] , res;
int odd[maxn] , even[maxn] , num[maxn];
bool flag1 = true , flag2 = true;
void phantich(int x , int i)
{
    odd[i] = even[i] = 0;
    stack <int> st;
    if (!x) st.push(0);
    while (x)
    {
        st.push(x % 10);
        x /= 10;
    }
    int l = 1;
    num[i] = st.size();
    while (st.size())
    {
        if (l) odd[i] += st.top();
        else even[i] += st.top();
        st.pop();
        l = 1 - l;
    }
}
void input()
{
    cin >> n;
    FORU(i , 1 , n)
    {
        cin >> a[i];
        phantich(a[i] , i);
        flag1 &= (num[i] % 2 == 0);
        flag2 &= (num[i] % 2 != 0);
    }
}
void update()
{
    int l = 1 , tmp = 0;
    FORU(j , 1 , n)
    {
        int i = x[j];
        if (l % 2) tmp += odd[i] - even[i];
        else tmp += even[i] - odd[i];
        l += num[i];
    }
    res += (tmp % 11 == 0);
}
void backtrack(int i)
{
    FORU(j , 1 , n)
    {
        if (!d[j])
        {
            d[j] = 1;
            x[i] = j;
            if (i == n) update();
            else backtrack(i + 1);
            d[j] = 0;
        }
    }
}
void sub1()
{
    backtrack(1);
    cout << res << '\n';
    res = 0;
}
void sub2()
{
    res = 1;
    int tmp = 0;
    FORU(i , 1 , n) tmp += odd[i] - even[i];
    if (tmp % 11 == 0)
    {
        FORU(i , 1 , n)
        {
            res = (res * i) % MOD;
        }
    }
    else res = 0;
    cout << res << '\n';
    res = 0;
}
void solve()
{
    if (n <= 8) sub1();
    else if (flag1) sub2();
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen(task".inp" , "r" , stdin);
    freopen(task".out" , "w" , stdout);
    int t;
    cin >> t;
    while (t--)
    {
        input();
        solve();
    }
    return 0;
}
