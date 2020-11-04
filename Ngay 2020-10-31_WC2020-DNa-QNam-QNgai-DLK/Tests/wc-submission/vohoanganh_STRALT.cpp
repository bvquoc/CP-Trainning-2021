#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include <map>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pi;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f;

template<typename T> void maximize(T &res, T val) { if (res < val) res = val; }
template<typename T> void minimize(T &res, T val) { if (res > val) res = val; }

string s;
void encode()
{
    string res;
    deque<string> S;
    deque<char> B;
    deque<int> V;

    S.push_back("");
    V.push_back(0);
    for (char c : s)
    {
        // cout << "With ('" << c << "') -> res = " << res << " | V = ";
        // for (int x : V) cout << x << ' '; cout << " | ";
        // for (string t : S) cout << t << ' '; cout << " | ";
        // cout << endl;

        if (c == '(')
        {
            B.push_back('(');
            S.push_back("");
            V.push_back(0);
            continue;
        }

        if (c == '[')
        {
            B.push_back('[');
            S.push_back("");
            V.push_back(0);
            continue;
        }

        if ('0' <= c && c <= '9')
        {
            V.back() = (V.back() << 3) + (V.back() << 1) + (c - '0');
            continue;
        }
        
        if (c == ')')
        {
            V.pop_back();
            string tmp;
            while (V.back() --> 0) tmp += S.back();
            S.back() = tmp;
            V.back() = 0;
            S.pop_back();

            S.back() += tmp;
            B.pop_back();
            if (B.empty())
            {
                res += S.back();
                S.back() = "";
            }
            continue;
        }

        if (c == ']')
        {
            string tmp;
            for (char c : S.back()) if (c != '*') tmp += c;
            if (S.back().back() == '*') tmp.pop_back();
            reverse(all(S.back()));
            for (char c : S.back()) if (c != '*') tmp += c;
            S.pop_back();
            S.back() += tmp;

            B.pop_back();
            V.pop_back();
            if (B.empty())
            {
                res += S.back();
                S.back() = "";
            }
            continue;
        }

        S.back() += c;
    }
    for (; S.size(); S.pop_back())
        res += S.back();
    
    swap(res, s);
}

int main()
{
    cin >> s;

    int cnt = 0;
    for (char c : s)
        if (c == '(' || c == '[')
            ++cnt;

    cout << cnt << '\n';
    if (cnt) encode();
    
    for (char c : s) putchar(c);
    return 0;
}