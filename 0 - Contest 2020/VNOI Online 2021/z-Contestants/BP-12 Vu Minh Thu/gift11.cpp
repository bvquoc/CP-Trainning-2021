#include<bits/stdc++.h>
using namespace std;

ifstream fi("gift11.inp");
ofstream fo("gift11.out");

int const N = 2005;
int const mod = 998244353;

int testcase;
int n[15], a[15][N];
int64_t ans;

int cntDigit[15];
bool isOdd[15], isEven[15];

bool isEvenDigit(int x){
    int cnt = 0;
    while(x > 0){
        ++cnt;
        x /= 10;
    }
    if(cnt % 2 == 0) return true;
    return false;
}

void enter(){
    fi >> testcase;
    for(int t = 1; t <= testcase; ++t){
        fi >> n[t];
        ++cntDigit[t];
        isOdd[t] = isEven[t] = true;
        for(int i = 1; i <= n[t]; ++i){
            fi >> a[t][i];
            if(isEvenDigit(a[t][i])) isOdd[t] = false;
            else isEven[t] = false;
        }
    }
}

int x[15];
bool check[15];

string toString(int x){
    string res = "";
    while(x > 0){
        res = char(x % 10 + '0') + res;
        x /= 10;
    }
    return res;
}

void go(int t, int pos){
    if(pos > n[t]){
        int cnt = 0;
        int sumEven = 0;
        int sumOdd = 0;
        string res = "";
        for(int i = 1; i <= n[t]; ++i) res = res + toString(x[i]);
        for(int i = 0; i < res.length(); ++i)
            if(i % 2 == 0) sumOdd += res[i] - '0';
            else sumEven += res[i]  - '0';
        if((sumOdd - sumEven) % 11 == 0) ++ans;
        return;
    }
    for(int i = 1; i <= n[t]; ++i){
        if(!check[i]){
            x[pos] = a[t][i];
            check[i] = true;
            go(t, pos + 1);
            check[i] = false;
        }
    }
}

void sub1(int t){
    ans = 0;
    go(t, 1);
    fo << ans % mod << "\n";
}

void sub2(int t){
    string res = "";
    for(int i = 1; i <= n[t]; ++i) res = res + toString(a[t][i]);
    int sumEven = 0;
    int sumOdd = 0;
    for(int i = 0; i < res.length(); ++i)
        if(i % 2 == 0) sumOdd += res[i] - '0';
        else sumEven += res[i] - '0';
    ans = 1;
    if((sumOdd - sumEven) % 11 == 0)
        for(int i = 1; i <= n[t]; ++i) ans = (ans * i) % mod;
    fo << ans % mod << "\n";
}

int main(){
    enter();
    for(int t = 1; t <= testcase; ++t){
        if(isEven[t] == true){
            sub2(t);
            continue;
        }
        else{
            sub1(t);
            continue;
        }
    }
}
