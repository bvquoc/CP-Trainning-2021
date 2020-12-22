#include <bits/stdc++.h>
using namespace std;
int n, k;
namespace subtask1{
	//Nhận thấy là ở mọi thời điểm lấy tiền, ta luôn lấy tối đa số tiền có thể
	//Có thể chứng minh được nếu ta để lại tiền ở các vị trí y1, y2, y3, ... trong cả quá trình, thì cách đi được xa nhất luôn là đem tối đa tiền đến vị trí nghỉ nhỏ nhất, sau đó đem tối đa đến vị trí thứ hai, ...
	//Vậy thì có thể quy hoạch động f[i] là số tiền tối đa có thể đem đến vị trí i. 
	//Vì ta không thể đi quá n, chỉ cần quy hoạch động đến n. Gọi f[i] là số tiền tối đa mà ta có thể mang đến i.
	//Ban đầu, tất cả f[i]<0
	//f[0]=n
	//Để tính f[i], duyệt tất cả các f[j], j<i và giả sử ta sẽ đi thằng từ j đến i.
	//Từ i có f[i] đồng, cách tối ưu thì luôn là mang tối đa tiền, đi từ j đến i và để lại toàn bộ tiền, rồi lặp lại đến khi không đi được.
	int f[1001];
	void solve(){
		int ans=0;
		for(int i=0; i<=n; i++) f[i]=-1;
		f[0]=n;
		for(int i=1; i<=n; i++){
			for(int j=0; j<i; j++){
				int best=f[j]/k;//số lần mà ta có thể đi bằng k đồng
				if(best==0) break;//dễ thấy được f[j] giảm dần.
				f[i]=max(f[i], best*(k-(i-j)));//Mỗi lần ta để lại được k-(i-j) đồng vì đem đi k và sử dụng mất i-j
				f[i]=max(f[i], best*(k-(i-j))+f[j]%k-(i-j));//Đi thêm một lần nữa với những đồng còn lại sau best lần.
			}
			if(f[i]<0) break;//dễ thấy được f[i] giảm dần.
			ans=i;
		}
		cout<<ans+1<<'\n';
	}
}
namespace subtask23{
	//Nhận thấy ta có các phép biến đổi 
		// f[i]=max(f[i], best*(k-(i-j)));//Mỗi lần ta để lại được k-(i-j) đồng vì đem đi k và sử dụng mất i-j
		// f[i]=max(f[i], best*(k-(i-j))+f[j]%k-(i-j));//Đi thêm một lần nữa với những đồng còn lại sau best lần.
	//Thì thực ra các phép này là hàm tuyến tính của i nếu ta đã biết được j.
	//Vậy thì ta có thể sử dụng cấu trúc dữ liệu segment tree lưu đoạn tuyến tính (IT đoạn thẳng/lichao tree) để làm.
	//Độ phức tạp là O(nlog(n)) nếu làm như vậy, và sẽ qua được subtask 2
	//Để làm được subtask 3 thì phải nhận ra được hệ số góc của các đường là -best và -best-1. Nếu ta tách cái này làm hai loại -best và -best-1 thì 
	//sẽ đảm bảo hệ số góc tăng dần (vì best=f[i]/k giảm dần). Khi hệ số góc tăng dần thì ta có thể dùng convex hull trick để giải được trong O(n).
	class ConvexHullTrick{
	public:
		class line{
		public:
			long long a, b;//y=ax+b
			line(long long a, long long b): a(a), b(b){}
			long long at(long long x){
				return a*x+b;  
			}
			long long findFirst(line L){//find the first possition that this >= L
				// a*x+b>=L.a*x+L.b
				// <=>x(a-L.a)>=L.b-b
				long long x=(L.b-b)/(a-L.a);
				while(at(x)<L.at(x)) x++;
				return x;
			}
		};
		deque <pair <line, long long>> L;
		void addLine(long long a, long long b){
			line A(a, b);
			if(L.empty()){
				L.push_back({A, 0});
			}
			else{
				
				while((!L.empty())&&(L.back().first.at(L.back().second)<=A.at(L.back().second))){
					// assert(L.back().first.a<=A.a);
					L.pop_back();
				}
				if(L.empty()){
					L.push_back({A, 0});
				}
				else if(A.at(n)>L.back().first.at(n)){
					L.push_back({A, A.findFirst(L.back().first)});
				}
			}
		}
		long long find(long long x){//x will increase
			if(L.empty()) return -1;
			while((L.size()>1)&&(L[1].second<=x)) L.pop_front();
			return L[0].first.at(x);
		}
	} A, B;
	void solve(){
		int ans=0;
		A.addLine(-n, n);
		for(int i=0; i<=n; i++){
			int best=max(A.find(i), B.find(i));
			if(best<=0) break;
			ans=max(ans, i+min(best, k));
			int complete=best/k;
			A.addLine(-complete, complete*(k+i));
			if(best%k) B.addLine(-complete-1, complete*(k+i)+best%k+i);
		}
		cout<<ans+1<<'\n';
	}
}
int main(){
	freopen("TOLLBOOTHS.INP", "r", stdin);
	freopen("TOLLBOOTHS.OUT", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>k;
	// subtask1::solve();
	subtask23::solve();
}