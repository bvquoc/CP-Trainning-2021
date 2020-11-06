#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N = 1e4 + 1;
ll n, Q, P, a[N], f[N][N], p[N][N];
int k;

void sub1()
{
    	f[0][0] = 0;
    	for(int i = 1; i <= n; i++)
    	for(int j = 1; j <= Q; j++){
            	f[i][j] = f[i - 1][j];
            	for(ll t = 1; t <= j && t <= P; t++)
                		f[i][j] = max(f[i][j], f[max(0, i - k)][j - t] + t * a[i]);
    	}
    	cout << f[n][Q];
}
void sub2(){
		/*int R = Q / P;
		if (Q % P != 0) R++;
		
		for(int i = 1; i <= n; i++)
        for(int j = 1; j <= R && j <= i; j++)
            	f[i][j] = max(f[i - 1][j], f[max(0, i - k)][j - 1] + a[i] * P);

    	for(int i = n; i >= 1; i--)
        for(int j = 1; j <= R && j <= i; j++)
            	p[i][j] = max(p[i + 1][j], p[min((int)n + 1, i + k)][j - 1] + a[i] * P);

	    int du = Q - (Q / P) * P;
    	ll res = 0;
    	for(int i = 1; i <= n; i++)
        for(int j = 0; j <= R - 1; j++)
            	res = max(res, a[i] * du + f[max(0, i - k)][j] + p[min((int)n + 1, i + k)][R - j - 1]);*/
        
        int R = Q / P;
        for(int i = 1; i <= n; i++)
        for(int j = 1; j <= R; j++)
            	f[i][j] = max(f[i - 1][j], f[max((int)0, i - k)][j - 1] + a[i] * P);

    	for(int i = n; i >= 1; i--)
        for(int j = 1; j <= R; j++)
            	p[i][j] = max(p[i + 1][j], p[min((int)n + 1, i + k)][j - 1] + a[i] * P);

    	int du = Q - (Q / P) * P;
    	ll res = max(f[n][R], p[1][R]);
    	for(int i = 1; i <= n; i++)
        for(int j = 0; j <= R; j++)
	            res = max(res, a[i] * du + f[max((int)0, i - k)][j] + p[min((int)n + 1, i + k)][R - j]);
            
	    cout << res;
}
int main(){
    	ios_base::sync_with_stdio(false); 
		cin.tie(0); cout.tie(0);
//		freopen("farm.inp", "r", stdin);
//		freopen("farm.out", "w", stdout);
    	cin >> n >> k >> Q >> P;
    	for(int i = 1; i <= n; i++) cin >> a[i];
    	//if (n <= 1000) sub1(); else
		sub2();
}

