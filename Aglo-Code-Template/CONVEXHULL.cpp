#include <bits/stdc++.h>
using namespace std;
#define int int64_t
struct point {
	int x, y;
	point() {
		x = 0;
		y = 0;
	}
	point(int _x, int _y) {
		x = _x;
		y = _y;
	}
	bool operator< (point b) { return (y < b.y || (y == b.y && x < b.x)); }
	void operator-= (point v) {
		x -= v.x;
		y -= v.y;
	}
};

typedef vector<point> Points;

bool ccw(point O, point A, point B) {
	A -= O, B -= O;
	return A.x * B.y > A.y * B.x;
}

point origin;
long double Area(Points a) {
	Points p;
	size_t n = a.size();
	p.push_back(a[n - 1]);
	for (point x : a)
		p.push_back(x);
	p.push_back(a[0]);
	long double res = 0.0;
	for (size_t i = 1; i <= n; i++)
		res += (p[i + 1].x - p[i].x) * (p[i + 1].y + p[i].y);
	res = (long double)(abs(res)) / 2.0;
	return res;
}

int n;
Points a, ConvexHull;

int32_t main(void) {
	freopen("CONVEXHULL.INP", "r", stdin);
	freopen("CONVEXHULL.OUT", "w", stdout);
	cin >> n;
	a.resize(n+2);
	for (int i=1; i<=n; i++)
		cin >> a[i].x >> a[i].y;
	
	sort(a.begin() + 1, a.end() - 1);
	origin = a[1];
	sort(a.begin() + 2, a.end() - 1, [](const point &A, point &B) {
		return ccw(origin, A, B);
	});
	
	a[0] = a[n];
	a[n + 1] = a[1];
	int j = 1;
	for (size_t i=1; i<=n+1; i++) {
		while (j>2 && !ccw(a[j-2], a[j-1], a[i]))
			j--;
		a[j++] = a[i];
	}

	for (size_t i=1; i<=j-2; i++)
		ConvexHull.push_back(a[i]);
	cout << ConvexHull.size() << endl;
	cout << fixed << setprecision(1) << Area(ConvexHull) << endl;
	for (point p : ConvexHull)
		cout << p.x << " " << p.y << endl;
	return 0;
}
