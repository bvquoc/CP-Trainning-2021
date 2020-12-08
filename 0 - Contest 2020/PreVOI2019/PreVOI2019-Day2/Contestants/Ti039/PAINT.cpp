#include <bits/stdc++.h>
using namespace std;
#define tag "PAINT"
#define maxn 1000007
#define oo 1000000007LL
#define mid ((l+r)>>1)
#define meset(a,x) memset(a,x,sizeof(a))
#define loop(x) for(int LoOpEr=1;LoOpEr<=x;LoOpEr++)
#define debug(x) cerr<<#x<<" = "<<x<<"\n"
#define runtime(stime) ((clock() - stime) / CLOCKS_PER_SEC * 1000)
#define checkfile(FiLeNaMe) { if(fopen(FiLeNaMe".inp","r")) freopen(FiLeNaMe".inp","r",stdin),freopen(FiLeNaMe".out","w",stdout); }
//// my data:
///>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
int n;

void brute(){
    vector<int> a;

    char x,y;
    for(int ques=0,type;ques<=n;ques++){
        cin>>type;
        if(type==1){
            cin>>x;
            a.push_back(x-'a');
        }else{
            cin>>x>>y;
            for(int &val: a){
                if(val==x-'a') val=y-'a';
            }
        }
    }

    for(int val: a) cout<<char(val+'a');
}

void subdm(){

}

void enter(){
    cin>>n;
    if(n<=1e4) brute();
    else subdm();
}
int main()
{
    checkfile(tag);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    enter();

    return 0;
}
