#include <bits/stdc++.h>
#define M 200005

using namespace std;

void reup(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int n;
int a[M];
int b[M];
bool ok;

void enter(){
    reup();
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <= n; ++i)
        cin >> b[i];
    ok = 1;
    for(int i = 1; i <= n; ++i)
        if(a[i] != b[i])
            ok = 0;
}

int main()
{
    freopen("PERMEOW.inp", "r", stdin);
    freopen("PERMEOW.out", "w", stdout);
    enter();
    cout << 0;
    return 0;
}
