#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxN=200005;
const ll MM=1e9+7;
ll a[maxN], f[maxN], b[maxN], gt[maxN];
int n;

ll Sub1(){
    int res=0;
    for (int i=1; i<=n; ++i){
        int rj=0;
        for (int j=1; j<=n; ++j) if (a[j]==i) rj=j;
        for (int j=rj; j>i; --j){
            ++res;
            swap(a[j], a[j-1]);
        }
    }
    return res;
}
ll Sub2(){
    f[1]=0;
    gt[0]=1;
    for (int i=1; i<=n; ++i) gt[i]=(gt[i-1]*i)%MM;
    for (int i=2; i<=n; ++i){
        ll tmp=-gt[i-1];
        for (int j=1; j<=i; ++j){
            tmp+=gt[i-1];
            tmp%=MM;
            f[i]=(f[i]+f[i-1]+tmp)%MM;
        }
    }
    return f[n];
}
bool check_Sub1(){
    for (int i=1; i<=n; ++i) if (a[i]!=b[i]) return false;
    return true;
}
int main()
{
    ifstream cin("PERMEOW.INP");
    ofstream cout("PERMEOW.OUT");
    cin >> n;
    for (int i=1; i<=n; ++i) cin >> a[i];
    for (int j=1; j<=n; ++j) cin >> b[j];
    if (check_Sub1()){
        cout << Sub1();
    }
    else{
        cout << Sub2();
    }
    return 0;
}
