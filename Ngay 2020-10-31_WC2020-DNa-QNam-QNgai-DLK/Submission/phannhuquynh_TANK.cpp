#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int N = 1e6 + 10;
int n, a[N];
ll s[N], M;

int check(int x){
		for(int i = 1; i <= n - x + 1; i++){
				int j = i + x - 1;
				if (s[j] - s[i - 1] < M) return 0;
		}
		return 1;
}
int main(){
		ios_base :: sync_with_stdio(false);
		cin.tie(0); cout.tie(0);
//		freopen("TANK.INP", "r", stdin);
//		freopen("TANK.OUT", "w", stdout);
		
		cin >> M >> n;
		
		s[0] = 0;
		for(int i = 1; i <= n; i++){
				cin >> a[i];
				s[i] = s[i - 1] + a[i];
		}
		
		int d = 1, c = n, res;
		while (d <= c){
				int mid = (d + c) / 2;
				if (check(mid)) res = mid, c = mid - 1;
				else d = mid + 1;
		}
		
		cout << res;
}
