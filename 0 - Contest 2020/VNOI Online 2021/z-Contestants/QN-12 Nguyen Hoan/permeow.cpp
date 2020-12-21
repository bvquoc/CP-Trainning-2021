#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fr(i,a,b) for(int i = a; i <= b; i++)
#define ll long long
#define ii pair<int,int>
#define pb push_back

int n;
int a[200010];
int b[200010];
bool check = true;

void io () {
    freopen ("permeow.inp", "r", stdin);
    freopen ("permeow.out", "w", stdout);
}

void inp () {
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> b[i];
        if(b[i] != a[i]) check = false;
    }
}

void sub () {
    int res = 0;
    for(int i = 1; i <= n; i++)
    {
        int vt = 0;
        for(int j = 1; j <= n; j++)
        {
            if(a[j] == i) {vt = j; break;}
        }
        for(int j = vt; j >= i + 1; j--)
        {
            res ++;
            swap(a[j], a[j - 1]);
        }
    }
    cout << res;
}

int main () {
    io ();
    inp ();
    if(check == true) sub ();
    else{ cout << "0\n";}
    return 0;
}
