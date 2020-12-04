#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
mt19937 gen;
uniform_int_distribution<ll> dis;
ll random(ll L,ll H){if(H<L)return H;return(0LL+dis(gen)+rand())%(H-L+1)+L;}
int testID;
#define subtask subtaskOf(testID)
#define testmax (subtaskOf(testID+1)>subtask)
#define test_th(i) (subtaskOf(testID-i)==subtask && subtaskOf(testID-i-1)<subtask)
///////////////////////////////////////////////main///////////////////////////////////////////
namespace sol{

    #define all(a) a.begin(),a.end()

    pair<long long, vector<int>> solve(vector<long long> a){
        // for(auto x: a) cerr << x << " ";
        vector<int> nxt(a.size()), pre(a.size());
        for (int i = 0; i < a.size(); ++i) nxt[i] = i+1, pre[i] = i-1;
        priority_queue<pair<long long, int>> heap;
        for (int i = 0; i+1 < a.size(); ++i) heap.push({-a[i]-a[nxt[i]], i});
        long long ans = 0;
        vector<int> orders;
        while(heap.size()){
            auto tmp = heap.top();
            heap.pop();
            int i = tmp.second, j = nxt[i];
            if (j >= a.size() || -a[i]-a[j] != tmp.first) continue;
            orders.push_back(i);
            ans -= tmp.first;
            a[j] += a[i];
            pre[j] = pre[i];
            pre[i] = -1;
            if (pre[j] >= 0){
                nxt[pre[j]] = j;
                heap.push({-a[pre[j]]-a[j], pre[j]});
            }
            if (nxt[j] < a.size()){
                heap.push({-a[j]-a[nxt[j]], j});
            }
        }
        // cerr << ans << " xxxx" << endl;
        reverse(all(orders));
        // for(int i : orders) cerr << i << " ";cerr<<endl;
        return make_pair(ans, orders);
    }

    #define u first.first
    #define v first.second
    #define x second.first
    #define y second.second
    typedef pair<int,int> pii;
    typedef pair<pii,pii> Rectangle;
    typedef Rectangle Line;

    pair<long long, vector<int>> solve(int n, int m, vector<Line> lines){
        map<Line, int> lineId;
        map<pii, vector<int>> Xs, Ys;
        for (Line &D : lines){
            lineId[D] = &D - &lines[0];
            if (D.u == D.x) Xs[pii(D.v, D.y)].push_back(D.x);
            else Ys[pii(D.u, D.x)].push_back(D.y);
        }
        for (auto &e : Xs) sort(all(e.second));
        for (auto &e : Ys) sort(all(e.second));
        vector<Rectangle> recs;
        recs.push_back(Rectangle(pii(0,0), pii(n,m)));
        long long ans = 0;
        vector<int> orders;
        while (recs.size()){
            Rectangle R = recs.back();
            recs.pop_back();
            vector<Line> lines;
            {//by X
                auto s = lower_bound(all(Xs[pii(R.v, R.y)]), R.u+1);
                auto t = upper_bound(all(Xs[pii(R.v, R.y)]), R.x-1);
                for ( ; s < t; ++s) lines.push_back(Line(pii(*s, R.v), pii(*s, R.y)));
            }
            {//by Y
                auto s = lower_bound(all(Ys[pii(R.u, R.x)]), R.v+1);
                auto t = upper_bound(all(Ys[pii(R.u, R.x)]), R.y-1);
                for ( ; s < t; ++s) lines.push_back(Line(pii(R.u, *s), pii(R.x, *s)));
            }
            sort(all(lines));
            //cerr << R.u << " " << R.v << " " << R.x << " " << R.y << ":" << endl;
            //for (auto line : lines) cerr << line.u << " " << line.v << " " << line.x << " " << line.y << endl;
            vector<long long> a;
            if (lines.size()){//insert rectangles
                #define area(R) (1LL*(R.x-R.u)*(R.y-R.v))
                pii P = R.first;
                for (auto &D : lines){
                    recs.push_back({P, D.second});
                    a.push_back(area(recs.back()));
                    P = D.first;
                }
                assert(P != R.first);
                recs.push_back({P, R.second});
                a.push_back(area(recs.back()));
            }
            auto tmp = solve(a);
            ans += tmp.first;
            for (int i : tmp.second) orders.push_back(lineId[lines[i]]);
        }
        return make_pair(ans, orders);
    }

}

