#include <bits/stdc++.h>
#define MAXN 200005

using namespace std;
int a[MAXN], b[MAXN];
int n;
bool ok;
void read()
{
    cin >> n;
    ok = 1;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> b[i];
    for(int i = 1; i <= n; ++i)
    {
        if(a[i] != b[i])
        {
            ok = 0;
            break;
        }
    }
}
int dem;
void sub1()
{
    dem = 0;
    for(int i = 1; i < n; ++i)
    {
        for(int j = i; j < n; ++j)
        {
            if(a[j] > a[j+1])
            {
                dem++;
                swap(a[j], a[j+1]);
            }
        }
    }
}
void out()
{
    cout << dem << '\n';
}
int main()
{
    freopen("PERMEOW.inp", "r", stdin);
    freopen("PERMEOW.out", "w", stdout);
    read();
    if(ok)sub1();
    out();
    return 0;
}
