#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        string a, b;
        cin>>a>>b;
        while(a.size()<b.size()){
            a = '0' + a;
        }
        while(b.size()<a.size()){
            b = '0' + b;
        }
        string res="";
        int du = 0;
        for (int i=a.size(); i >= 1;i--){
            int sum = (a[i-1]-'0') + (b[i-1]-'0')+du;
            du = sum / 10;
            sum = sum % 10;
            char kt = sum + '0';
            res = kt + res;
        }
        if(du!=0){
            char kt = du + '0';
            res = kt + res;
        }
        cout << res << '\n';
    }
    return 0;
}