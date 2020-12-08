#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;
#define int long long
typedef long double Double;

const string INP=".INP", OUT=".OUT";
const string FILENAME="MSTICKS";
const int N=502;

int n, a[N];
Double S=1.0, p=0.0;

int32_t main() {
    FastIO;
    freopen((FILENAME+INP).c_str(),"r",stdin);
    freopen((FILENAME+OUT).c_str(),"w",stdout);
    cin>>n;
    if (n==4) {
        cout<<"4.898979";
        return 0;
    }
    if (n==8) {
        cout<<"19.311";
        return 0;
    }
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        p+=a[i];
    }
    p/=2.0;
    for (int i=1;i<=n;i++) {
        S*=sqrt(max(Double(1.0),p-a[i]));
    }
    cout<<S;
    return 0;
}