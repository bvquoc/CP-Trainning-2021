#include <bits/stdc++.h>
using namespace std;
long long w, h, l;
using ld=long double;
#define double ld
namespace subtask1{
	//Vì w, h khá là bé, ta có thể mô phỏng trực tiếp bằng số thực mà không lo sai số
	const double epsilon=1e-9;
	class ray{
	public:
		double a, b;//Vì ta sẽ không bao giờ gặp tia song song với Ox hoặc Oy, có thể sử dụng y=ax+b
		double x;//tọa độ x của gốc của tia
		bool d;//tia đi theo chiều x tăng hay x giảm
		ray (double a, double b, double x, bool d): a(a), b(b), x(x), d(d){}
		double yAt(double x0){//trả về tọa độ y0 tương ứng với x0 trên tia
			return a*x0+b;
		}
		double xAt(double y0){//trả về tọa độ x0 tương ứng với y0 trên tia
			return (y0-b)/a;
		}
	};
	ray fromSlopeAndStart(double a, double x, double y, bool d){//tạo ra tia từ hệ số góc, điểm bắt đầu và hướng
		return ray(a, y-x*a, x, d);
	}
	void solve(){
		int ans=0;
		ray r(double(h)/l, 0, 0, 1);//tia ban đầu có gốc ở (0, 0), có phương trình là y=(h/l)x+0 và có hướng theo x tăng
		while(true){
			int dir=0;//không cắt cạnh nào
			if(r.d){//đi sang phải
				double y=r.yAt(w);
				if(abs(y)<epsilon) break;//đi ra ở góc phải dưới
				if(abs(y-h)<epsilon) break;//đi ra ở góc phải trên
				ans++;
				if((y>-epsilon)&&(y<epsilon+h)){//tia cắt cạnh phải trong cạnh, chứng tỏ cạnh này là cạnh sẽ phải lại tia
					//phản lại một gương thẳng đứng thì hệ số góc đảo thành số âm, hướng của x đảo ngược lại 
					r=fromSlopeAndStart(-r.a, w, y, !r.d);
				}
				else if(y>0) dir=1;//cắt cạnh trên
				else dir=2;//cắt cạnh dưới
			}
			else{//đi sang trái
				double y=r.yAt(0);
				if(abs(y)<epsilon) break;//đi ra ở góc trái dưới
				if(abs(y-h)<epsilon) break;//đi ra ở góc trái trên
				ans++;
				if((y>-epsilon)&&(y<epsilon+h)){//tia cắt cạnh trái trong cạnh, chứng tỏ cạnh này là cạnh sẽ phải lại tia
					//phản lại một gương thẳng đứng thì hệ số góc đảo thành số âm, hướng của x đảo ngược lại 
					r=fromSlopeAndStart(-r.a, 0, y, !r.d);
				}
				else if(y>0) dir=1;//cắt cạnh trên
				else dir=2;//cắt cạnh dưới
			}
			if(dir==1){//cắt cạnh trên
				double x=r.xAt(h);
				//phản lại một gương nằm ngang thì hệ số góc đảo thành số âm, hướng của x giữ nguyên
				r=fromSlopeAndStart(-r.a, x, h, r.d);
			}
			else if(dir==2){//cắt cạnh dưới
				double x=r.xAt(0);
				//phản lại một gương nằm ngang thì hệ số góc đảo thành số âm, hướng của x giữ nguyên
				r=fromSlopeAndStart(-r.a, x, 0, r.d);
			}
		}
		cout<<ans<<'\n';
	}
}
namespace subtask2{
	//Nhận thấy là vẫn có thể mô phỏng từng bước được, nhưng nếu ra dùng số thực thì dẫn đến bị sai số
	//Để làm được thì cần dùng phân số (fraction)
	class fraction{
	public:
		long long a, b;
		fraction(long long x): a(x), b(1){}
		fraction(long long _a, long long _b): a(_a), b(_b){
			long long d=__gcd(abs(a), abs(b));
			a/=d;
			b/=d;
			if(a==0) b=1;
			else if(b<0){
				a=-a;
				b=-b;
			}
		}
		fraction operator -(){
			return fraction(-a, b);
		}
		fraction operator * (fraction f){
			return fraction(a*f.a, b*f.b);
		}
		fraction operator / (fraction f){
			return fraction(a*f.b, b*f.a);
		}
		fraction operator + (fraction f){
			return fraction(a*f.b+b*f.a, b*f.b);
		}
		fraction operator - (fraction f){
			return fraction(a*f.b-b*f.a, b*f.b);
		}
		bool operator == (fraction f){
			return a*f.b==b*f.a;
		}
		bool operator >(fraction f){
			return a*f.b>b*f.a;
		}
		bool operator <(fraction f){
			return a*f.b<b*f.a;
		}
		friend ostream& operator << (ostream& out, fraction f){
			return out<<(double(f.a)/f.b);
		}
	};
	class ray{
	public:
		fraction a, b;//Vì ta sẽ không bao giờ gặp tia song song với Ox hoặc Oy, có thể sử dụng y=ax+b
		fraction x;//tọa độ x của gốc của tia
		bool d;//tia đi theo chiều x tăng hay x giảm
		ray (fraction a, fraction b, fraction x, bool d): a(a), b(b), x(x), d(d){}
		fraction yAt(fraction x0){//trả về tọa độ y0 tương ứng với x0 trên tia
			return a*x0+b;
		}
		fraction xAt(fraction y0){//trả về tọa độ x0 tương ứng với y0 trên tia
			return (y0-b)/a;
		}
	};
	ray fromSlopeAndStart(fraction a, fraction x, fraction y, bool d){//tạo ra tia từ hệ số góc, điểm bắt đầu và hướng
		return ray(a, y-x*a, x, d);
	}
	void solve(){
		int ans=0;
		ray r(fraction(h, l), 0, 0, 1);//tia ban đầu có gốc ở (0, 0), có phương trình là y=(h/l)x+0 và có hướng theo x tăng
		while(true){
			int dir=0;//không cắt cạnh nào
			if(r.d){//đi sang phải
				fraction y=r.yAt(w);
				if(y==0) break;//đi ra ở góc phải dưới
				else if(y==h) break;//đi ra ở góc phải trên
				ans++;
				if((y>0)&&(y<h)){//tia cắt cạnh phải trong cạnh, chứng tỏ cạnh này là cạnh sẽ phải lại tia
					//phản lại một gương thẳng đứng thì hệ số góc đảo thành số âm, hướng của x đảo ngược lại 
					r=fromSlopeAndStart(-r.a, w, y, !r.d);
				}
				else if(y>0) dir=1;//cắt cạnh trên
				else dir=2;//cắt cạnh dưới
			}
			else{//đi sang trái
				fraction y=r.yAt(0);
				if(y==0) break;//đi ra ở góc trái dưới
				else if(y==h) break;//đi ra ở góc trái trên
				ans++;
				if((y>0)&&(y<h)){//tia cắt cạnh trái trong cạnh, chứng tỏ cạnh này là cạnh sẽ phải lại tia
					//phản lại một gương thẳng đứng thì hệ số góc đảo thành số âm, hướng của x đảo ngược lại 
					r=fromSlopeAndStart(-r.a, 0, y, !r.d);
				}
				else if(y>0) dir=1;//cắt cạnh trên
				else dir=2;//cắt cạnh dưới
			}
			if(dir==1){//cắt cạnh trên
				fraction x=r.xAt(h);
				//phản lại một gương nằm ngang thì hệ số góc đảo thành số âm, hướng của x giữ nguyên
				r=fromSlopeAndStart(-r.a, x, h, r.d);
			}
			else if(dir==2){//cắt cạnh dưới
				fraction x=r.xAt(0);
				//phản lại một gương nằm ngang thì hệ số góc đảo thành số âm, hướng của x giữ nguyên
				r=fromSlopeAndStart(-r.a, x, 0, r.d);
			}
		}
		cout<<ans<<'\n';
	}
}
namespace subtask3{
	//Thay vì cho tia sáng phản chiếu thì ta có thể tưởng tượng có một hộp khác ở bên cạnh, và tia sáng sẽ đi vào đó.
	//Vậy thì bài toán trở thành tìm đầu tiên có dạng (a*w, b*h) tia y=(h/l)*x đi qua điểm này.
	//Có b*h=a*w*h/l=>b=a*w/l. Điểm đầu tiên thì sẽ có a bé nhất mà a*w/l là một số nguyên, tức là đi tìm a dương bé nhất sao cho a*w chia hết cho l
	//cái này đơn giản bằng l/gcd(w, l)
	//Nếu ta đã biết được là đi đến một điểm (a*w, b*h) thì kết quả đơn giản là a-1+b-1 (tổng số cạnh mà đoạn (0, 0)-(a*w, b*h) cắt)
	void solve(){
		long long a=l/__gcd(w, l);
		long long b=a*w/l;
		cout<<a+b-2<<'\n';
	}
}
int main(){
	freopen("REFLECTION.INP", "r", stdin);
	freopen("REFLECTION.OUT", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>w>>h>>l;
	// subtask1::solve();
	// subtask2::solve();
	subtask3::solve();
	
}