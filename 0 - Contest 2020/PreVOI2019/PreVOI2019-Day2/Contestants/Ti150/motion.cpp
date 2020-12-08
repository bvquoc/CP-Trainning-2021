#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

int n, m, x, y, z, t, x_, y_, z_, t_;
pair<int, int> pa, pb, va, vb;

void prep()
{
	cin>>n>>m>>x>>y>>x_>>y_>>z>>t>>z_>>t_;
	pb={z, t};
	vb={z_-z, t_-t};
	pa={x, y};
	va={x_-x, y_-y};
	if(va.first<0)
	{
		va.first=-va.first;
		pa.first=-pa.first;
	}
	if(va.second<0)
	{
		va.second=-va.second;
		pa.second=-pa.second;
	}
	if(vb.first<0)
	{
		vb.first=-vb.first;
		pb.first=-pb.first;
	}
	if(vb.second<0)
	{
		vb.second=-vb.second;
		pb.second=-pb.second;
	}
	while(pa.first<0) pa.first+=2*m;
	while(pb.first<0) pb.first+=2*m;
	while(pa.second<0) pa.second+=2*n;
	while(pb.second<0) pb.second+=2*n;
}

pair<int, int> toigian(int a, int b)
{
	if(a<0)
	{
		a=-a, b=-b;
	}
	int ax=__gcd(a, b);
	return {a/ax, b/ax};
}

pair<int, int> inverse(int a, int b)
{
	if(b==0)
	{
		return {1, 0};
	}
	else
	{
		pair<int, int> khonglienquanlam=inverse(b, a%b);
		pair<int, int> res={khonglienquanlam.second, khonglienquanlam.first-khonglienquanlam.second*(a/b)};
		return {res.first, res.second};
	}
}

pair<int, int> getans(int a, int b, int c, int d, int e, int f)
{
	int a1=a*b, b1=b*f-c*e, c1=a*e;
	int dm=__gcd(a1, __gcd(b1, c1));
	a1/=dm;
	b1/=dm;
	c1/=dm;
	if(__gcd(a1, c1)!=1) return {1, 0};
	int ax=inverse(a1, c1).first;
	int miny=(ax*(-b1)+c1*1000000)%c1;
	return {miny*d+f, e};
}

pair<int, int> gmin(pair<int, int> a, pair<int, int> b)
{
	if(a.f*b.s>a.s*b.f)
	{
		return a;
	}
	else
	{
		return b;
	}
}

void solve()
{
	pair<int, int> ans={1, 0};
	prep();

	//x di nguoc
	int sx=pa.first+pb.first;
	int px=(sx)/(2*m); 
	if(sx%(2*m)!=0) px++;
	px*=2*m;

	px-=sx;
	pair<int, int> fx1={px-sx, va.f+vb.f}, tx1={2*m, va.f+vb.f};
	//y di nguoc
	int sy=pa.s+pb.s;
	int py=(sy)/(2*n); 
	if(sy%(2*n)!=0) py++;
	py*=2*n;

	py-=sy;
	pair<int, int> fy1={py-sy, va.s+vb.s}, ty1={2*n, va.s+vb.s};

	//y di xuoi
	sy=pa.s-pb.s;
	py=(sy)/(2*n); 
	if(sy%(2*n)!=0) py++;
	py*=2*n;
	py-=sy;
	pair<int, int> fy2={abs(py-sy), abs(va.s-vb.s)}, ty2={2*n, abs(va.s-vb.s)};
	//x di xuoi
	sx=pa.s-pb.s;
	px=(sx)/(2*m); 
	if(sx%(2*n)!=0) px++;
	px*=2*m;
	px-=sx;
	pair<int, int> fx2={abs(px-sx), abs(va.f-vb.f)}, tx2={2*m, abs(va.f-vb.f)};

	if(fx1.second!=0&&fy1.second!=0) ans=gmin(ans, getans(fx1.first, fx1.second, tx1.first, fy1.first, fy1.second, ty1.first));
	if(fx2.second!=0&&fy1.second!=0) ans=gmin(ans, getans(fx2.first, fx2.second, tx2.first, fy1.first, fy1.second, ty1.first));
	if(fx1.second!=0&&fx2.second!=0) ans=gmin(ans, getans(fx1.first, fx1.second, tx1.first, fy2.first, fy2.second, ty2.first));
	if(fx2.second!=0&&fy2.second!=0) ans=gmin(ans, getans(fx2.first, fx2.second, tx2.first, fy1.first, fy1.second, ty1.first));

	ans=toigian(ans.first, ans.second);
	if(ans.second==0) cout<<-1<<'\n';
	else cout<<ans.first<<" "<<ans.second<<'\n';
}

signed main()
{
	freopen("motion.inp", "r", stdin);
	freopen("motion.out", "w", stdout);
	ios::sync_with_stdio(false);
	int tests;
	cin>>tests;
	for(int test=1; test<=tests; test++)
	{
		solve();
	}
}