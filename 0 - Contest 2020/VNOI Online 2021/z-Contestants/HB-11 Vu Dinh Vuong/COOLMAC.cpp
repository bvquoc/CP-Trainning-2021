#include <bits/stdc++.h>
#define pii pair<int,int>
#define vi vector<int>
#define F first
#define S second
#define PB(x) push_back(x)
#define ll long long

using namespace std;

const ll MOD = 1e9 + 7;

int n,m;


int main()
{
    ifstream cin("COOLMAC.inp");
    ofstream cout("COOLMAC.out");
    cin >> n;
    vector<pii> resis(n);
    for (int i = 0 ; i < n ; i++) cin >> resis[i].F >> resis[i].S;

    cin >> m;
    int below = 1e5, high = 1e5;
    for (int i = 0 ; i < m ; i++){
        int tempa;
        cin >> tempa;
        below = min (below,tempa);
    }

    sort(resis.begin(),resis.end());
    below--;
    int kq = 0;
    for (int i = 0 ; below < high && i < n ; kq++){
        int next = 0;
        while (i < n && resis[i].F <= below+1){
            next = max(next,resis[i].S);
            i++;
        }
        if (next == 0){
            cout << -1;
            return 0;
        }
        below = next;
    }

    if (below < high) cout << -1;
     else cout << kq;

    return 0;
}
