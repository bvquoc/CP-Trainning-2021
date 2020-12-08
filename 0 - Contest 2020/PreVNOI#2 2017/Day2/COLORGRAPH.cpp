#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

const string INP=".INP", OUT=".OUT";
const string FILENAME="COLORGRAPH";
const int N=100005;

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

int n, c[N];
set <int> Colors;
int d[N], cur;
vector <int> ke[N];
set <int> col[N];

void BFS(int s){
	for (int i=1;i<=n;i++) {
		col[i].clear();
	}
	queue<int> qu;
	qu.push(s);
	col[s].insert(c[s]);

	while (qu.size()) {
		int u=qu.front();
		qu.pop();
		for (int v:ke[u])
		if (col[v].empty()) {
			col[v]=col[u];
			col[v].insert(c[v]);
			cur+=col[v].size();
			qu.push(v);
		}
	}
}

void bfs(int s){
	for (int i=1;i<=n;i++) {
		d[i]=0;
	}
	queue<int> qu;
	qu.push(s);
	d[s]=1;

	while (qu.size()) {
		int u=qu.front();
		qu.pop();
		for (int v:ke[u])
		if (d[v]==0) {
			d[v]=d[u]+1;
			cur+=d[v];
			qu.push(v);
		}
	}

}

int32_t main() {
	FastIO;
	freopen((FILENAME+INP).c_str(),"r",stdin);
	freopen((FILENAME+OUT).c_str(),"w",stdout);
	Read(n);
	for (int i=1;i<=n;i++) {
		Read(c[i]);
		Colors.insert(c[i]);
	}

	if (Colors.size()==1) { // Sub3
		for (int i=1;i<=n;i++)
			cout<<n<<endl;
		return 0;
	}

	for (int i=1;i<n;i++) {
		int u, v;
		Read(u); Read(v);
		ke[u].push_back(v);  
		ke[v].push_back(u);
	}
	
	if (Colors.size()==n) { // Sub4
		for (int i=1;i<=n;i++) {
			cur=1;
			bfs(i);
			Write(cur);
			putchar('\n');
		}
		return 0;
	}

	for (int i=1;i<=n;i++) {
		cur=1;
		BFS(i);
		Write(cur);
		putchar('\n');
	}
	return 0;
}