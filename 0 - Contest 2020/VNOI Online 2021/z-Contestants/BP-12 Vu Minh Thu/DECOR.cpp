#include<bits/stdc++.h>
using namespace std;

ifstream fi("DECOR.inp");
ofstream fo("DECOR.out");

int const N = 5e5 + 5;

int n, m, k;
int a[N];

pair<int, int> change[N];

int ans, pos;

void sub1(){
    int lt;
    for(int i = 1; i <= n; ++i){
        if(a[i] == 1 && a[i - 1] == 0) lt = i;
        if(a[i] == 0 && a[i - 1] == 1){
            if(ans < i - lt){
                ans = i - lt;
                pos = lt;
            }
        }
    }
    if(ans == 0) fo << -1;
    else fo << pos << " " << ans;
}

pair<int, int> light[N];

void sub2(){
    int cnt = 0;
    int lt;
    for(int i = 1; i <= n + 1; ++i){
        if(a[i] == 1 && a[i - 1] == 0) lt = i;
        if(a[i] == 0 && a[i - 1] == 1){
            if(ans < i - lt){
                ans = i - lt;
                pos = lt;
            }
            light[++cnt] = {lt, i - 1};
        }
    }
    if(ans == 0) fo << -1;
    else {
        int i = 1;
        while(i < cnt){
            if(k < light[i + 1].first - light[i].second - 1){
                int res = light[i].second - light[i].first + 1 + k;
                if(ans < res){
                    ans = res;
                    pos = light[i].first;
                }
            }
            else{
                int res = light[i].second - light[i].first + 1 + k + light[i + 1].second - light[i + 1].first + 1;
                if(ans < res){
                    ans = res;
                    pos = light[i].first;
                }
            }
            ++i;
        }
        fo << pos << " " << ans;
    }
}

int main(){
    fi >> n >> m >> k;
    for(int i = 1; i <= n; ++i) {
        char c; fi >> c;
        a[i] = c - '0';
    }
    for(int i = 1; i <= m; ++i)
        fi >> change[i].first >> change[i].second;
    if(n == 1){
        if(a[1] == 1 || k == 1) {fo << 1 << " " << 1; return 0;}
        else {fo << -1; return 0;}
    }
    if(m == 0 && k == 0){
        sub1();
        return 0;
    }
    else sub2();

}
