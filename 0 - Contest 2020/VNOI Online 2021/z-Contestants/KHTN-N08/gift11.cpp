#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2004;
const int mod=998244353;
int dp_odd[maxn][maxn/2][11];
int dp_even[maxn][maxn][11];  // number of numbers, counting off + sign
int fact[maxn];
int T;
int val[maxn];
int odd[maxn];
int even[maxn];
int ways[11];
int cnt_odd=0;
int cnt_even=0;
int rem_odd=0;
int rem_even=0;
int n;
void init() {
    fact[0]=1;
    for(int i=1 ; i<maxn ; i++) {
        fact[i]=(fact[i-1]*i)%mod;
        //cout<<fact[i]<<" ";
    }
    //cout<<endl;
}
void reset() {
    for(int i=0 ; i<=n ; i++) {
        val[i]=odd[i]=even[i]=0;
        for(int j=0 ; j<=n ; j++) {
            for(int k=0 ; k<11 ; k++) {
                dp_odd[i][j][k]=dp_even[i][j][k]=0;
            }
        }
    }
    cnt_odd=cnt_even=0;
    for(int i=0 ; i<11 ; i++) ways[i]=0;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("gift11.inp","r",stdin);
    freopen("gift11.out","w",stdout);
    init();
    cin>>T;
    while(T--) {
        cin>>n;
        reset();
        cnt_odd=cnt_even=rem_odd=rem_even=0;
        for(int i=1 ; i<=n ; i++) {
            string str;
            cin>>str;
            for(int j=0 ; j<str.length() ; j++) {
                int d=str[j]-'0';
                if(j%2==0) val[i]+=d;
                else val[i]-=d;
            }
            val[i]%=11;
            if(val[i]<0) val[i]+=11;
            if(str.length()%2==0) {
                even[++cnt_even]=val[i];
            }
            else {
                odd[++cnt_odd]=val[i];
            }
        }
        // dp odd
        dp_odd[0][0][0]=1;
        for(int pos=1 ; pos<=cnt_odd ; pos++) {
            for(int add=0 ; add<=pos&&add<=(cnt_odd+1)/2 ; add++) {
                for(int rem=0 ; rem<11 ; rem++) {
                    int n_rem=(rem-odd[pos]);
                    if(n_rem<0) n_rem+=11;
                    if(add>0) {
                        dp_odd[pos][add][rem]+=dp_odd[pos-1][add-1][n_rem];
                        if(dp_odd[pos][add][rem]>=mod) dp_odd[pos][add][rem]-=mod;
                        //cout<<"dp_odd "<<pos<<" "<<add<<" "<<n_rem<<" = "<<dp_odd[pos-1][add-1][rem]<<endl;
                    }
                    n_rem=rem+odd[pos];
                    if(n_rem>=11) n_rem-=11;
                    dp_odd[pos][add][rem]+=dp_odd[pos-1][add][n_rem];
                    if(dp_odd[pos][add][rem]>=mod) dp_odd[pos][add][rem]-=mod;
                    //cout<<"dp_odd "<<pos<<" "<<add<<" "<<n_rem<<" = "<<dp_odd[pos][add][n_rem]<<endl;
                }
            }
        }
        for(int i=0 ; i<11 ; i++) {
            ways[i]=dp_odd[cnt_odd][(cnt_odd+1)/2][i];
            //cout<<ways[i]<<' ';
        }
        //cout<<endl;
        dp_even[0][0][0]=1;
        for(int pos=1 ; pos<=cnt_even ; pos++) {
            for(int add=0 ; add<=pos ; add++) {
                for(int rem=0 ; rem<11 ; rem++) {
                    int n_rem=rem+even[pos];
                    if(n_rem>=11) n_rem-=11;
                    if(add>0) {
                        dp_even[pos][add][n_rem]+=dp_even[pos-1][add-1][rem];
                        if(dp_even[pos][add][n_rem]>mod) dp_even[pos][add][n_rem]-=mod;
                    }
                    n_rem=rem-odd[pos];
                    if(n_rem<0) n_rem+=11;
                    dp_even[pos][add][n_rem]+=dp_even[pos-1][add][rem];
                    if(dp_even[pos][add][n_rem]>mod) dp_even[pos][add][n_rem]-=mod;
                }
            }
        }
        int ans=0;
        for(int add=0 ; add<=cnt_even ; add++) {
            for(int rem=0 ; rem<11 ; rem++) {
                if(dp_even[cnt_even][add][rem]) {
                    int way_odd=ways[(11-rem)%11];
                    int way_even=dp_even[cnt_even][add][rem];
                    int c_add=add+(cnt_odd+1)/2;
                    int c_minus=cnt_even-add+cnt_odd/2;
                    //cout<<"way odd even c add minus "<<way_odd<<" "<<way_even<<" "<<c_add<<" "<<c_minus<<endl;
                    int bonus=(fact[c_add]*fact[c_minus])%mod;
                    bonus=(bonus*way_odd)%mod;
                    bonus=(bonus*way_even)%mod;
                    ans=ans+bonus;
                    if(ans>=mod) ans-=mod;
                }
            }
        }
        cout<<ans<<'\n';
    }
}
/*
4
2
1 1
3
1 31 12
3
12345 67 84
9
1 2 3 4 5 6 7 8 9

*/
