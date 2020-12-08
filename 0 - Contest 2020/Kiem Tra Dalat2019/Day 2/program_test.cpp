#include <bits/stdc++.h>
using namespace std;
#define int long long

const string name="BALLOON";
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
		int n=Rand(1,500);
		inp<<n<<endl;
		inp<<"1 ";
		for (int i=1; i<n; i++) inp<<Rand(1,300000)<<" ";
		// inp<<endl;
		// while (q--) {
		// 	int x=Rand(1,2000);
		// 	inp<<x<<" ";
		// }
		inp.close();
		// Nếu dùng Linux thì "./"+Tên chương trình
		system((name+".exe").c_str());
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