#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
using namespace std;

using ii = pair <int, int>;
using ld = long double;
using ll = long long;

const int N = 100005;
int n, L; 
pair <int, ll> res[N];
struct Data { 
    int id, time, speed; ll ans;
	bool operator < (const Data &B) { return id < B.id; } 
	bool operator == (const Data &B) { return time == B.time; }
} a[N];

signed main(void) {
    FastIO;
    freopen("WALKING.INP","r",stdin);
    freopen("WALKING.OUT","w",stdout);
    cin >> n >> L;
    FOR(i,1,n) {
        cin >> a[i].time >> a[i].speed;
        a[i].id = i;
		a[i].ans = 1LL*a[i].time + 1LL*a[i].speed*L;
    }
    sort(a+1,a+1+n,[](const Data &A, const Data &B) {
        return (A.time < B.time || (A.time == B.time && A.speed > B.speed));
    });
    
	FOR(i,2,n) a[i].ans = max(a[i].ans, a[i-1].ans);
	sort(a+1, a+1+n);
	FOR(i,1,n) cout << a[i].ans << endl;
    return 0;
}