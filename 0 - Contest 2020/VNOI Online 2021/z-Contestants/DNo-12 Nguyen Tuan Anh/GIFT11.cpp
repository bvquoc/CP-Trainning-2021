#include <bits/stdc++.h>
#define int long long
using namespace std;
const string filename="GIFT11";
const int MOD=998244353;
vector<string> a;
int T,n,res;
bool cx[3000],su2;

void backtrack(int u, string s) {
    if(u>n) {
        int length=s.length()-1;
        int s1=0,s2=0;
        for(int i=0;i<=length;i+=2) s1+=(s[i]-48);
        for(int i=1;i<=length;i+=2) s2+=(s[i]-48);
        if((s1-s2)%11==0) ++res;
        return;
    }
    for(int i=0;i<a.size();++i) {
        if(!cx[i]) {
            cx[i]=true;
            backtrack(u+1,s+a[i]);
            cx[i]=false;
        }
    }
}

void sub2() {
    int s1=0,s2=0;
    for(int i=0;i<a.size();++i) {
        int m=a[i].length()-1;
        for(int j=0;j<=m;j+=2) s1+=(a[i][j]-48);
        for(int j=1;j<=m;j+=2) s2+=(a[i][j]-48);
    }
    if((s1-s2)%11==0) {
        int s=1;
        for(int i=1;i<=n;++i) {
            s=s*i;
            s%=MOD;
        }
        res=s;
    }
}

int32_t main() {
    freopen((filename+".INP").c_str(),"r",stdin);
    freopen((filename+".OUT").c_str(),"w",stdout);
    cin>>T;
    while(T--) {
        res=0;
        su2=true;
        a.clear();
        cin>>n;
        for(int i=1;i<=n;++i) {
            string x;
            cin>>x;
            a.push_back(x);
            if(x.length()%2==1) su2=false;
        }
        if(su2) {
            sub2();
            printf("%lld\n", res);
            continue;
        }
        {
            memset(cx,false,sizeof(cx));
            backtrack(1,"");
            printf("%lld\n", res);
            continue;
        }
    }
    return 0;
}
