#include <bits/stdc++.h>
#define maxn 505
#define oo 2000000000

using namespace std;
typedef pair<int,int> II;
typedef pair<int,II> III;

string a, b, c;

void sub1() {
    if(c[0] == a[0] || c[0] == b[0]) cout<<"TRETRAU";
    else if(a[0] == b[0]) {
        cout<<1<<'\n';
        cout<<a;
    } else {
        cout<<2<<'\n';
        cout<<a<<b;
    }
}

void sub2() {
    cout<<a.size() + b.size()<<'\n';
    cout<<a<<b;
}

int main() {
    freopen("XCKLT.inp", "r", stdin);
    freopen("XCKLT.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>a>>b>>c;

    if(a.size() == 1 && b.size() == 1 && c.size() == 1) sub1();
    else sub2();
}
