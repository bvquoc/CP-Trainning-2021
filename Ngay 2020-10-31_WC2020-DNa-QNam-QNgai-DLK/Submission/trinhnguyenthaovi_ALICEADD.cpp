#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define ii pair <int, int>
#define NAME "TEST"

using namespace std;

const int gh = 1e5 + 5, oo = 1e9, modu = 1e9 + 7;

string a, b;
int t;

string cong (string a, string b)
{
    string kq = "";
    int nho = 0, tam;
    while (a.size() > b.size()) b = '0' + b;
    while (a.size() < b.size()) a = '0' + a;
    for (int i = a.size() - 1; i >= 0; --i)
    {
        tam = (a[i] - 48) + (b[i] - 48) + nho;
        nho = tam / 10;
        tam %= 10;
        kq += char (tam + 48);
    }
    if (nho) kq += '1';
    reverse(kq.begin(), kq.end());
    return kq;
}

int main()
{
//    freopen (NAME".INP", "r", stdin);
//    freopen (NAME".OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        cout << cong (a, b) << '\n';
    }

    return 0;
}
