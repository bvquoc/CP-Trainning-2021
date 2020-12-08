#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define pll pair<ll, ll>
#define ppii pair<pii, pii>
#define pli pair<ll, int>
using namespace std;
const int N=1e6+1;
struct query
{
    int t, x, y;
};
vector<query> q;
int n, cnt, it[26], ans[N];
main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("PAINT.inp", "r", stdin);
    freopen("PAINT.out", "w", stdout);
    cin>>n;
    q=vector<query>(n);
    char c, c1;
    for(int i=0; i<q.size(); i++){
        cin>>q[i].t>>c;
        q[i].x=c-'a';
        if(q[i].t==1) cnt++;
        else{
            cin>>c1;
            q[i].y=c1-'a';
        }
    }
    int cur=cnt;
    for(int i=0; i<26; i++) it[i]=i;
    for(int i=q.size()-1; i>=0; i--){
        if(q[i].t==1) ans[cur--]=it[q[i].x];
        else it[q[i].x]=it[q[i].y];
    }
    for(int i=1; i<=cnt; i++) cout<<(char)(ans[i]+'a');
    cout<<'\n';
}
