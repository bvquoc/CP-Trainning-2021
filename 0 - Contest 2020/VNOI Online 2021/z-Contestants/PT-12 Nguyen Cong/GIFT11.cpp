#include <bits/stdc++.h>
using namespace std;

int Test;
int n;
int A[2020];
const int MOD = 998244353;
void Sum (int &a, const int &b) {
    a += b;
    if(a >= MOD) a -= MOD;
    return;
}
namespace SUBTRAU {
    int memo[10][300][11] ;

    int Ans = 0;
    vector <int> shv;
    void Process (void) {
        shv.clear();
        Ans = 0;
        for(int i = 1; i <= n; i ++) {
            shv.push_back(i);

        }

        do {
            int ok = 1;
            int odd = 0;
            int even = 0;

            for(int i = 0; i < n; i ++) {
                int a = A[shv[i]];
                int Sl = 0;
                while(a) {
                    Sl ++;
                    a /= 10;
                }
                a = A[shv[i]];
                int oldok = ok;
                if(Sl & 1) {
                    while(a) {
                        if(ok == 1) even += (a % 10);
                        else odd += (a % 10);
                        ok = 1 - ok;
                        a /= 10;
                    }
                    ok = 1 - oldok;
                } else {
                    ok = 1 - ok;
                    while(a) {
                        if(ok == 1) even += (a % 10);
                        else odd += (a % 10);
                        ok = 1 - ok;
                        a /= 10;
                    }
                    ok = oldok;
                }
            }
//            cout << odd << " " << even << endl;
            if(abs(odd - even) % 11 == 0) {
//                for(int i = 0; i < n; i ++) {
//                    cout << A[shv[i]];
//                }
//                cout << endl;
                Sum(Ans, 1);
            }
        } while(next_permutation(shv.begin(), shv.end()));

        cout << Ans << '\n';
    }
}

namespace SUBFULL {
    #define ii pair <int, int>
    #define fi first
    #define se second
    int cntOdd, cntEven;
    int memo[2020][2020][12];
    ii ODD[2020];
    ii EVEN[2020];
    int SUM;
    int Num;
    int solve(int odd, int even, int remOdd) {
        if(odd + even == cntEven + cntOdd)
        {
            return (abs(remOdd - (SUM - remOdd)) % 11 == 0);
        }
        if(memo[odd][even][remOdd] != -1) return memo[odd][even][remOdd];
        int Cur = 0;
        if(odd < cntOdd) {
            if(odd & 1) {
                Sum(Cur , 1LL * solve(odd + 1, even, (remOdd + ODD[odd+1].fi) % 11) * (cntOdd - odd) % MOD);
            } else {
                Sum(Cur, 1LL * solve(odd + 1, even, (remOdd + ODD[odd+1].se) % 11) * (cntOdd - odd) % MOD);
            }
        }
        if(even < cntEven) {
            if(odd & 1) {
                Sum(Cur, 1LL * solve(odd, even + 1, (remOdd + EVEN[even+1].se) % 11) * (cntEven - even) % MOD);
            } else {
                Sum(Cur, 1LL * solve(odd, even + 1, (remOdd + EVEN[even+1].fi) % 11) * (cntEven - even) % MOD);
            }
        }
        return memo[odd][even][remOdd] = Cur % MOD;
    }
    void Process( void) {
        cntOdd = 0;
        cntEven = 0;
        SUM = 0;
        for(int i = 1; i <= n; i ++) {
            int a = A[i];
            int sl = 0;
            int rem = 0;
            int sum = 0;
            while(a) {
                sum += (a % 10);
                if(sl & 1) rem += (a % 10);
                sl ++;
                a /= 10;
            }
            SUM += sum;
            if(sl & 1) {
                ODD[++cntOdd] = {sum - rem, rem};
            } else {
                EVEN[++cntEven] = {sum - rem, rem};
            }
        }
        SUM %= 11;
        memset(memo, -1, sizeof memo);
//        cout << cntOdd << " _ " << endl;
//        cout << cntEven << endl;
        cout << solve(0,0,0) % MOD << endl;
    }
}

main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("GIFT11.inp", "r", stdin);
    freopen("GIFT11.out", "w", stdout);

    cin >> Test;
    while(Test --) {
        cin >> n;
        for(int i = 1; i <= n; i ++) {
            cin >> A[i];
        }
        if(n <= 10) SUBTRAU::Process();
        else
            SUBFULL::Process();
    }
}
