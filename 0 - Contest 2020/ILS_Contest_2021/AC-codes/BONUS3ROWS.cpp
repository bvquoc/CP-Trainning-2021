#include <bits/stdc++.h>
using namespace std;
int n, qCnt;
long long a[4][100001];
long long s[4][100001];
class query{
public:
	int x, y, u, v;
	int id;
} q[100001];
long long ans[100001];
namespace subtask1{
	//Subtask 1 có n*q<=10^6, vì thế ta có thể giải quyết mỗi truy vấn trong O(n).
	//Cách đơn giản nhất là quy hoạch động.
	long long f[4][100001];
	long long getAnswer(int x, int y, int u, int v){
		long long res=0;
		if(y==v){
			if(x>u) swap(u, x);
			for(int i=x; i<=u; i++) res+=a[i][y];
		}
		else{
			if(y>v){
				swap(x, u);
				swap(y, v);
			}
			if(x==u){
				for(int i=y; i<=v; i++) res+=a[x][i];
			}
			else{
				int h=(x>u)?-1:1;
				for(int i=x;; i+=h){
					for(int j=y; j<=v; j++){
						f[i][j]=-1e18;
					}
					if(i==u) break;
				}
				f[x][y]=0;
				for(int i=x;; i+=h){
					for(int j=y; j<=v; j++){
						f[i][j]+=a[i][j];
						if(i!=u) f[i+h][j]=max(f[i+h][j], f[i][j]);
						if(j!=v) f[i][j+1]=max(f[i][j+1], f[i][j]);
					}
					if(i==u) break;
				}
				res=f[u][v];
			}
		}
		return res;
	}
	void solve(){
		for(int i=1; i<=qCnt; i++) ans[i]=getAnswer(q[i].x, q[i].y, q[i].u, q[i].v);
	}
}
namespace subtask2{
	//Subtask 2 có điều kiện đặc biệt là chỉ di chuyển tối đa giữa hai hàng
	//Nếu di chuyển trên cùng hàng/cột thì có cách đi duy nhất và có thể giải bằng tổng dồn
	//Giả sử như di chuyển từ ô (1, l) sang ô (2, r) (r>l) thì ta sẽ di chuyển trên hàng 1 các ô (1, l), (1, l+1), ..., (1.., i) và trên hàng 2 các ô (2, i), (2, i+1), ..., (2, r)
	//Gọi s[i][j] là tổng dồn trên hàng i thì kết quả trên có thể tính được thành f[1][i]-f[1][l-1]+f[2][r]-f[2][i-1]
	//Tổng trên có phần cố định là -f[1][l-1]+f[2][r], ta cần tìm i sao cho  f[1][i]-f[2][i-1] lớn nhất có thể. Điều này trở thành tìm max trên một đoạn.
	//Để tìm max có nhiều cách làm, trong code này dùng segment tree
	class segmentTree{
	public:
		using pointer=segmentTree*;
		int l, r, m;
		pointer left, right;
		long long value;
		segmentTree(long long *a, int l, int r): l(l), r(r), m((l+r)/2){
			if(l==r){
				value=a[l];
			}
			else{
				left=new segmentTree(a, l, m);
				right=new segmentTree(a, m+1, r);
				value=max(left->value, right->value);
			}
		}
		long long get(int u, int v){
			if(l>v||r<u) return -1e18;
			else if(u<=l&&v>=r) return value;
			else return max(left->get(u, v), right->get(u, v));
		}
	};
	segmentTree::pointer tree[4][4];
	long long weight[100001];
	void makeTree(int u, int v){
		//Đi từ (u, l) -> (v, r) => (u, l)->(u, i) + (v, i)->(i, r)
		for(int i=1; i<=n; i++) weight[i]=s[u][i]-s[v][i-1];
		tree[u][v]=new segmentTree(weight, 1, n);
	}
	long long getAnswer(int x, int y, int u, int v){
		if(x==u){
			if(y>v) swap(y, v);
			return s[x][v]-s[x][y-1];
		}
		else{
			if(y>v){
				swap(y, v);
				swap(x, u);
			}
			// assert(abs(x-u)==1);
			if(abs(x-u)!=1) exit(0);
			return -s[x][y-1]+s[u][v]+tree[x][u]->get(y, v);
		}
	}
	void solve(){
		if(1LL*n*qCnt<=1000000) subtask1::solve();
		else{
			for(int i=1; i<3; i++) makeTree(i, i+1);
			for(int i=3; i>1; i--) makeTree(i, i-1);
			for(int i=1; i<=qCnt; i++) ans[i]=getAnswer(q[i].x, q[i].y, q[i].u, q[i].v);
		}
	}
}
namespace subtask3{
	//Trường hợp mà đi trên 1/2 hàng thì xử lí giống hệt subtask2
	//Trường hợp mà đi trên 3 hàng:
	//Giả sử đi từ (1, l) đến (3, r) thì tồn tại hai số (i, j) sao cho ta sẽ đi
	//(1, l)->(1, i), (2, i)->(2, j), (3, j)->(3, r) (l<=i<=j<=r)
	//Tổng là s[1][i]-s[1][l-1]+s[2][j]-s[2][i-1]+s[3][r]-s[3][j-1]
	//Cắt thành 3 phần: (s[3][r]-s[1][l-1])+(s[1][i]-s[2][i-1])+(s[2][j]-s[3][j-1])
	//Phần đầu tiên thì ta có khi duyệt truy vấn, vậy ta cần phải tìm 2 giá trị i, j sao cho (s[1][i]-s[2][i-1])+(s[2][j]-s[3][j-1]) lớn nhất có thể
	//Nếu ta chọn được i thì có cách chọn j tốt nhất có thể. j tốt nhất có thể chính là j>i mà có (s[2][j]-s[3][j-1]) lớn nhất có thể.
	//Nếu ta duyệt r tăng dần thì ta có thể tìm được với mỗi i giá trị (s[1][i]-s[2][i-1])+(s[2][j]-s[3][j-1]) lớn nhất có thể. 
	//Giữ lại giá trị lớn nhất bằng cách sử dụng segment tree có lazy update. Cũng cần sử dụng một deque để tìm  (s[2][j]-s[3][j-1]) lớn nhất có thể.
	vector <query> w[4][4];
	class segmentTree{
	public:
		using pointer=segmentTree*;
		int l, r, m;
		pointer left, right;
		long long value, lazy;
		segmentTree(int l, int r): l(l), r(r), m((l+r)/2), lazy(0), value(0){
			if(l!=r){
				left=new segmentTree(l, m);
				right=new segmentTree(m+1, r);
			}
		}
		void down(){
			left->value+=lazy;
			right->value+=lazy;
			left->lazy+=lazy;
			right->lazy+=lazy;
			lazy=0;
		}
		void update(int u, int v, long long x){
			if(l>v||r<u) return;
			else if(u<=l&&v>=r){
				value+=x;
				lazy+=x;
			}
			else{
				down();
				left->update(u, v, x);
				right->update(u, v, x);
				value=max(left->value, right->value);
			}
		}
		long long get(int u, int v){
			if(l>v||r<u) return -1e18;
			else if(u<=l&&v>=r) return value;
			else{
				down();
				return max(left->get(u, v), right->get(u, v));
			}
		}
		void show(long long pad=0){
			if(l==r) cout<<value+pad<<' ';
			else{
				left->show(pad+lazy);
				right->show(pad+lazy);
			}
		}
	};
	segmentTree::pointer tree;
	void getAnswer(int f, int g){
		sort(w[f][g].begin(), w[f][g].end(), [](query A, query B){
			return A.v<B.v;
		});
		tree=new segmentTree(1, n);
		int r=1;
		stack <pair <long long, int>> d;
		for(query q: w[f][g]){
			while(r<=q.v){
				long long weight=s[2][r]-s[g][r-1];
				tree->update(r, r, s[f][r]-s[2][r-1]+weight);
				int done=r;
				while((!d.empty())&&(d.top().first<weight)){
					tree->update(d.top().second, done-1, weight-d.top().first);
					done=d.top().second;
					d.pop();
				}
				d.push({weight, done});
				r++;
				
			}
			ans[q.id]=s[g][q.v]-s[f][q.y-1]+tree->get(q.y, q.v);
		}
	}
	void solve(){
		for(int i=1; i<3; i++) subtask2::makeTree(i, i+1);
		for(int i=3; i>1; i--) subtask2::makeTree(i, i-1);
		for(int i=1; i<=qCnt; i++){
			if(abs(q[i].x-q[i].u)<=1){
				ans[q[i].id]=subtask2::getAnswer(q[i].x, q[i].y, q[i].u, q[i].v);
			}
			else{
				if(q[i].y>q[i].v){
					swap(q[i].y, q[i].v);
					swap(q[i].u, q[i].x);
				}
				w[q[i].x][q[i].u].push_back(q[i]);
			}
		}
		getAnswer(1, 3);
		getAnswer(3, 1);
	}
}
int main(){
	freopen("BONUS3ROWS.INP", "r", stdin);
	freopen("BONUS3ROWS.OUT", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin>>n>>qCnt;
	for(int i=1; i<=3; i++) for(int j=1; j<=n; j++){
		cin>>a[i][j];
		s[i][j]=s[i][j-1]+a[i][j];
	}
	for(int i=1; i<=qCnt; i++){
		cin>>q[i].x>>q[i].y>>q[i].u>>q[i].v;
		q[i].id=i;
	}
	// subtask1::solve();
	// subtask2::solve();
	subtask3::solve();
	for(int i=1; i<=qCnt; i++) cout<<ans[i]<<'\n';
}