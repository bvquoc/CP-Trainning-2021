#include<bits/stdc++.h>
using namespace std;	
const long long oo = 1e12;
const long long maxN = 2e5 +  500;
//vector<pair<int, int>> f[maxN];
long long f[25][maxN];
vector<pair<int, int> > a[maxN];
//vector<long long> a[maxN];
vector<long long> bank;
long long dp[maxN * 2][25];
pair<int, int> pb;
struct data {
    long long dinh;
    long long dodai;
    bool operator < (const data & temp) const {
        return dodai > temp.dodai;
    }
    data(long long _a, long long _b) {
        dinh = _a;
        dodai= _b;
    }
};
priority_queue<data> s;
void Dijkstra(long long node, long long _dinh) {
	while(!s.empty()) {
		_dinh = s.top().dinh;
		s.pop();
		for(int i = 0;i <= (int)(a[_dinh].size()) - 1; i++) {
            if(f[node][_dinh] + a[_dinh][i].second < f[node][a[_dinh][i].first]) {
                 f[node][a[_dinh][i].first] = f[node][_dinh] + a[_dinh][i].second;
                 s.push(data(a[_dinh][i].first, f[node][a[_dinh][i].first]));
             }
        }
    }
}
int main()
{
	long long tam,tam2,tam3,n,m,p,l,k;
	cin >> n >> m >> p >> l >> k;
	for(int i = 1; i <= m; i++) {
		cin >> tam >> tam2 >> tam3;
		pb.first = tam2;
		pb.second = tam3;
		a[tam].push_back(pb);
		pb.first = tam;
		pb.second = tam3;
		a[tam2].push_back(pb);
	}
	memset(f, 1000000, sizeof(f));
	f[1][1] = 0;
	s.push(data(1, 0));
	Dijkstra(1, 1);
	cout << f[1][n];
}
