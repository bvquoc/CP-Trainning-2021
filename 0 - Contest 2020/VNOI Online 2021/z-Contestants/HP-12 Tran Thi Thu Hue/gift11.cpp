#include <bits/stdc++.h>
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define pii pair<int,int>
#define st first
#define nd second
using namespace std;
const int N = 2002, mod = 998244353;

int n, a[N], x[N], gt[N];

void trau()
{
    forinc(i,1,n)
    {
    	x[i] = i;
    	cin >> a[i];
    }
    int res = 0;
    do
	{
		int cs = 1;
		int s[2] = {0,0};
        forinc(i,1,n)
        {
        	int val = a[x[i]];
        	while(val)
			{
				s[cs] += val%10;
				val /= 10;
				cs ^= 1;
			}
        }
        if(abs(s[0]-s[1]) % 11 == 0) ++res;
	}while(next_permutation(x+1,x+n+1));
	cout << res%mod << '\n';
}

void sub2()
{
	int sum = 0;
	forinc(i,1,n) sum += a[i];
	if(sum % 11) cout << 0 << '\n';
	else cout << gt[n] << '\n';
}

int f[N][N][12];
void add(int &a,int b)
{
	a += b;
	if(a >= mod) a -= mod;
}

void sub3()
{
    int n_le = (n+1)/2;
    f[0][0][0] = 1;
    forinc(i,0,n)
    forinc(j,0,n_le)
    forinc(d,0,10)
    {
        add(f[i+1][j+1][(d+a[i]+11)%11], f[i][j][d]);
        add(f[i+1][j][(d-a[i]+11)%11], f[i][j][d]);
    }
    int res = 1ll*f[n][n_le][0]*gt[n_le]%mod*gt[n-n_le] % mod;
    cout << res << '\n';
}

int main()
{
	freopen("gift11.inp","r",stdin);
	freopen("gift11.out","w",stdout);

	ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

	int test; cin >> test;
	gt[0] = 1;
	forinc(i,1,N-2) gt[i] = 1ll*gt[i-1]*i%mod;
	while(test--)
	{
		cin >> n;
		if(n<=9)
		{
			trau();
			continue;
		}
		bool chan = 1, le = 1;
		forinc(i,1,n)
		{
			int x; cin >> x;
			int ncs = 0;
            while(x)
			{
				ncs++;
				a[i] += x % 10 * (ncs%2 ? 1 : -1);
				x /= 10;
			}
			if(ncs % 2) chan = 0;
			else le = 0;
		}
		if(chan) sub2();
		if(le) sub3();
	}
}