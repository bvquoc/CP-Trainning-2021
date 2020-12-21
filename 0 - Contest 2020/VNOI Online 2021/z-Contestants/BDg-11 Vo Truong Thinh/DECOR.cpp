#include <bits/stdc++.h>
#define M 500005

using namespace std;

void reup(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int n, m, k;

int b[M];

void enter(){
    reup();
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i){
        char c;
        cin >> c;
        b[i] = c - 48;
    }
}

void sub1(){
    int j = 1;
    int ans = 0;
    int l = 0;
    int r = 0;
    for(int i = 1; i <= n; ++i){
        if(b[i] == 0)
            continue;
        if(j < i)
            j = i + 1;
        while(j <= n && b[j] == 1)
            ++j;
        if(ans < j - i){
            ans = j - i;
            l = i;
            r = j - 1;
        }
    }
    if(ans == 0)
        cout << -1;
    else
        cout << l << " " << r;
}

void sub2(){
    for(int i = 1; i <= n; ++i)
        b[i] += b[i - 1];
    int j = 1;
    int ans = 0;
    int l = 0;
    int r = 0;
    for(int i = 1; i <= n; ++i){
        if(j < i)
            j = i;
        while(j <= n && b[j] - b[i - 1] + k >= j - i + 1)
            ++j;
        if(ans < j - i){
            ans = j - i;
            l = i;
            r = j - 1;
        }
    }
    if(ans == 0)
        cout << -1;
    else
        cout << l << " " << r;
}

int main()
{
    freopen("DECOR.inp", "r", stdin);
    freopen("DECOR.out", "w", stdout);
    enter();
    if(m == 0 && k == 0)
        sub1();
    else
        if(m == 0)
            sub2();
    else
        cout << -1;
    return 0;
}
