/// Author: djxone123456(Mong u)

#include<bits/stdc++.h>
#define sz(x) int(x.size())
#define reset(x) memset(x, 0,sizeof(x))
#define MIN(x,y) if (x > (y)) x = (y)
#define MAX(x,y) if (x < (y)) x = (y)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pi pair<int, int>
#define pii pair<pi, int>
#define Task "debug"
#define MOD 1000000007
#define INF INT_MAX
#define endl '\n'

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double db;

int pos, n, cnt = 0;
string s;

string cmp1()
{
    int num = 0;
    string t;

    for(pos; pos < n; pos++)
    {
        if(s[pos] >= '0' && s[pos] <= '9')
        {
            num = num * 10 + (int)s[pos] - '0';
        }
        else
            if(s[pos] == '[')
            {
                pos++;
                cnt++;
                if(s[pos] == '*')
                {
                    pos++;
                    string tmp = cmp1();
                    string tmp1 = tmp;
                    reverse(tmp1.begin(), tmp1.end());
                    t += tmp + tmp1;
                }
                else
                {
                    string tmp = cmp1();
                    string tmp1 = tmp.substr(0, tmp.size() - 1);
                    reverse(tmp1.begin(), tmp1.end());
                    t += tmp + tmp1;
                }
            }
        else
            if(s[pos] == '(')
            {
                cnt++;
                pos++;
                string tmp = cmp1();

                for(int i = 1; i <= num; i++)
                    t += tmp;

                num = 0;
            }
        else
            if(s[pos] == ')' || (s[pos] == ']' && s[pos - 1] != '*')) return t;
        else
            if(s[pos] == ']') continue;
        else
            if(s[pos] == '*') return t;
        else
            t += s[pos];
    }
    return t;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifdef djxone123456
    freopen(Task".inp", "r", stdin);
    freopen(Task".out", "w", stdout);
    #endif // djxone123456

    cin >> s;

    n = s.size();
    pos = 0;

    string tmp = cmp1();

    cout << cnt << endl << tmp;

    return 0;
}
