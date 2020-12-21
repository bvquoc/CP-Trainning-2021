#include<bits/stdc++.h>
#define bug(a) cout<< #a << ": " << a << endl;
#define bug2(a, b) cout<< #a << ": " << a << ", " << #b << ": " << b << endl;
#define bugarr(a, i, j) cout<< #a << "{" << i << "..." << j << "}: "; fto(k, i, j-1) cout<< a[k] << ", "; cout<<a[j] << endl;
#define fto(i, a, b) for(int i = a; i <= b; ++i)
#define fdto(i, a, b) for(int i = a; i >= b; --i)
#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d %d", &a, &b)
#define pril(a) printf("%d\n", a)
#define pris(a) printf("%d ", a)
#define ll long long
#define ii pair<int, int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vii vector<ii>
#define all(x) (x).begin(), (x).end()
#define oo 998244353
#define maxN 2005
#define sz(a) (int)a.size()
#define fast ios::sync_with_stdio(false); cin.tie(0)
using namespace std; 

int n, ans;
int a[maxN], b[maxN], avail[maxN];

void solve1(int pos) {
	if (pos > n) {
		int temp = 1;
		int sumle = 0, sumchan = 0;
		string res = "";
		int b1[maxN];
		fto(i, 1, n) b1[i] = a[b[i]];
		fto(i, 1, n) {
			string restemp = "";
			while (b1[i] > 0) {
				restemp += (b1[i]%10) + '0';
				b1[i] /= 10;
			}
			reverse(all(restemp));
			res += restemp; 
		}
		int check = 1;
		fto(i, 0, sz(res)-1) {
			if (check == 1) sumle += res[i] - '0';
			else sumchan += res[i] - '0';
			check = 1 - check;
		}
		//bug2(sumchan, sumle);
		if ((sumle - sumchan)%11 == 0) ans = (ans + 1)%oo;
		//ans = ans % oo;
		return;
	}
	fto(i, 1, n) {
		if (avail[i]) {
			b[pos] = i;
			avail[i] = 0;
			solve1(pos+1);
			avail[i] = 1;
		}
	}
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("gift11.inp", "r", stdin);
    freopen("gift11.out", "w", stdout);
    #endif

    int t; sci(t);
    while (t--) {
    	sci(n);
    	fto(i, 1, n) sci(a[i]);
    	ans = 0;
    	if (n <= 10) {
    		fto(i, 1, 13) avail[i] = 1;
    		solve1(1);
    		cout << ans << '\n';
    		
    	//return 0;
    		continue;
    	}
    	int okchan = 1;
    	fto(i, 1, n) {
    		int temp = 1;
    		int socs = 0;
    		//bug(a[i]);
    		while (temp <= a[i]) {
    			temp *= 10;
    			++socs;
    		}
    		//bug(socs);
    		if (socs % 2 != 0) {
    			okchan = 0;
    			break;
    		}
    	}
    	//bug(okchan);
    	if (okchan) {
    		ans = 0;
    		int sumle = 0;
    		int sumchan = 0;
    		fto(i, 1, n) {
    			int check = 0;
    			while (a[i] > 0) {
    				if (check == 0) sumchan += a[i]%10;
    				else sumle += a[i] %10;
    				a[i] /= 10;
    				check = 1 - check;
    				//bug(a[i]);
    			}
    		}
			//bug2(sumchan, sumle);
			if ((sumle - sumchan)%11 == 0) {
				ans = 1;
	    		fto(i, 1, n) {
	    			ans = (ans * i)%oo;

	    		}
    		}
    		cout << ans << '\n';
    		continue;
    	}
    	//return 0;
    	//cout << dp(slle, slchan) << '\n';
    }


    return 0;
}