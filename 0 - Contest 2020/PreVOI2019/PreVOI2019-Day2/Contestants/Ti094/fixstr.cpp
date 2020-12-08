#include <iostream>
#include <fstream>
#define N 1000002

using namespace std;

string s[N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("fixstr.inp", "r", stdin);
	freopen("fixstr.out", "w", stdout);
    int m; cin >> s[0] >> m;
    string str = s[0];
    int i;
    for (i = 1; i <= m; ++i)
    {
        char chr; int x;
        cin >> chr >> x; --x;
        if (chr == 'U') str = s[x];
        if (chr == 'C')
            str[x] = (str[x] == '(' ? ')' : '(');
        s[i] = str;
        if (chr == 'Q')
        {
            int y, q = 0, re;
            cin >> y; --y;
            re = y - x + 1;
            for (; x <= y; ++x)
                if (str[x] == '(') ++q;
                    else { if (q) { re -= 2; --q; } }
            cout << re <<'\n';
        }
    }
	return 0;
}
