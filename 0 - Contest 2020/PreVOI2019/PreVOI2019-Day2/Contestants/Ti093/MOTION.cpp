#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;
const int BIG = 1e9 + 555;

struct Point {
	double x, y;
	Point(){};
	Point(double _x, double _y) : x((double)_x), y((double)_y) {};

	Point operator - (const Point &other){
		return Point(x - other.x, y - other.y);
	}
};

ll m, n, nTest;

ll gcd(ll a, ll b){
	if(a == 0){
		return b;
	}

	return gcd(b % a, a);
}

Point move(Point s, Point &delta, double t){
	Point f = Point((double)(s.x + delta.x * t), (double)(s.y + delta.y * t));
	//cerr << "t = " << t << '\n';
	
	//cerr << "! " << f.x << ' ' << f.y << '\n';
	for(int i = 100; i >= 1; i--){
		if(i * m < f.x && f.x < (i + 1) * m){
			f.x = i * m - (f.x - i * m);
			//cerr << "x = " << f.x << '\n';
		}
	}

	for(int i = -100; i <= -1; i++){
		if(i * m < f.x && f.x < (i + 1) * m){
			f.x = 2 * (i + 1) * m - f.x;
			//cerr << "x = " << f.x << '\n';
		}
	}

	for(int i = 100; i >= 1; i--){
		if(i * n < f.y && f.y < (i + 1) * n){
			f.y = i * n - (f.y - i * n);
			//cerr << "y = " << f.y << '\n';
		}
	}

	for(int i = -100; i <= -1; i++){
		if(i * n < f.y && f.y < (i + 1) * n){
			f.y = 2 * (i + 1) * n - f.y;
			//cerr << "y = " << f.y << '\n';
		}
	}
	
	//cerr << f.x << ' ' << f.y << '\n';

	return f;
}

const double EPS = 1e-10;

void sub1(){
	while(nTest--){
		Point a, b, c, d;
		cin >> m >> n >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
		
		ll optP = BIG, optQ = 1;
		bool flag = false;

		for(ll nu = 0; nu <= 100; nu++){
			for(ll de = 1; de <= 100; de++){
				ll g = gcd(nu, de);
				ll p = nu / g;
				ll q = de / g;

				Point delta0 = b - a;
				Point delta1 = d - c;

				Point motion0 = move(a, delta0, (double)p / (double)q);
				Point motion1 = move(c, delta1, (double)p / (double)q);

				if((fabs(motion0.x - motion1.x) < EPS) && (fabs(motion0.y - motion1.y) < EPS)){
					flag = true;
					if(p * optQ < q * optP){
						optP = p, optQ = q;
					}
				}
			}
		}
		
		if(!flag){
			cout << "-1\n";
			continue;
		}

		cout << optP << ' ' << optQ << '\n';
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("MOTION.INP", "r", stdin);
	freopen("MOTION.OUT", "w", stdout);
	
	cerr << setprecision(10) << fixed;

	cin >> nTest;

	if(nTest <= 10){
		sub1();
		return 0;
	}

	return 0;
}