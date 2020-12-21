#include<bits/stdc++.h>
using namespace std;

ifstream fi("permeow.inp");
ofstream fo("permeow.out");

int const N = 2e5 + 5;

int n;
int a[N], b[N];

int ans;

void sub1(){
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j < i; ++j)
            if(a[j] > a[i]) ++ans;
    fo << ans;
}

int main(){
    fi >> n;
    bool check1 = true;
    bool check2 = true;
    for(int i = 1; i <= n; ++i) {
        fi >> a[i];
        if(a[i] != i) check2 = false;
    }
    for(int i = 1; i <= n; ++i) {
        fi >> b[i];
        if(b[i] != a[i]) check1 = false;
        if(b[i] != n - i + 1) check2 = false;
    }
    sub1();
    return 0;
}
