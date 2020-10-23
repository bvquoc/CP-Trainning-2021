#include <bits/stdc++.h>
using namespace std;
int power(int a, int n){
	int p = 1;
	for(int i = 0; i < n; i++){
		p *= a;
	}
	return p;
}
int main(){
	ifstream ifs("KMULT.INP");
	ofstream ofs("KMULT.OUT");
	if(ifs.is_open()){
		int n, k;
		ifs >> n >> k;
		int *a = new int[n];
		for(int i = 0 ; i < n; i++){
			ifs >> a[i];
		}
		int m = n - 1;
		int l = power(2, m);
		int *b = new int[m];
		b[m - 1] = 1;
		for(int i = m - 2; i >= 0 ;i--){
			b[i] = b[i+1] * 2;
		}
		for(int x = 0; x < l; x++){
			int t = x;
			int s = a[0];
			for(int i = 0; i < m; i++){
				if(t >= b[i]){
					t -= b[i];
					s -= a[i + 1];
				}else{
					s += a[i + 1];
				}
			}
			t = x;
			if(s % k == 0){
				printf("s = %d\n", s);
				for(int i = 0; i < m; i++){
					if(t >= b[i]){
						t -= b[i];
						
						cout << '-';
					}else{
						cout << '+';
					}
				}
				cout << endl;	
			}
		}
		delete []a;
		ifs.close();
		ofs.close();
	}
	return 0;
}
