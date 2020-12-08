#include <bits/stdc++.h>
using namespace std;
#define int long long

const string name="fasttype";
const int nTest=100;

int Rand(int l, int h) {
	return l+((int)rand()*(RAND_MAX+1)*(RAND_MAX+1)*(RAND_MAX+1)+
			  (int)rand()*(RAND_MAX+1)*(RAND_MAX+1)+
			  (int)rand()*(RAND_MAX+1)+
			   rand())%(h-l+1);
}

int32_t main() {
	freopen("programtest.txt", "w", stdout);
	srand(time(NULL));
	
	for (int iTest=1; iTest<=nTest; iTest++) {
		ofstream inp((name+".inp").c_str());
		// Code phần sinh test ở đây
		int k, m, q;
		k=10; 
		m=Rand(k,k+5);
		inp<<k<<" "<<m<<endl;
		int n=Rand(k+1,k+20);
		for (int i=1;i<=n;i++) {
			int cs=Rand('a','z');
			inp<<char(cs);
		}
		inp<<endl;
		q=Rand(1,30);
		inp<<q<<endl;
		while (q--) {
			int l, r, c;
			l=Rand(1,n/2), r=(l,n);
			c=Rand(1,n);
			inp<<l<<" "<<r<<" "<<c<<endl;
		}
		inp.close();
		// Nếu dùng Linux thì "./"+Tên chương trình
		system((name+"_bac.exe").c_str());
		system((name+"_trau.exe").c_str());
		// Nếu dùng linux thì thay fc bằng diff
		if(system(("fc "+name+".out "+name+".ans").c_str()) != 0)
		{
			cout<<"Test "<<iTest<<": WRONG!\n";
			return 0;
		}
		cout<<"Test "<<iTest<<": CORRECT!\n";
	}

	return 0;
}