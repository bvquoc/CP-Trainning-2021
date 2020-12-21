#include <bits/stdc++.h>
#define pii pair<int,int>
#define vi vector<int>
#define F first
#define S second
#define PB(x) push_back(x)
#define ll long long
#define task "PERMEOW"
#define maxn 2005

using namespace std;

const ll MOD = 1e9 + 7;

int a[maxn], b[maxn], n,cnt;

int main()
{
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    cin >> n;
    for (int i = 0 ; i < n ; i++) cin >> a[i];
    for (int i = 0 ; i < n ; i++) cin >> b[i];

    for (int i = 0 ; i < n ; i++)
        for (int j = i+1 ; j < n ; j++) if (a[j] < a[i]) cnt++;

    cout << cnt;

    return 0;
}