const ll nmax[]={100000, 100000, 100000, 100000, 100000};
const ll nmin[]={100000, 100000, 100000, 100000, 100000};
vector<int> ntest = {4, 4, 4, 4, 4};// % number of test of each subtask

int subtaskOf(int n){if(n<0)return-1;for(int i=0;i<ntest.size();++i)if((n-=ntest[i])<0)return i;return ntest.size();}

#define all(a) a.begin(),a.end()
#define u first.first
#define v first.second
#define x second.first
#define y second.second
typedef pair<int,int> pii;
typedef pair<pii,pii> Rectangle;
typedef Rectangle Line;

void test0_99(int num){
    int n = random(100000, 1000000);
    int m = random(100000, 1000000);
    int k = random(50000, 100000);
    if (testID % 3 == 0) n = random(5e8, 1e9), m = random(2, 5);
    if (subtask == 1) n = 1;
    if (subtask == 0) k = random(6, 8);
    vector<Line> lines;
    vector<Rectangle> recs;
    recs.push_back(Rectangle(pii(0,0), pii(n, m)));
    #define area(R) (1LL*(R.x-R.u)*(R.y-R.v))
    while(k--){
        if (recs.empty()) break;
        int i = random(0, (int)recs.size()-1);
        swap(recs[i], recs.back());
        Rectangle R = recs.back();
        recs.pop_back();
        if (area(R) <= 1){
            ++k;
            continue;
        }
        if (R.u+1 == R.x || (R.v+1<R.y && random(0, 1))){
            int yc = random(R.v+1, R.y-1);
            Line D(pii(R.u, yc), pii(R.x, yc));
            lines.push_back(D);
            recs.push_back(Rectangle(R.first, D.second));
            recs.push_back(Rectangle(D.first, R.second));
        } else {
            int xc = random(R.u+1, R.x-1);
            Line D(pii(xc, R.v), pii(xc, R.y));
            lines.push_back(D);
            recs.push_back(Rectangle(R.first, D.second));
            recs.push_back(Rectangle(D.first, R.second));            
        }
    }
    auto tmp = sol::solve(n, m, lines);
    assert(tmp.first >= 0 && tmp.first <= 1e18);
    if (subtask != 3 && subtask != 2) random_shuffle(all(lines));
    if (subtask == 2){
        auto l = lines;
        lines.clear();
        for (int i : tmp.second) lines.push_back(l[i]);
    }
    cerr << n << ' ' << m << ' ' << lines.size() << ": " << tmp.first << '\n';
    cout << n << ' ' << m << ' ' << lines.size() << '\n';
    for (auto &line : lines) cout << line.u << ' '  << line.v << ' ' << line.x << ' ' << line.y << '\n';
}

/////////////////////////////////////////////end////////////////////////////////////////////////
int main(int argc,char** argv){
    testID = 0;

    if (argc > 2){
        testID = atoi(argv[1]);
        freopen(argv[2],"w",stdout);
    } else {
        char* s = argv[0];
        int n=strlen(s), i=n-1;
        while(i&&s[i-1]!='_') --i;
        while(s[n-1]!='.') s[--n]=0;
        sprintf(s+n,"inp");freopen(s+i,"w",stdout);
        sprintf(s+n,"test");freopen(s+i,"r",stdin);
        cin>>testID;
    }
    if (subtask >= ntest.size()){
        return 125;
    }

    int k = testID;
    if (argc>3) k += atoi(argv[3]);
    while(k--) 0LL+dis(gen)+rand();
    test0_99(testID);
}
