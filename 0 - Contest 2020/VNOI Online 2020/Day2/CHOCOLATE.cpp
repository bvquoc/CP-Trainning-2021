#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
#define fi first
#define se second
#define int long long

const string INP=".INP", OUT=".OUT";
const string FILENAME="CHOCOLATE";
const int N=20, M=257;
typedef pair<int,int> ii;
typedef vector <int> vi;

template <typename T>
inline void Read(T& x) {
	bool Neg=false;
	char c;
	for (c=getchar();c<'0' || c>'9';c=getchar()) if (c=='-') Neg=!Neg;
	x=c-'0';
	for (c=getchar();c>='0' && c<='9';c=getchar()) x=x*10+c-'0';
	if (Neg) x=-x;
}
template <typename T>
inline void Write(T x) {
	if (x<0) { putchar('-'); x=-x; }
	T p=1;
	for (T temp=x/10;temp>0;temp/=10) p*=10;
	for (;p>0;x%=p,p/=10) putchar(x/p+'0');
}

int n, k, m, p[N];
vector<int> adj[16];
bool mark[N];

int32_t main() {
	FastIO;
	freopen((FILENAME+INP).c_str(),"r",stdin);
	freopen((FILENAME+OUT).c_str(),"w",stdout);
	Read(n); Read(k); Read(m);
	for (int i=1; i<=m; ++i) {
		int u, v;
		Read(u); Read(v);
		--u; --v;
		adj[u].push_back(v);
	}
	
	if (n<=8) {
		vector<int> ans(n);
		for (int i=0; i<n; ++i) ans[i]=i;
		do {
			bool ok=1;
			for (int u=0; u<n; ++u) {
				for (int v : adj[u]) 
					if (ans[v]<=ans[u]) {
						ok=false;
						break;
					}
				if (!ok) break;
			}
			k-=ok;
			if (k==0) {
				for (int i=0; i<n; ++i) {
					Write(ans[i]+1);
					putchar(' ');
				}
				return 0;
			}
		} while(next_permutation(ans.begin(), ans.end()));
		cout<<"poor professor";
		return 0;
	} else if (m==0) {
		p[0]=1;
		for (int i=1; i<=n; ++i) p[i]=p[i-1]*i;
		if (k>p[n]) return !(cout<<"poor professor");
		for (int i=1; i<=n; ++i) {
			for (int j=1; j<=n; ++j) if (!mark[j]) {
				if (p[n-i]<k) k-=p[n-i];
				else {
					mark[j]=1;
					Write(j);
					putchar(' ');
					break;
				}
			}
		}
		return 0;
	}
	
	cout<<"poor professor";
	
	return 0;
}