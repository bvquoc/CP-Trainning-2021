#include<bits/stdc++.h>
using namespace std;
template<typename T> ostream& operator<<(ostream& os, vector<T> a){os<<"( ";for(T &x:a)os<<x<<" ";os<<")\n";return os;}
template<typename T> ostream& operator<<(ostream& os, set<T> a){os<<"( ";for(T x:a)os<<x<<" ";os<<")\n";return os;}
template<typename T1, typename T2> ostream& operator<<(ostream& os, pair<T1,T2> a){os<<"("<<a.first<<" "<<a.second<<") ";return os;}
template<typename T> ostream& operator<<(ostream& os, complex<T> a){os<<"(r="<<a.real()<<" i="<<a.imag()<<") ";return os;}
typedef long long ll;
typedef double dd;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vi> vvi;
#define all(a) a.begin(),a.end()
#define DEBUG 1
#define debug(a) if(DEBUG)cout<<#a<<" = "<<a<<endl
#define x first
#define y second
//===========================Head=========================//

int main(int argc,char** argv){
    //freopen("BOX2.inp","r",stdin);
    //freopen("BOX2.out","w",stdout);
    int n;
    scanf("%d",&n);
    vector<pair<pii,int>> a(n);
    for (int i=0;i<n;++i){
        scanf("%d%d",&a[i].x.x,&a[i].x.y);
        a[i].y=i+1;
        a[i].x.y *= -1;
    }
    sort(all(a));
    //cout<<a;
    vi pos;
    vvi ans;
    for (int i=0;i<n;++i){
        int d=0, c=pos.size()-1, r=-1;
        while(d<=c){
            int g=(d+c)/2;
            if (a[pos[g]].x.y<=a[i].x.y){
                r=g;
                d=g+1;
            } else c=g-1;
        }
        if (++r == (int)pos.size()){
            pos.push_back(0);
            ans.push_back(vi(0));
        }
        pos[r]=i;
        ans[r].push_back(i);
    }
    printf("%d\n",(int)ans.size());
    for (auto &lst:ans){
        printf("%d ",(int)lst.size());
        reverse(all(lst));
        for (auto i:lst) printf("%d ",a[i].y);
        printf("\n");
    }
}
