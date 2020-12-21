#include <bits/stdc++.h>
#define x first
#define y second
#define ll long long
#define mod 998244353
#define pii pair <int ,int>
#define reset(x) memset(x, 0,sizeof(x))
#define PB push_back
#define mp make_pair
#define maxn 1000005
#define task "gift11"

using namespace std;

int t,n,S;
vector <int> a[2005];

void sub1() {
    for(int i=1; i<=t; i++) {
        int res=0;
        vector <int> xl;
        for(int j=0; j<a[i].size(); j++)
            xl.PB(j);
        do {
            int cnt=1,s=0;
            for(int cs:xl) {
                int h=a[i][cs];
                vector <int> num;
                while(h>0) {
                    num.PB(h%10);
                    h/=10;
                }
                reverse(num.begin(),num.end());

                for(int x:num) {
                    if(cnt%2==1)
                        s+=x;
                    else
                        s-=x;
                    cnt++;
                }
            }
            if(s%11==0)
                res++;
        } while(next_permutation(xl.begin(),xl.end()));
        cout<<res<<'\n';
    }
}

void sub2() {
    for(int i=1; i<=t; i++) {
        int cnt=1,s=0;
        for(int x:a[i]) {
            int h=x;
            vector <int> num;
            while(h>0) {
                num.PB(h%10);
                h/=10;
            }
            reverse(num.begin(),num.end());
            for(int x:num) {
                if(cnt%2==1)
                    s+=x;
                else
                    s-=x;
                cnt++;
            }
        }
        if(s%11!=0)
            cout<<0<<'\n';
        else {
            ll res=1;
            for(int j=1;j<=a[i].size();j++)
                res=res*j%mod;
            cout<<res<<'\n';
        }
    }
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>t;
    for(int i=1; i<=t; i++) {
        cin>>n;
        for(int j=1; j<=n; j++) {
            int x;
            cin>>x;
            a[i].PB(x);
        }
        S+=n;
    }
    if(S<=8) {
        sub1();
        return 0;
    } else {
        sub2();
        return 0;
    }
}
