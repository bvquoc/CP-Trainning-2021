//TaiEm(Nguyen Duc Huy) IT_18-21 
//#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <deque>
#include <bitset>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> i3;

#define taskname "DHAKA"
#define FOR(i,j,n) for(int i=j; i<=n; i++)
#define FOD(i,j,n) for(int i=j; i>=n; i--)
#define fi first
#define se second
#define REP(i,j,n) for(int i=j; i<n; i++)
#define LL long long
#define LD long double

const int maxN=1234567;
const LL oo=1e18+11;

struct ds {
	int mot,hai;
};

bool xet(const ds x , const ds y) {
	return x.mot<y.mot;
}

//////////////////////////////////////////////

int n;

//////////////////////////////////////////////

void enter(){
    cout << -1;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen(taskname".INP","r",stdin);
    freopen(taskname".OUT","w",stdout);
    #else
        // online submission
    #endif
    // main program here
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    enter();
    return 0;
}