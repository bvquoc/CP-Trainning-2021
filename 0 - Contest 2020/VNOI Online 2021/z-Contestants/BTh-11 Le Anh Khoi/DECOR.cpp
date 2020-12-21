#include <bits/stdc++.h>

using namespace std;

int n, m, k, resr = 0;
string s;

bool check(int val)
{
    int tmp = k;
    for(int i = 0; i < val; i++){
        for(int j = i; j < i + val - 2; j++){
            if(s[j] == '0') tmp--;
        }
        if(tmp > 0){
            resr = i + val;
            return 1;
        }
    }
    return 0;
}

int main()
{
    freopen("DECOR.INP", "r", stdin);
    freopen("DECOR.OUT", "w", stdout);
    cin >> n >> m >> k;
    cin >> s;
    if(m == 0){
        if(k == 0){
            int last = 0, res = 0, l, r;
            for(int i = 0; i < n; i++){
                if(s[i] == '1'){
                    if(res < ++last){
                        res = last;
                        r = i;
                    }
                }
                else last = 0;
            }
            cout << r - res + 2 << " " << r + 1;
        }
        else{
            int l = 1, r = n, res = 0;
            while(l <= r){
                int mid = (l+r)/2;
                if(check(mid)){
                    res = mid;
                    l = mid + 1;
                }
                else r = mid - 1;
            }
            cout << resr - res + 1 << " " << resr;
        }
    }
    return 0;
}
