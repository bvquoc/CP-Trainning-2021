//Hoang Son WIBU lolicon codeforces rate 1439 khong cay
#include <bits/stdc++.h>
#define F first
#define S second
#define times double stime = clock();
#define gettime cerr << "\nTime executed: " << (clock() - stime) / CLOCKS_PER_SEC * 1000 << "ms.\n";
using namespace std;
typedef long long ll;
typedef double dou;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const ll mod = 998244353;
//-std=gnu++17 -Wall

//GIFT11
int t;
int n;
pii a[2005];
int fs1[2005];
void sub1(){
    int res = 0;
    for(int i = 1; i<=n; i++) fs1[i] = i;
    do {
        int sum = 0, pos = 0;
        for(int i = 1; i<=n; i++){
            sum += ((pos + 1)%2 ? 1 : -1)*a[fs1[i]].F;
            pos += a[fs1[i]].S;
        }
        if(sum%11 == 0) res++;
    } while(next_permutation(fs1 + 1, fs1 + n + 1));
    cout << res << "\n";
}
void sub2(){
    int sum = 0, pos = 0;
    for(int i = 1; i<=n; i++){
        sum += ((pos + 1)%2 ? 1 : -1)*a[i].F;
        pos += a[i].S;
    }
    int res = 1;
    if(sum%11 == 0){
        for(int i = 1; i<=n; i++){
            res = (1ll*res*i)%mod;
        }
        cout << res;
    } else cout << 0;
    cout << "\n";
}
void process(){
    cin >> t;
    while(t--){
        cin >> n;
        bool oksub2 = true, oksub3 = true;
        for(int i = 1; i<=n; i++){
            int val, len = 0;
            cin >> val;
            int sum = 0;
            while(val != 0){
                sum += (len%2 ? -1 : 1)*val%10;
                val/=10;
                len++;
            }   
            if(len%2 == 0) sum *= -1;
            if(len%2) oksub2 = false;
            if(len%2 == 0) oksub3 = false;
            a[i] = {sum, len};
            //cout << sum << " " << len << " | ";
        }
        //cout << "\n";
        if(oksub2){
            sub2();
        } else if(n<=8){
            sub1();
        } else sub1();
    }
}
int online = 1;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    if(online == 0){
        freopen("in.inp","r", stdin);
        freopen("out.out","w", stdout);
    } else if(online == 1){
        freopen("GIFT11.inp","r", stdin);
        freopen("GIFT11.out","w", stdout);
    }
    //times
    process();
    //gettime
    return 0;
}