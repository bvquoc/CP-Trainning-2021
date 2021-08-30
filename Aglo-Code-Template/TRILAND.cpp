#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define x first
#define y second
typedef pair<int,int> point;
typedef vector <point> Points;

void operator -= (point &A, point B){ A.x-=B.x; A.y-=B.y; }
bool ccw(point O, point A, point B) { A-=O, B-=O; return A.x*B.y > A.y*B.x; }
point origin;

long double Area(point a, point b, point c) {
	point p[5];
	p[1] = a; p[2] = b; p[3] = c; p[4] = a;
	long double s=0.0;
	for (int i=1;i<=3;i++) 
		s+=(p[i+1].x-p[i].x)*(p[i+1].y+p[i].y);
	s = (long double)(abs(s))/2.0;
	return s;
}

int n; Points a, CVH;
long double res=0.0;

int32_t main(void){
	freopen("TRILAND.INP","r",stdin);
	freopen("TRILAND.OUT","w",stdout);
	cin >> n; a.resize(n+2);
	for (size_t i=1;i<=n;i++) 
		cin >> a[i].x >> a[i].y;
	
	//Find Convex Hull
	sort(a.begin()+1,a.end()-1);
	origin = a[1];
	sort(a.begin()+2,a.end()-1,[](const point &A, point &B){ 
		return ccw(origin, A, B); 
	});
	
	a[0] = a[n]; a[n+1] = a[1];
	int j=1;
	for (size_t i=1; i<=n+1; i++) {
		while (j>2 && !ccw(a[j-2],a[j-1],a[i])) j--;
		a[j++]=a[i];
	}
	for (size_t i=1;i<=j-2;i++) CVH.push_back(a[i]);
	
	// Solve
	for (size_t i=0;i<CVH.size()-2;i++) {
		size_t k = i+2;
		for (size_t j=i+1;j<CVH.size()-1;j++) {
			long double s=Area(CVH[i],CVH[j],CVH[k]);
			while (k<CVH.size()-1) {
				long double _s=Area(CVH[i],CVH[j],CVH[k+1]);
				if (s<_s) {
					s=_s;
					k++;
				} else break;
			}
			res = max(res,s);
		}
	}
	cout << fixed << setprecision(1) << res;
	return 0;
}
