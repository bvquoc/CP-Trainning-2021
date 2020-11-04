#include<bits/stdc++.h>
using namespace std;

long n;
long long a[100005], M;

bool check(long mid)
{
    for (long i = 1; i <= n - mid + 1; i++)
    {
        if (a[i + mid - 1] - a[i - 1] < M) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> M >> n;
    for (long i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    long l = 1, r = n;
    long mid = (l + r) / 2;
    while (r - l > 1)
    {
        if (check(mid)) r = mid;
        else l = mid;
        mid = (l + r) / 2;
    }
    if (check(l)) cout << l;
    else cout << r;
    return 0;
}
