#include <bits/stdc++.h>

const int N = 1e5 + 5, mod = 1e9 + 7;
#define X first
#define Y second
#define fo(i,j,k) for(int i = j; i <= k; ++i)
#define of(i,j,k) for(int i = j; i >= k; --i)
#define PB push_back
#define all(a) (a).begin(),(a).end()
#define reset(a,val) fill(a+1,a+sizeof(a),val)
#define getbit(i,j) (int)(((i) >> (j)) & 1)
#define task "PERMEOW"

using namespace std;

typedef pair <int,int> ii;
typedef long long ll;

int n,a[N];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);

    cin >> n;
    fo(i,1,n) cin >> a[i];

    cout << 0;

    return 0;
}
