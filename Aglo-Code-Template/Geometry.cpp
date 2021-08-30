struct Point {
	int x, y;
	Point(int _x = 0, int _y = 0) { x = _x; y = _y; }

	Point operator + (const Point &a) const { return Point(x + a.x, y + a.y); }
	Point operator - (const Point &a) const { return Point(x - a.x, y - a.y); }
	Point operator * (int k) const { return Point(x * k, y * k); }
};

struct Line {
	// ba hệ số của phương trình tổng quát ax + by + c = 0
	int a, b;
	long long c;
	// constructor dựng đường thẳng đi qua hai điểm m và n
	Line(const Point &m, const Point &n) {
		// xác định hệ số theo công thức
		a = m.y - n.y;
		b = n.x - m.x;
		c = -(1LL * a * m.x + 1LL * b * m.y);

		// chuẩn hóa đường thẳng
		int t = gcd(a, b, c);
		a /= t; b /= t; c /= t;
		if (a < 0 || (a == 0 && b < 0)) {
			a = -a; b = -b; c = -c;
		}
	}

	// kiểm tra điểm p có nằm trên đường thẳng hay không
	bool contain(const Point &p) const {
		return 1LL * a * p.x + 1LL * b * p.y + c == 0;
	}

	Point intersect(const Line &l) const {
		int a1 = a, b1 = b;
		long long c1 = -c;
		int a2 = l.a, b2 = l.b;
		long long c2 = -l.c;
		
		long long d = 1LL * a1 * b2 - 1LL * a2 * b1;
		long long dx = c1 * b2 - c2 * b1;
		long long dy = a1 * c2 - a2 * c1;

		if (d == 0) NA;
		else return Point(dx / d, dy / d); // giao điểm duy nhất tại tọa độ dx/d, dy/d
	}
};

// xoay điểm b quanh tâm a một góc alpha ngược chiều kim đồng hồ
// sin(a+b) = sin(a) * cos(b) + sin(b) * cos(a)
// cos(a+b) = cos(a) * cos(b) - sin(a) * sin(b)
Point rotate(const Point &a, const Point &b, double alpha) {
	Point ab = b - a; // vector a -> b;

	Point new_ab = Point(ab.x * cos(alpha) - ab.y * sin(alpha),
				ab.y * cos(alpha) + sin(alpha) * ab.x);
	return a + new_ab;
}
