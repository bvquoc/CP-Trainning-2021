#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define MOD 1000000007
#define ten "decor"

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef unsigned long long ull;

int Z[2000000], n, m, k, LL = 0, RR = 0;
string s;

void Zalgo()
{
    int L = 1, R = 1;

    Z[0] = n;

    for(int i = 1; i < n; i++)
    {
        if(R < i)
        {
            L = R = i;

            while(R < n && s[R] == s[R - L]) R++;
            Z[i] = R - L; R--;
        }
        else
        {
            int k = i - L;

            if(Z[k] < R - i + 1) Z[i] = Z[k];
            else
            {
                L = i;

                while(R < n && s[R] == s[R - L]) R++;
                Z[i] = R - L; R--;
            }
        }
    }
}

void subtask1()
{
    int Max = 0;
    n = s.size();

    string s1;

    for(int i = 1; i <= n; i++)
        s1 += "1";

    s = s1 + "#" + s;
    n = s.size();

    Zalgo();

    for(int i = n / 2; i < n; i++)
    {
        if(Max < Z[i])
            {
                Max = Z[i];
                LL = i - n / 2;
                RR = i + Z[i] - n / 2 - 1;
            }
    }

    if(Max == 0)
    {
        cout << -1;
        return;
    }
    cout << LL <<' '<< RR;
}

void subtask2()
{
    int l = 0, Max = 0;

    n = s.size();

    for(int r = 0; r < n; r++)
    {
        if(s[r] == '1')
        {
            if(Max < r - l + 1)
            {
                Max = r - l + 1;
                LL = l;
                RR = r;
            }
            continue;
        }

        if(k == 0)
        {
            while(l <= r && k == 0)
            {
                if(s[l] == '0') k++;
                l++;
            }

            if(Max < r - l + 1)
            {
                Max = r - l + 1;
                LL = l;
                RR = r;
            }
        }

        if(k > 0)
        {
            k--;

            if(Max < r - l + 1)
            {
                Max = r - l + 1;
                LL = l;
                RR = r;
            }
        }
    }

    if(Max == 0)
    {
        cout << -1;
        return;
    }
    cout << LL + 1 <<' '<< RR + 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen(ten".inp", "r", stdin);
    freopen(ten".out", "w", stdout);

    cin >> n >> m >> k;

    cin >> s;

    if(m == 0 && k == 0)
    {
        subtask1();
        return 0;
    }
    subtask2();

    return 0;
}
