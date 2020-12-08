#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define taskname "MOTION"

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld,ld> ii;

const int maxn = 1e5 + 5;
#define x first
#define y second

int t;
ii a , b , c , d;
int n , m;
ld dis(ii a , ii b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
bool conner(ii a){
    return (a.x == 0 || a.x == m) && (a.y == 0 || a.y == n);
}
vector<pair<ld,ii>> val;
vector<pair<ld,ii>> path1 , path2;
ii Mul(ii x , ld k){
    return mp(x.x * k , x.y * k);
}
ii Plus(ii x , ii y){
    return mp(x.x + y.x , x.y + y.y);
}
ii Minus(ii x , ii y){
    return mp(x.x - y.x , x.y - y.y);
}
void Try(vector<pair<ld,ii>> & path){
    ld speed = 1.0 / dis(path[0].second,path[1].second);
//    cout << " " << speed << endl;
    for(int i = 0 ; i <= 1000 ; ++i){
        auto u = path[i].second;
        auto v = path[i + 1].second;
        if(conner(v)){
            path.pb(mp(0,u));
        }
        else{
            auto res = u;
            if(v.x == 0 || v.x == m){
                res = mp(u.x,v.y + (v.y - u.y));
            }else{
                res = mp(v.x + (v.x - u.x) , u.y);
            }
            if(res.x < 0){
                res = Plus(v , Mul(Minus(res , v) ,  (0 - v.x) / (res.x - v.x)));
            }else if(res.y < 0){
                res = Plus(v , Mul(Minus(res , v) ,  (0 - v.y) / (res.y - v.y)));
            }else if(res.x > m){
                res = Plus(v , Mul(Minus(res , v) ,  (m - v.x) / (res.x - v.x)));
            }else if(res.y > n){
                res = Plus(v , Mul(Minus(res , v) ,  (n - v.y) / (res.y - v.y)));
            }
            path.pb(mp(0,res));
        }
//        cout << path.back().second.first << " " << path.back().second.second << endl;
        path.back().first = path[i + 1].first + dis(v , path.back().second) * speed;
    }
}
void Solve(){
    val.clear();path1.clear();path2.clear();
    cin >> m >> n;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
    for(int i = 1 ; i <= m * n ; ++i){
        for(int j = 1 ; j <= n + m ; ++j){
            if(__gcd(i,j) == 1){
                val.pb(mp((ld)i / j , mp(i,j)));
            }
        }
    }
    sort(val.begin(),val.end());
    path1.pb(mp(0 , a));path1.pb(mp(1 , b));Try(path1);
    path2.pb(mp(0 , c));path2.pb(mp(1 , d));Try(path2);
//    for(auto c : path1)cout << c.first << endl;
    auto speed1 = 1 / dis(a,b);
    auto speed2 = 1 / dis(c,d);
    for(auto c : val){
        auto it1 = lower_bound(path1.begin(),path1.end(),mp(c.first,mp((ld)0,ld(0)))) - path1.begin()-1;
        auto it2 = lower_bound(path2.begin(),path2.end(),mp(c.first,mp((ld)0,ld(0)))) - path2.begin()-1;
        if(it1 + 1 < path1.size() && it2 + 1 < path2.size()){
            auto u = path1[it1];
            auto v = path2[it2];
            auto pos1 = Plus(u.second,Mul(Minus(path1[it1 + 1].second,path1[it1].second),(c.first-u.first)*speed1));
            auto pos2 = Plus(v.second,Mul(Minus(path2[it2 + 1].second,path2[it2].second),(c.first-v.first)*speed2));
//            cout << (c.first - v.first) << endl;
            if(c.first - v.first == 0.5){
//                cout << pos1.first << " " << pos1.second << endl;
//                cout << pos2.first << " " << pos2.second << endl;
            }
            if(abs(pos1.first - pos2.first) <= 1e-4 && abs(pos1.second - pos2.second) <= 1e-4){
                cout << c.second.first << " " << c.second.second << '\n';
                return;
            }
        }
    }
    cout << -1 << '\n';
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(taskname".INP","r")){
		freopen(taskname".INP", "r",stdin);
		freopen(taskname".OUT", "w",stdout);
    }
    int t;cin >> t;
    while(t--)Solve();
}

