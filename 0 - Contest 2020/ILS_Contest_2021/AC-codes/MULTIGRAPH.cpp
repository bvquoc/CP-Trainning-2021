#include <bits/stdc++.h>
using namespace std;
int n, q;
int a[100001];
class cmp{
public:
	bool operator()(pair <int, long long> A, pair <int, long long> B){
		return A.second>B.second;
	}
};
using heap=priority_queue<pair <int, long long>, vector <pair <int, long long>>, cmp>;
namespace subtask1{
	//n và q rất bé nên mỗi lần có thể dijkstra lại
	long long f[100001];
	vector <pair <int, long long>> g[100001];
	long long dijkstra(int u, int v){
		for(int i=1; i<=n; i++) f[i]=1e18;
		for(int i=1; i<=n; i++){
			g[i].clear();
			for(int j=1; j<=n; j++){
				g[i].push_back({j, ((long long)a[i])*a[j]});
			}
		}
		heap q;
		f[u]=0;
		q.push({u, f[0]});
		while(!q.empty()){
			auto p=q.top();
			q.pop();
			if(p.second!=f[p.first]) continue;
			if(p.first==v) return p.second;
			for(auto w: g[p.first]) if(f[w.first]>p.second+w.second){
				f[w.first]=p.second+w.second;
				q.push({w.first, f[w.first]});
			}
		}
	}
	void solve(){
		for(int i=1, t, u, x; i<=q; i++){
			cin>>t>>u>>x;
			if(t==1){
				a[u]=x;
			}
			else{
				cout<<dijkstra(u, x)<<'\n';
				// long long ans=((long long)a[u])*a[x];
				// ans=min(ans, ((long long)(s.begin()->first))*(a[u]+a[x]));
				// cout<<ans<<'\n';
			}
		}
	}
}
namespace subtask2{
	//Nhận thấy là dijkstra thông thường sẽ bị mất O(q*n^2log(n)). Phần log(n) sinh ra vì ta phải chèn vào queue O(n^2) lần cho O(n^2) cạnh.
	//Nhận thấy là nếu ta không chèn, thì mỗi lần tìm đỉnh trọng số thấp nhất duyệt lại mất O(n), và phải duyệt n lần nên thực ra chỉ mất O(n^2) thôi.
	//Vậy thì trong đồ thị dày, cài dijkstra không dùng heap sẽ chạy tốt hơn
	long long f[100001];
	bool done[100001];
	vector <pair <int, long long>> g[100001];
	long long dijkstra(int u, int v){
		for(int i=1; i<=n; i++) f[i]=1e18;
		for(int i=1; i<=n; i++){
			done[i]=0;
			g[i].clear();
			for(int j=1; j<=n; j++){
				g[i].push_back({j, ((long long)a[i])*a[j]});
			}
		}
		f[u]=0;
		// done[u]=1;
		for(int cnt=1; cnt<=n; cnt++){
			int p=-1;
			for(int i=1; i<=n; i++) if(!done[i]){
				if(p==-1) p=i;
				else if(f[i]<f[p]) p=i;
			}
			done[p]=1;
			if(p==v) return f[p];
			for(auto w: g[p]) if(f[w.first]>f[p]+w.second) f[w.first]=f[p]+w.second;			
		}
	}
	void solve(){
		for(int i=1, t, u, x; i<=q; i++){
			cin>>t>>u>>x;
			if(t==1){
				a[u]=x;
			}
			else{
				cout<<dijkstra(u, x)<<'\n';
			}
		}
	}
}
namespace subtask3{
	//Vì n<=100 và chỉ có 10 lần cập nhật, mỗi lần ta có thể floyd lại, trả lời trong O(1)
	// long long f[100001];
	// bool done[100001];
	// vector <pair <int, long long>> g[100001];
	long long f[101][101];
	void floyd(){
		for(int i=1; i<=n; i++){
			f[i][i]=0;
			for(int j=i+1; j<=n; j++){
				f[i][j]=f[j][i]=((long long)a[i])*a[j];
			}
		}
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				for(int k=1; k<=n; k++){
					f[j][k]=min(f[j][k], f[j][i]+f[i][k]);
				}
			}
		}
	}
	void solve(){
		if(n>100){
			return;
		}
		floyd();
		for(int i=1, t, u, x; i<=q; i++){
			cin>>t>>u>>x;
			if(t==1){
				a[u]=x;
				floyd();
			}
			else{
				cout<<f[u][x]<<'\n';
			}
		}
	}
}
namespace subtask4{
	//nhận thấy thực ra chỉ có 2 đường đi là có thể ngắn nhất: đi thẳng từ u->v với trọng số a[u]*a[v]
	//đi qua đúng 1 đỉnh giữa có a[i] thấp nhất, trọng số là (a[u]+a[v])*a[min]
	//vậy thì ở mỗi thời điểm, ta chỉ cần biết giá trị a[i] bé nhất
	//Vậy thì có thể kiểm soát giá trị của các đỉnh bằng set/segment tree, ....
	set <pair <int, int>> s;
	void solve(){
		for(int i=1; i<=n; i++) s.insert({a[i], i});
		for(int i=1, t, u, x; i<=q; i++){
			cin>>t>>u>>x;
			if(t==1){
				s.erase({a[u], u});
				a[u]=x;
				s.insert({a[u], u});
			}
			else{
				long long ans=((long long)a[u])*a[x];
				ans=min(ans, ((long long)(s.begin()->first))*(a[u]+a[x]));
				if(u==x) ans=0;
				cout<<ans<<'\n';
			}
		}
	}
}
int main(){
	freopen("MULTIGRAPH.INP", "r", stdin);
	freopen("MULTIGRAPH.OUT", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>q;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		cerr<<a[i]<<" \n"[i==n];
	}
	// subtask1::solve();	
	// subtask2::solve();	
	// subtask3::solve();	
	subtask4::solve();	
}