#include <bits/stdc++.h>
#define ii pair<int, int>
#define iii pair<int, ii>
using namespace std;

const int maxT = 1e5;

long long ktra[maxT + 2], dau[maxT + 2];
long long t, n, res = 0;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("COOLMAC.inp", "r", stdin);
    freopen("COOLMAC.ans", "w", stdout);
    int mn = maxT;
    cin >> n;
    vector<iii> a(2 * n);
    for(int i = 0; i < n; i ++)
    {
        int u, v;
        cin >> u >> v;
        dau[i] = u;
        a[i * 2] = {u, {0, i}};
        a[i * 2 + 1] = {v,{ 1, i}};
    }
    sort(a.begin(), a.end());
    cin >> t;
    while(t--)
    {
        int x;
        cin >> x;
        mn = min(mn, x);
    }
    dau[100001] = 100000;
    deque<int> qu;
    memset(ktra, 0, sizeof(ktra));
    for(int i = 0; i < 2 * n; i++)
    {
        int u = a[i].first;
        int dc = a[i].second.first;
        int j = a[i].second.second;
        if(!qu.empty() && qu.front() == 100001) qu.pop_front();
        if(!dc) qu.push_back(j);
        else{

            while(!qu.empty() && ktra[qu.front()]) qu.pop_front();

            if(j == qu.front()){
                qu.pop_front();
                while(!qu.empty() && ktra[qu.front()]) qu.pop_front();
                if(qu.empty()) qu.push_back(100001);
                if(dau[j] <= mn && dau[qu.front()] > mn){
                    res++;
                    mn = u;
                    ktra[j] = 1;
                }
                while(!qu.empty() && ktra[qu.front()]) qu.pop_front();
            }
            else{
                ktra[j] = 1;
            }
        }
    }
    if(mn != maxT) cout<<"-1";
    else cout<<res;
}
