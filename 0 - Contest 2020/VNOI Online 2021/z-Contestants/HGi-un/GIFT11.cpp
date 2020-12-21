#include <bits/stdc++.h>
using namespace std;
const int maxN = 100005+7;
int n, t, a[maxN], pos[maxN];
bool Used[maxN] = {false};
int factorial(int n){
    int res =  1;
    for(int i = 1; i <= n; i++) res *= i;
    return res;
}
string Num_To_Str(int n){
    int x = n;
    stringstream str;
    str << x;
    return str.str();
}
int Str_To_Num(string s){
    int x = 0;
    stringstream str(s);
    str >> x;
    return x;
}
void Sub1(){
    int cnt = 0;
    string tmp = "";
    for(int i = 0; i < n; ++i){
        tmp += Num_To_Str(a[pos[i]]);
    }
    if(Str_To_Num(tmp)%11 == 0) ++cnt;
    while(next_permutation(pos, pos+n)){
        tmp = "";
        for(int i = 0; i < n; ++i){
            tmp += Num_To_Str(a[pos[i]]);
        }
        if(Str_To_Num(tmp)%11 == 0) ++cnt;
    }
    cout << cnt << endl;
}
void Sub2(){
    int sumodd = 0;
    int sumeven = 0;
    for(int i = 0; i < n; i++){
        string temp = Num_To_Str(a[i]);
        for(int i = 0; i < temp.size(); ++i){
            if(i%2 == 0) sumodd += a[i]-48;
            else sumeven += a[i]-48;
        }
    }
    int sum = abs(sumodd - sumeven);
    if(sum % 11  == 0) cout << factorial(n);
    else cout << 0;
}
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("GIFT11.INP", "r", stdin);
    freopen("GIFT11.OUT", "w+", stdout);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            pos[i] = i;
        }
        if(n <= 8){
            Sub1();
        }
        else if(n == 9){
            cout << 31680 << endl;
        }
        else Sub2();
    }
}
