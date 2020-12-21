#include <bits/stdc++.h>
#define X first
#define Y second
#define f1(i,n) for (int i = 1; i <= n; i++)
#define f0(i,n) for (int i = 0; i < n; i++)
#define N 200005

using namespace std;
int n;
int a[N],b[N];

bool _check(int x){
    if (x == -1) return true;
    f0(i, n) if (a[i] != b[i]) return false;
    return true;
}
void ham_hv(int &a, int &b){
	int temp;
	temp = a;
	a = b; 
	b = temp;
}

void ham_sinh(int n, int &stop){
	int j = n - 2;
	while(j > -1  && a[j] > a[j+1]){
		j--;
	}
	if(_check(j)) stop = 1;
	else{
		int k = n - 1; 
		while(a[j] > a[k]) k--;
		ham_hv(a[j], a[k]);
	}

	int r = j + 1;
	int s = n -1;
	while(r < s){
		ham_hv(a[r], a[s]);
		r++;
		s--;
	}	
}

int main(){
    ifstream fi("PERMEOW.INP"); ofstream fo("PERMEOW.OUT");
    int stop = 0, ans = 0;
    fi >> n;
    f0(i, n) fi >> a[i];
    f0(i, n) fi >> b[i];
    while(stop == 0)
    {
        bool dk = true;
        int c[N];
        f0(i, n) c[i] = a[i];
        while (dk)
        {
            bool dk1 = false;

            f0(i, (n-1)) 
            if (c[i] > c[i + 1]) {
                ham_hv(c[i], c[i + 1]);
                dk1 = true;
                ans++;
            }
            if (dk1 == false) dk = false;
        }
		ham_sinh(n, stop);
	}
    fo << ans << endl;
    return 0;
}