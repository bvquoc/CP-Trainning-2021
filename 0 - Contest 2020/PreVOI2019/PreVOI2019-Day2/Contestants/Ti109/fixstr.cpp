#include<bits/stdc++.h>
#define fr(i,x,y) for(int i=x;i<=y;i++)
#define ft(i,x,y) for(int i=y;i>=x;i--)
#define ll long long
#define add push_back
#define ad push
#define fi first
#define se second
#define fast_read ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef struct pair<ll,ll> ii;
int n,m,x,a,b,res,st,dd[1001][1001];
string s1,tv;
int s[1000010];
vector<int> nx;
void io(){
    fast_read
    freopen("fixstr.inp" , "r" , stdin);
    freopen("fixstr.out" , "w" , stdout);
}
void inp(){
    cin>>s1;
    n=s1.size();
    fr(i,1,n){
        if(s1[i-1]=='(') s[i]=1;
        else s[i]=-1;
    }
    cin>>m;
}
void sub(){
    fr(k,1,m){
        cin>>tv;
        res=0;
        if(tv=="C"){
            fr(i,1,n) dd[k][i]=s[i];
            cin>>x;
            if(s[x]==1) s[x]=-1;
            else s[x]=1;
        }
        if(tv=="Q"){
            cin>>a>>b;
            st=a;
            nx.clear();
            fr(i,1,n) dd[k][i]=s[i];
            fr(i,a,b){
                if(s[i]==1) nx.add(s[i]);
                else{
                    if(nx.empty()) {
                        res++;
                        continue;
                    }
                    if(nx.back()+s[i]==0) nx.pop_back();
                }
            }
            res+=nx.size();
            cout<<res<<"\n";
        }
        if(tv=="U"){
            cin>>a;
            fr(i,1,n) dd[k][i]=s[i];
            fr(i,1,n) s[i]=dd[a][i];
        }
    }
}
int main (){
    io();
    inp();
    sub();
    return 0;
}

