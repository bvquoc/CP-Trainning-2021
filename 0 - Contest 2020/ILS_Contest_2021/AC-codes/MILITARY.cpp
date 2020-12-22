#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[2001];
vector <int> g[100001];
bool sp[100001];
namespace subtask1{
	//n<=500 có nhiều cách để giải. Trong đó có cách là bfs từ tất cả các đỉnh để kiểm tra xem đỉnh này có thỏa mãn không
	//Độ phức tạp là O(n^2+nk^2)
	int f[501];
	bool done[501];
	void solve(){
		vector <int> ans;
		for(int i=1; i<=n; i++){
			queue <int> q;
			for(int j=1; j<=n; j++) f[j]=0;
			q.push(i);
			f[i]=1;
			while(!q.empty()){
				int u=q.front();
				q.pop();
				for(int v: g[u]) if(!f[v]){
					f[v]=f[u]+1;
					q.push(v);
				}
			}
			bool good=true;
			for(int x=1; x<=k; x++){
				for(int y=x+1; y<=k; y++) if(f[a[x]]==f[a[y]]){
					good=false;
					break;
				}
				if(!good) break;
			}
			if(good) ans.push_back(i);
		}
		cout<<ans.size()<<'\n';
		for(int x: ans) cout<<x<<' ';
	}
}
namespace subtask2{
	//k<=300 thì ta có thể tính khoảng cách từ k đỉnh đặc biệt đến tất cả các đỉnh
	//Nếu tìm hai đỉnh bằng nhau bằng cách duyệt như subtask1 thì sẽ không đủ nhanh. nhưng ta có thể dùng một mảng đánh dấu để làm được trong O(nk)
	int f[301][100001];
	int cnt[100001];
	int last[100001];
	void solve(){
		vector <int> ans;
		for(int i=1; i<=k; i++){
			queue <int> q;
			q.push(a[i]);
			f[i][a[i]]=1;
			while(!q.empty()){
				int u=q.front();
				q.pop();
				for(int v: g[u]) if(!f[i][v]){
					f[i][v]=f[i][u]+1;
					q.push(v);
				}
			}
		}
		for(int i=1; i<=n; i++){
			bool good=true;
			for(int j=1; j<=k; j++){
				if(last[f[j][i]]==i){
					good=false;
					break;
				}
				else last[f[j][i]]=i;
			}
			if(good) ans.push_back(i);	
		}
		cout<<ans.size()<<'\n';
		for(int x: ans) cout<<x<<' ';
	}
}
namespace subtask3{
	//k<=2000 thì không làm O(nk) được.
	//Nhận thấy là một đỉnh x mà có cùng độ dài đường đi đến hai đỉnh u, v thì hai đường đi từ u đến x và từ v đến x giao nhau lần đầu tiên ở điểm chính giữa u và v.
	//Từ đó, nếu gọi t là điểm chính giữa u và v, thì từ u và v có đường đi ngắn nhất bằng nhau tới mọi điểm x nếu như đường đi t -> x, t -> u và t -> v giao nhau
	//ở điểm duy nhất là t.
	//Vậy thì ta có thể duyệt mọi cặp u - v, tìm t và đánh dấu lại mọi đỉnh x thỏa mãn.
	//Độ phức tạp là O(n+k^2log(n)).
	bool done[100001];
	int f[100001][18];
	int h[100001];
	int s[100002];
	int first[100001];
	int last[100001];
	int cnt;
	void dfs(int u){
		cnt++;
		first[u]=cnt;
		done[u]=1;
		for(int i=0; f[f[u][i]][i]; i++) f[u][i+1]=f[f[u][i]][i];
		for(int v: g[u]) if(!done[v]){
			h[v]=h[u]+1;
			f[v][0]=u;
			dfs(v);
		}
		last[u]=cnt;
	}
	int lca(int u, int v){
		if(h[u]<h[v]) swap(u, v);
		for(int i=__lg(h[u]); i>=0; i--) if(h[f[u][i]]>=h[v]) u=f[u][i];
		if(u==v) return v;
		for(int i=__lg(h[u]); i>=0; i--) if(f[u][i]!=f[v][i]){
			u=f[u][i];
			v=f[v][i];
		}
		return f[u][0];
	}
	int findChild(int r, int u){
		//Nếu u là hậu duệ thực sự của r, tìm đỉnh con v của r sao cho u cũng là hậu duệ của v
		for(int i=__lg(h[u]); i>=0; i--) if(h[f[u][i]]>h[r]) u=f[u][i];
		return u;
	}
	int findAncestor(int u, int x){
		//Tìm đỉnh cha thứ x của u
		for(int i=__lg(x); i>=0; i--) if((x>>i)&1) u=f[u][i];
		return u;
	}
	void mark(int u, int x){
		s[first[u]]+=x;
		s[last[u]+1]-=x;
	}
	void process(int u, int v){
		//đánh dấu tất cả các đỉnh đến được cùng lức từ hai đỉnh u và v
		if((h[u]+h[v])%2) return;//khoảng cách lẻ thì không có điểm chính giữa
		if(h[u]<h[v]) swap(u, v);
		int r=lca(u, v);
		if(h[u]==h[v]){//u và v bằng nhau
			u=findChild(r, u);
			v=findChild(r, v);
			mark(1, 1);//mọi đỉnh đều thỏa mãn ngoại trừ các đỉnh trên đường từ r đến u và đến v (trừ r)
			mark(u, -1);
			mark(v, -1);
		}
		else{//u thấp hơn v
			r=findAncestor(u, (h[u]+h[v]-h[r]*2)/2);
			mark(r, 1);//mọi đỉnh đều thỏa mãn ngoại trừ các đỉnh trên đường từ r đến u và đến v (trừ r)
			u=findChild(r, u);
			mark(u, -1);
		}
	}
	void solve(){
		h[1]=1;
		dfs(1);
		for(int i=1; i<=k; i++) for(int j=i+1; j<=k; j++) process(a[i], a[j]);
		for(int i=1; i<=n; i++){
			s[i]+=s[i-1];
		}
		vector <int> ans;
		for(int i=1; i<=n; i++) if(s[first[i]]==0) ans.push_back(i);//đỉnh chưa bị đánh dấu thì có thể chiếm được
		cout<<ans.size()<<'\n';
		for(int x: ans) cout<<x<<' ';
	}
}
int main(){
	freopen("MILITARY.INP", "r", stdin);
	freopen("MILITARY.OUT", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>k;
	for(int i=1; i<=k; i++){
		cin>>a[i];
		sp[a[i]]=1;
	}
	for(int i=1, u, v; i<n; i++){
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	// subtask1::solve();
	// subtask2::solve();
	subtask3::solve();
}