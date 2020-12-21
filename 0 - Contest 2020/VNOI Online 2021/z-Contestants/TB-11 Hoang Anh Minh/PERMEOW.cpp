#include <iostream>
#include <bits/stdc++.h>
#define FORU(i , a , b) for (int i = (a) ; i <= (b) ; i++)
#define FORD(i , a , b) for (int i = (a) ; i >= (b) ; i--)
#define pii pair <int , int>
#define fi first
#define se second
#define task "PERMEOW"
#define oo (int)1e9
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn] , b[maxn] , n;
int app[maxn];
void input()
{
    cin >> n;
    FORU(i , 1 , n) cin >> a[i];
    FORU(i , 1 , n)
    {
        cin >> b[i];
        app[b[i]] = i;
    }
}
void sub1()
{
    int res = 0;
    FORD(i , n , 1)
    {
        res += i - app[i];
        FORU(j , app[i] , i - 1)
        {
            int tmp = a[j + 1];
            a[j] = a[j + 1];
            app[tmp] = j;
        }
    }
    cout << res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen(task".inp" , "r" , stdin);
    freopen(task".out" , "w" , stdout);
    input();
    sub1();
    return 0;
}
