#include <bits/stdc++.h>
#define task "FIXSTR"
#define nmax 1000006
#define S second
#define F first
#define reset(x) memset(x,0,sizeof(x))
#define len(s) int(s.length())
#define endl '\n'

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
string s,str[nmax];
int n;

int count(int l, int r)
{
    int cur = 0, ans = 0;
//    string tmp = "";
//    for (int i = l; i <= r; i++)
//    {
//        tmp = tmp + s[i];
//    }
//
//    cout << tmp << endl;
    for (int i = l; i <= r; i++)
    {
        if (s[i] == '(' && cur >= 0) {
            cur++;
            continue;
        }
        if (s[i] == '(' && cur < 0){
            cur = 1;
            continue;
        }
        if (s[i] == ')') cur--;
        if (cur < 0) ans = ans + 1;
    }
    if (cur > 0) ans += cur;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin >> s;
    cin >> n;
    s = '.' + s;
    char t;
    int x, y;
    for (int i = 1; i <= n; i++)
    {
        cin >> t;
        if (t == 'C')
        {
            cin >> x;
            s[x] = (s[x] == '(' ? ')' : '(');
            str[i] = s;
        }
        if (t == 'U')
        {
            cin >> x;
            s = str[x - 1];
            str[i] = s;
        }
        if (t == 'Q')
        {
            cin >> x >> y;
            cout << count(x, y) << endl;
            str[i] = s;
        }
    }
}
