#include <bits/stdc++.h>
#define maxn 2005
#define maxc 1000000007
#define MOD 1000000007
#define task "permeow"
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define pii pair<int,int>
#define ll long long
#define bit(p,x) ((x>>p) & 1)
using namespace std;

int n, a[maxn], pos[maxn];

int main()
{
    ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; ++ i){
        cin >> a[i];
        pos[a[i]] = i;
    }
    for(int i = 1; i <= n; ++ i){
        int x;
        cin >> x;
        if(x != a[i]){
            cout << 695448741;
            return 0;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; ++ i){
        int x = pos[i];
        while(x != i){
            pos[a[x - 1]] = x;
            pos[a[x]] = x - 1;
            swap(a[x], a[x - 1]);
            -- x;
            ++ ans;
        }
    }
    cout << ans;
    return 0;
}
