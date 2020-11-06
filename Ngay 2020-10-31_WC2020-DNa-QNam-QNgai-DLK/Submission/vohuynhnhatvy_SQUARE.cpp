#include<bits/stdc++.h>


using namespace std;
const long long M=1e18;
long long k;
vector<long long> s;
int main()
{
    // freopen("test.txt", "r", stdin);
    // freopen("test.out", "w", stdout);
    cin >> k;
    long long sqrtk = sqrt(k);
    if (k>=0 && sqrtk*sqrtk == k){
        cout << sqrtk;
        return 0;
    }
//     if (k > 0 && k%2==0)
//     {
//         cout<<"none";
//         return 0;
//     }
    for (long long i = 1 ; i*i <= abs(k); i++){
        if (k % i == 0){
            s.push_back(i);
            s.push_back(-i);
            if (i*i != abs(k)){
                s.push_back(k/i);
                s.push_back(-k/i);
            }
        }
    }

    long long ans = M;
    for (int i = 0; i < s.size(); i++){
        long long j=k/s[i];
        long long maxnum=-M;
        if ((s[i]+j)%2==0) maxnum=(s[i]+j)/2;
        if (maxnum<0) maxnum=-M;
        ans=min(ans,abs(maxnum));
    }
    if (ans != M) cout<<ans;
    else cout<<"none";
}
