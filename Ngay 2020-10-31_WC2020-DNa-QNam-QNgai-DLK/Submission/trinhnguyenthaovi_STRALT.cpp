#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define ii pair <int, int>
#define NAME "TEST"

using namespace std;

const int N = 1e5 + 5, oo = 1e9, mod = 1e9 + 7;

string s;
stack <int> cnt, open, open2;
int tmp, close, close2, res;
bool ok = 1;

void get ()
{
    ++res;
    string tmp = "", sth = "";
    for (int i = open.top(); i <= close; ++i) sth += s[i];
    for (int i = 1; i <= cnt.top(); ++i) tmp += sth;
    s.erase (s.begin() + open.top(), s.begin() + close + 1);
    s.insert (s.begin() + open.top(), tmp.begin(), tmp.end());
    cnt.pop(); open.pop();
}

void get2 (bool ok)
{
    int op = open2.top(), cl = close2;
    ++res;
    string tmp, sth = "";
    if (!ok) ++open2.top(); /// TH dấu * ở trước
    else --close2;
    for (int i = open2.top(); i <= close2; ++i) sth += s[i];
    tmp = sth;
    if (ok) tmp.erase(tmp.size() - 1);
    reverse (tmp.begin(), tmp.end());
    sth += tmp;

    s.erase (s.begin() + op, s.begin() + cl + 1);
    s.insert (s.begin() + op, sth.begin(), sth.end());
    open2.pop();
}

void sub1()
{
    tmp = 0;
    res = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] <= 57 && s[i] >= 48)
        {
            tmp = tmp * 10 + (s[i] - 48);
            s.erase (s.begin() + i);
            --i;
            continue;
        }
        else if (tmp)
        {
            cnt.push (tmp);
            tmp = 0;
        }
        if (s[i] == '(')
        {
            s.erase (s.begin() + i);
            open.push (i);
            --i;
        }
        else if (s[i] == ')')
        {
            s.erase (s.begin() + i);
            close = i - 1;
            get ();
            i = (open.size()) ? open.top() : 0;
        }
    }
    cout << res << '\n' << s;
    return;
}

void sub2()
{
    tmp = 0;
    res = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] <= 57 && s[i] >= 48)
        {
            tmp = tmp * 10 + (s[i] - 48);
            s.erase (s.begin() + i);
            --i;
            continue;
        }
        else if (tmp)
        {
            cnt.push (tmp);
            tmp = 0;
        }
        if (s[i] == '(')
        {
            s.erase (s.begin() + i);
            open.push (i);
            --i;
        }
        else if (s[i] == ')')
        {
            s.erase (s.begin() + i);
            close = i - 1;
            get ();
            i = (open.size()) ? open.top() : 0;
        }
        if (s[i] == '[')
        {
            s.erase (s.begin() + i);
            open2.push (i);
            --i;
        }
        else if (s[i] == ']')
        {
            s.erase (s.begin() + i);
            close2 = i - 1;
            get2 ((s[close2] == '*'));
            i = (open2.size()) ? open2.top() : 0;
        }
    }
    cout << res << '\n' << s;
    return;
}

int main()
{
//    freopen (NAME".INP", "r", stdin);
//    freopen (NAME".OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '[') ok = 0;
    }
    //if (ok) sub1();
    sub2 ();
    return 0;
}
