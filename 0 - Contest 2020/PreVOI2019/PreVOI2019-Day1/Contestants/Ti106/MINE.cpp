#include<bits/stdc++.h>
#define mx 200005
using namespace std;
int n, m, x;
int get(int x,int i)
{
    return (x >> i) & 1;
}
int a[mx];
void nhap()
{
    cin >> n >> m;
        x = 2 * n;

    for(int i = 1; i <= x; i++)
        cin >> a[i];
}
int in[mx],out[mx];
bool tr[mx];
stack<int> per;
int check(int i)
{
    int cur = 0;
    for(int j = 0; j < x; j++)
    {
        if(get(i,j))
            cur++;
        else
            cur--;
        if(cur < 0)
            return 0;
    }
    for(int j = 0; j < x; j++)
    {
        if(get(i,j))
        {
            cur++;
            per.push(cur);
            in[cur] = j +1;
        }
        else
        {
            out[per.top()] = j + 1;
            per.pop();
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(a[out[i]] - a[in[i]] > m)return 0;
    }
    if(tr[out[1]])return 0;
    tr[out[1]] = 1;
    return 1;
}
void brute()
{
    int ans = 0;
    for(int i = 1; i <= (1 << x); i++)
    {
        int k = __builtin_popcount(i);
        if(k * 2 != x)
            continue;
        ans += check(i);
    }
    cout << ans;
}
void sub2()
{

}
void backtrack();
int main()
{
    /// den truoc di truoc den sau di sau
    /// 2 tinh huong khac nhau neu xet
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("MINE.inp","r",stdin);
    freopen("MINE.out","w",stdout);
    nhap();
    if(n <= 10)
        brute();
    else if(m = 1e6)
        sub2();
}
