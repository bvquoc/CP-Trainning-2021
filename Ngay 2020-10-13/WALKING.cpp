#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
// #define int long long
using namespace std;

using ii = pair <int, int>;
using ld = long double;
using ll = long long;

struct MaxST{
	vector <int> st;
	MaxST() {}
	MaxST(int n) {
		st.resize((4*(n+5)));
	}
	void assign(int n) {
		st.resize((4*(n+5)));
	}

	void update(int id, int l, int r, int i, int v) {
		if (i<l || r<i) return;
		if (l==r) {
			st[id] = v;
			return;
		}
		int mid = (l+r)>>1, id1 = id<<1, id2 = id1+1;
		update(id1,l,mid,i,v);
		update(id2,mid+1,r,i,v);
		st[id] = max(st[id1],st[id2]);
	}

	int getmax(int id, int l, int r, int u, int v) {
		if (v<l || r<u) return INT_MIN;
		if (u<=l && r<=v) return st[id];
		int mid = (l+r)>>1, id1 = id<<1, id2 = id1+1;
		return max(getmax(id1,l,mid,u,v), getmax(id2, mid+1, r, u, v));
	}
} ST;

const int N = 100005;
int n, L; ii res[N];
struct Data { 
    int id, time, speed; 
	bool operator == (const Data &B) {
		return time == B.time;
	}
} a[N];

signed main(void) {
    FastIO;
    freopen("WALKING.INP","r",stdin);
    freopen("WALKING.OUT","w",stdout);
    cin >> n >> L;
    FOR(i,1,n) {
        a[i].id = i;
        cin >> a[i].time >> a[i].speed;
    }
    sort(a+1,a+1+n,[](const Data &A, const Data &B) {
        return (A.time < B.time || (A.time == B.time && A.speed > B.speed));
    });

    ST.assign(n);
    FOR(i,1,n) {
        ST.update(1,1,n,i,a[i].speed);
        res[i].first = a[i].id;
    }
	
    FOR(i,1,n) {
		cout << a[i].time << ' ' << a[i].speed << endl;
    }

    return 0;
}