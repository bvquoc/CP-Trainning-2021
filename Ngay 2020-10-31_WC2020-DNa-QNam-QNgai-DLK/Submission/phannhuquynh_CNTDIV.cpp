#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 10;
int P[N], n, test, d[N];

void sang(){
    	P[0] = 1; P[1] = 1;
    	for(int i = 2; i <= sqrt(N); i++)
        	if (!P[i])
            for (int j = 2; j * i <= N; j++)
                	P[i * j] = i;
    	for(int i = 2; i <= N; i++)
        	if (!P[i]) P[i] = i;
}

int main(){
    	ios_base::sync_with_stdio(0);
    	cin.tie(0); cout.tie(0);
//    	freopen("cntdiv.inp","r",stdin);
//    	freopen("cntdiv.out","w",stdout);
    	
    	sang();
    	cin >> test;
    	while (test--) {
    			cin >> n;
        		int k = 0, j = n;

        		while (j != 1) {
            			d[P[j]]++;
            			k = max(k, P[j]), j /= P[j];
        		}
        		j = n + 1;
       			while (j != 1) {
            			d[P[j]]++;
            			k = max(k, P[j]), j /= P[j];
        		}
        		j = n + 2;
        		while (j != 1) {
            			d[P[j]]++;
            			k = max(k, P[j]), j /= P[j];
        		}
        		ll cnt1 = 1, cnt2 = 1;
        		for(int i = 2; i <= k; i++) {
            			cnt1 = cnt1 * (d[i] + 1);
            			cnt2 = cnt2 * (2 * d[i] + 1);
            			d[i] = 0;
        		}
        		ll res = cnt2 - cnt2 / 2 - cnt1;
        		cout << res << '\n';
    	}
}
