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
#define oo 1000000007
#define maxN 1000005
#define sz(a) (int)a.size()
#define fast ios::sync_with_stdio(false); cin.tie(0)
using namespace std;

int n, m, k;
int a[maxN], sum[maxN];

int check(int x, int left, int right) {
	int temp = sum[x] - sum[left-1];
	int l = x - left + 1;
	return (l - temp <= k);
}

int tk(int left, int right) {
	int res = 0;
	int l = left, r = right;
	while (l <= r) {
		int mid = (l + r)/2;
		if (check(mid, left, right)) {
			res = mid;
			l = mid + 1;
		} else r = mid - 1; 
	}

	return res;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("decor.inp", "r", stdin);
    freopen("decor.out", "w", stdout);
    #endif

    scii(n, m); sci(k);
    string temp; cin >> temp;
    fto(i, 0, sz(temp)-1) a[i+1] = temp[i] - '0';
    fto(i, 1, n) sum[i] = sum[i-1] + a[i];
    //bugarr(a, 1, n);
   	//bugarr(sum, 1, n);
   	int ans = -oo;
   	int ansl = 0;
   	int ansr = 0;
   	if (m == 0) {
   		fto(i, 1, n) {
   			int x = tk(i, n);
   			if (x - i > ans) {
   				ans = x - i;
   				ansl = i;
   				ansr = x;
   			}
   		}
   	}

   	if (ansl == 0) {
   		puts("-1");
   		return 0;
   	} 
   	pris(ansl); pril(ansr);

    return 0;
}