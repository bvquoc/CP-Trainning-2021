#include <bits/stdc++.h>

#define TASK "PERMEOW"

using namespace std;

const int maxn = 2e5 + 5;

int n, a[maxn], b[maxn];

namespace Sub1
{

    void Main()
    {
        int res = 0;
        for (int i = 1; i <= n; i ++)
        {
            for (int j = 1; j <= n; j ++)
                if (a[j] == i)
                {
                    for (int k = j; k > i; k --) swap(a[k], a[k - 1]), res ++;
                    break;
                }

        }
        cout << res;
    }


}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen(TASK".INP", "r", stdin);
	freopen(TASK".OUT", "w", stdout);

    cin >> n;
    bool all_equal = 1;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i ++)
    {
        cin >> b[i];
        if (b[i] != a[i]) all_equal = 0;
    }
    Sub1::Main();

	return 0;
}
