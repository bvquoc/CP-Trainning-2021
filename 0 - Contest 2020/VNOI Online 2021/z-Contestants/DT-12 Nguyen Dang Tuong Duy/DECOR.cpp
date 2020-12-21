#include <bits/stdc++.h>
using namespace std;
const long long oo=2*1e18;
string s;
int n,m,k,ans;
void sub1() {
    long long cur=0;
    for (int i=n-1;i>=0;i--) {
        if (s[i]=='0') continue;
        cur+=(1<<(n-1-i));
        if (cur>=oo) {
            cout<<-1;
            return;
        }
    }
    while (cur!=0) {
        cur=(cur&(cur<<1));
        ans++;
    }
    for (int i=0;i<n;i++) {
        string tmp=s.substr(i,ans);
        if (count(tmp.begin(),tmp.end(),'0')==0) {
            cout<<i+1<<' '<<i+ans;
            return;
        }
    }
}
void sub2(){
    int cnt=count(s.begin(),s.end(),'0');
    if (cnt<=k) {
        cout<<1<<' '<<n;
        return;
    }
    else cout<<-1;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    freopen("DECOR.INP","r",stdin);
    freopen("DECOR.OUT","w",stdout);
    cin>>n>>m>>k;
    cin>>s;
    if (m==0 && k==0) {
        sub1();
        return 0;
    }
    else if (m==0 && k!=0) {
        sub2();
        return 0;
    }
}
