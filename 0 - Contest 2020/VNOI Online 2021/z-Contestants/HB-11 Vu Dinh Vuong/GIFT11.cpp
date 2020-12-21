#include <bits/stdc++.h>
#define pii pair<int,int>
#define vi vector<int>
#define F first
#define S second
#define PB(x) push_back(x)
#define ll long long
#define maxn 2005

using namespace std;

const ll MOD = 998244353;
int n,t,kq;
bool check[maxn];
string a[maxn];
ll gt[maxn];

void backtrack(string s, int cnt){
    if (cnt == n){
        int l = 0,c = 0;
        for (int i = 0 ; i < s.size() ; i++){
            if (i % 2) l += (s[i] - 48);
             else c += (s[i] - 48);
        }
        if (abs(l-c) %  11 == 0) kq++;
        return;
    }

    for (int i = 0 ; i < n ; i++){
        if (!check[i]){
            check[i] = 1;
            backtrack(s+a[i],cnt+1);
            check[i] = 0;
        }
    }
}

void prepare(){
    gt[0] = 1;
    for (int i = 1 ; i < maxn ; i++) gt[i] = (gt[i-1]*i) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(0);
    ifstream cin("GIFT11.inp");
    ofstream cout("GIFT11.out");
    cin >> t;
    prepare();
    while (t--){
        cin >> n;
        bool sub2 = 1;
        for (int i = 0 ; i < n ; i++){
            cin >> a[i];
            if (a[i].size() % 2) sub2 = 0;
        }

        if (sub2){
            int l = 0 , c = 0;
            for (int i = 0 ; i < n ; i++){
                for (int j = a[i].size() - 1 ; j >= 0 ; j--){
                    if (j % 2) l += (a[i][j] - 48);
                     else c += (a[i][j] - 48);
                }
            }
            if (abs(l - c) % 11 == 0) cout << gt[n] << '\n';
                 else cout << 0 << '\n';
        }
        else{
        string s = "";
        backtrack(s,0);
        cout << kq;
        }
    }
    return 0;
}
