#include <bits/stdc++.h>

using namespace std;

int n, a[200005], b[200005];
int ok = -1;


int main()
{
    freopen("PERMEOW.INP", "r", stdin);
    freopen("PERMEOW.OUT", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] == i && ok == -1)
            ok = 2;
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
        if(a[i] != b[i]){
            if(n - i + 1 == b[i] && ok == 2) continue;
            ok = 0;
        }
        else if(ok != 0) ok = 1;
    }


    if(ok == 1){
        int res = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                int k = j;
                if(a[k] == i){
                    while(a[i] != i){
                        swap(a[k], a[k-1]);
                        k--;
                        res++;
                    }
                }
            }
        }
        cout << res;
    }
    else if(ok == 2){

    }
    return 0;
}
