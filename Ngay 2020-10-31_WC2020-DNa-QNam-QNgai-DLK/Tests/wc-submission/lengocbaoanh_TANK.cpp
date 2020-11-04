#include<bits/stdc++.h>
using namespace std;
const long long maxN = 1e6 + 500;
long long a[maxN];
int main()
{
	long long m,ans = 0,n,sum = 0,j;
	cin >> m >> n;
	j = 1;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) {
		sum = sum + a[i];
		while(sum - a[j] > m) {
			sum -= a[j];
			j++;
		}
		ans = max(ans, i - j + 1);
	}
	cout << ans << endl;
}
