#include <bits/stdc++.h>
using namespace std;
// #define int int64_t
int n;
const int base=999999937;
void add(long long &u, int v){
	u+=v;
	if(u>=base) u-=base;
}
void add(int &u, int v){
	u+=v;
	if(u>=base) u-=base;
}
namespace subtask1{
	//n<=6 nên chỉ có 10^6 số. Ta có thể duyệt tất cả các số rồi kiểm tra. 
	int f(int n){
		int x=1;
		for(int i=1; i<=n; i++) x*=10;
		int ans=0;
		for(int i=0; i<x; i++){
			int f=0;
			int u=i;
			while(u){
				f|=(1<<(u%10));
				u/=10;
			}
			for(int j=1; j<=9; j++) if((f>>j)&1){
				if(i%j) goto line0;
			}
			ans++;
			line0:;
		}
		return ans;
	}
	void solve(){
		cout<<f(n);
	}
}
namespace subtask2{
	//n<=8 thì ta không thể chạy code kịp trong time limit, trừ khi tối ưu rất nhiều.
	//Vì chỉ có 8 giá trị khác nhau thôi, nên thực ra ta có thể tính trước kết quả và chỉ in ra
	//Chạy code sẽ mất khoảng 30s.
	int ans[]={0, 10, 33, 138, 752, 4578, 29951, 207198, 1495638};
	void prepare(){
		for(int i=1; i<=8; i++){
			cerr<<subtask1::f(i)<<", ";
			cerr.flush();
		}
	}
	void solve(){
		// prepare();
		cout<<ans[n];
	}
}
namespace subtask3{
	//Ta có thể quy hoạch động là đã chọn số nào, và mod cho các số này là bao nhiêu.
	//Có 2^8 cách để chọn số, vì ta không cần quan tâm đến số 1 và 0
	//Có 2*3*4*5*6*7*8*9 cách để chọn mod 
	//Vậy thì có 92897280 trạng thái, không thể quy hoạch động được.
	//Nhận thấy là biết số dư khi chia cho 8 thì ta cũng biết số dư khi chia cho 4 và 2, nên thực ra chỉ cần lưu lại số dư khi chia cho 8 là đủ. 
	//Tương tự, chỉ cần lưu số dư khi chia cho 9 mà không cần lưu 3. 
	//Biết được số dư khi chia cho 2 và 3 từ 8 và 9, từ đó tính được số dư khi chia cho 6. 
	//Vậy thì thực tế ta chỉ cần lưu số dư khi chia cho 5, 7, 8, 9.
	//Để đơn giản việc code, ta có thể chỉ lưu lại số dư khi chia cho 2520=5*7*8*9
	//Một cách khác để nhận thấy việc này là 2520=lcm(2, 3, 4, ...,8, 9). Nếu biết được số dư khi chia cho lcm(x1, x2, ..., xn) thì ta biết được số dư khi chia cho mọi giá trị xi
	//Số trạng thái bây giờ là 2520*2^8=645120, đủ để quy hoạch động với n=30
	const int mod=2520;
	int f[1<<8][mod];
	int g[1<<8][mod];
	void getAnswer(){
		int ans=0;
		for(int i=0; i<256; i++){
			vector <int> list;
			for(int j=0; j<8; j++) if((i>>j)&1) list.push_back(j+2);
			for(int j=0; j<mod; j++){
				for(int x: list) if(j%x) goto line1;
				add(ans, f[i][j]);
				line1:;
			}
		}
		cout<<ans<<'\n';
	}
	void solve(){
		f[0][0]=1;
		for(int cnt=0; cnt<n; cnt++){
			for(int i=0; i<256; i++) for(int j=0; j<mod; j++) g[i][j]=0;
			for(int i=0; i<256; i++) for(int j=0; j<mod; j++) if(f[i][j]){
				for(int d=0; d<=1; d++) add(g[i][(j*10+d)%mod], f[i][j]);
				for(int d=2; d<=9; d++) add(g[i|(1<<(d-2))][(j*10+d)%mod], f[i][j]);
			}
			for(int i=0; i<256; i++) for(int j=0; j<mod; j++) f[i][j]=g[i][j];
		}
		getAnswer();
	}
}
namespace subtask4{
	//Nhận xét thêm từ subtask 3 là ta thực ra không cần phải biết rõ là dùng những số nào, chỉ cần biêt là cái lcm của tất cả các chữ số được dùng là bao nhiêu.
	//Nhận thấy là lcm của các số từ 1 đến 9 có dạng là 5*7*8*9=2^3*3^2*5*7, nên có được 4*3*2*2 ước khác nhau, tức là chỉ có 48 cái lcm ta cần quan tâm đến.
	//Số trạng thái trở thành trở thành 48*2520=120960, đủ chạy được n=200.
	const int states=48;
	const int mod=2520;
	int s[states];
	int nx[states][10];
	int f[states][mod];
	int g[states][mod];
	void getAnswer(){
		long long ans=0;
		for(int i=0; i<states; i++)	for(int j=0; j<mod; j+=s[i]) add(ans, f[i][j]);
		cout<<ans<<'\n';
	}
	int lcm(int a, int b){
		if(a==0) return b;
		if(b==0) return a;
		int d=__gcd(a, b);
		return a/d*b;
	}
	void solve(){
		int c=0;
		for(int i=1; i<=8; i*=2){
			for(int j=1; j<=9; j*=3){
				for(int k=1; k<=5; k*=5){
					for(int l=1; l<=7; l*=7){
						s[c]=i*j*k*l;
						c++;
					}
				}
			}
		}
		for(int i=0; i<states; i++){
			for(int d=0; d<10; d++){
				int f=lcm(d, s[i]);
				while(s[nx[i][d]]!=f) nx[i][d]++;
			}
		}
		f[0][0]=1;
		for(int cnt=0; cnt<n; cnt++){
			for(int i=0; i<states; i++) for(int j=0; j<mod; j++) g[i][j]=0;
			for(int i=0; i<states; i++) for(int j=0; j<mod; j++) if(f[i][j]){
				for(int d=0; d<=9; d++) add(g[nx[i][d]][(j*10+d)%mod], f[i][j]);
			}
			for(int i=0; i<states; i++) for(int j=0; j<mod; j++) f[i][j]=g[i][j];
		}
		getAnswer();
	}
}
int main(){
	freopen("NDNUM.INP", "r", stdin);
	freopen("NDNUM.OUT", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	// subtask2::solve();
	// subtask3::solve();
	subtask4::solve();
	
}