#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'
using namespace std;
long long n,k,a[100001],s,nho,t = 1;
int cnp(int k)
{
    int trai,phai,mid;
    trai = 1;
    phai = n;
    while (trai <= phai)
    {
        mid = (trai+phai)/2;
        nho = mid;
        if (a[mid] == k)
            return mid;
        if (a[mid] < k)
        {
            trai = mid + 1;
        }
        if (a[mid] > k)
        {
            phai = mid - 1;
        }
    }
    return 0;
}
int main()
{
    FastIO;
    freopen("TEAM.INP","r",stdin);
    freopen("TEAM.OUT","w",stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        {
        cin >> a[i];
        s = s + a[i];
        }
    k = k % s;
    if (k == 0)
    {
        cout << 0;
        exit(0);
    }
    if (n <= 100000 && k <= 100000000)
    {
        while (k - a[t] >= 0)
        {
            k = k - a[t];
            t++;
        }
            cout << k;
    }
    else
    {
        for (int i = 1; i <= n; i++)
            a[i] = a[i] + a[i-1];
        if (cnp(k) == 0)
        {
            k = k - a[nho-1];
            cout << k;
        }
        else
        {
            k = k - a[nho];
            cout << k;
        }
    }
    return 0;
}
